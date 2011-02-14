/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2011	Alexander Meinke <ameinke at online dot de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include "qbluetooth.hpp"
#include "ui_qbluetooth.h"


QBluetooth::QBluetooth(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QBluetooth),
	display(new BluetoothDisplayTable),
	channel(new BluetoothRFComm) {
    ui->setupUi(this);
	ui->gridLayout_2->addWidget(display);
	qDebug() << "QBluetooth: Hello";
	ui->statusbar->showMessage("Ready");

	ui->toolBarDevice->addWidget(ui->toolButtonScan);
	ui->toolBarDevice->addWidget(ui->toolButtonConnect);
	ui->toolBarDevice->addWidget(ui->toolButtonDisconnect);
	ui->toolBarDisplay->addWidget(ui->toolButtonSend);
	ui->toolBarDisplay->addWidget(ui->toolButtonClear);
	ui->toolBarEdit->addWidget(ui->toolButtonRectangle);
}

QBluetooth::~QBluetooth() {
	qDebug() << "QBluetooth: Bye";
	delete channel;
	delete display;
	delete ui;
}

/*
  * Context menu actions
  */
void QBluetooth::on_actionOpen_triggered() {
	qDebug() << "QBluetooth: Open action triggered";
	QString file = QFileDialog::getOpenFileName(this, "Open Display File",
												QDir::homePath());
	display->openImage(file);
}

void QBluetooth::on_actionSave_triggered() {
	qDebug() << "QBluetooth: Save action triggered";
	QString file = QFileDialog::getSaveFileName(this, "Save Display File",
												QDir::homePath());
	display->saveImage(file);
}

/*
  * Device tab buttons
  */
void QBluetooth::on_toolButtonScan_clicked() {
	qDebug() << "QBluetooth: Scan clicked";
	ui->listWidget->clear();
	ui->statusbar->showMessage("Scanning");
	channel->inquiry();
	ui->listWidget->addItems(channel->getRemoteNames());
	ui->statusbar->showMessage("Ready");
}

/*
  * Display tab buttons
  */
void QBluetooth::on_toolButtonSend_clicked() {
	qDebug() << "QBluetooth: Send clicked";
	for(qint16 y = 0; y < 64; y+=8)
		for(qint16 x = 0; x < 128; x++) {
			quint8 toSend = ((display->pixel(x, y)^QColor(Qt::black).rgb())&0x00000001
			                 | ((display->pixel(x, y+1)^QColor(Qt::black).rgb())&0x00000001) << 1
							 | ((display->pixel(x, y+2)^QColor(Qt::black).rgb())&0x00000001) << 2
							 | ((display->pixel(x, y+3)^QColor(Qt::black).rgb())&0x00000001) << 3
					         | ((display->pixel(x, y+4)^QColor(Qt::black).rgb())&0x00000001) << 4
					         | ((display->pixel(x, y+5)^QColor(Qt::black).rgb())&0x00000001) << 5
					         | ((display->pixel(x, y+6)^QColor(Qt::black).rgb())&0x00000001) << 6
					         | ((display->pixel(x, y+7)^QColor(Qt::black).rgb())&0x00000001) << 7);
			channel->send(&toSend, 1);
			qDebug() << "QBluetooth:" << x << "x" << y << ":"
			         << (((display->pixel(x, y)^QColor(Qt::black).rgb())&0x00000001) << 7
			             | ((display->pixel(x, y+1)^QColor(Qt::black).rgb())&0x00000001) << 6
		                 | ((display->pixel(x, y+2)^QColor(Qt::black).rgb())&0x00000001) << 5
		                 | ((display->pixel(x, y+3)^QColor(Qt::black).rgb())&0x00000001) << 4
		                 | ((display->pixel(x, y+4)^QColor(Qt::black).rgb())&0x00000001) << 3
		                 | ((display->pixel(x, y+5)^QColor(Qt::black).rgb())&0x00000001) << 2
		                 | ((display->pixel(x, y+6)^QColor(Qt::black).rgb())&0x00000001) << 1
		                 | (display->pixel(x, y+7)^QColor(Qt::black).rgb())&0x00000001);
		}
}

void QBluetooth::on_toolButtonClear_clicked() {
	qDebug() << "QBluetooth: Clear clicked";
	display->fill(0);
	display->clear();
}

void QBluetooth::on_toolButtonRectangle_clicked() {
	qDebug() << "QBluetooth: Rectangle clicked";
	display->addRect(QPoint(0, 0), QSize(20, 10));
}


/*
  * Device tab lists
  */


void QBluetooth::on_listWidget_itemDoubleClicked() {
	qDebug() << "QBluetooth: List item double clicked";
	/*
	 * Connecting to remote device could be called here.
	 */
	ui->statusbar->showMessage("Connecting");
	channel->connecting(ui->listWidget->selectedItems()[0]->text(), 1);
	if(channel->getStatus() == true)
		ui->statusbar->showMessage("Connected");
	else
		ui->statusbar->showMessage("Disconnected");
}
