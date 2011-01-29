#include "qbluetooth.hpp"
#include "ui_qbluetooth.h"


QBluetooth::QBluetooth(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QBluetooth) {
    ui->setupUi(this);
	qDebug() << "qbluetooth: Hello";
	ui->statusbar->showMessage("Ready");

	ui->toolBarDevice->addWidget(ui->toolButtonScan);
	ui->toolBarDevice->addWidget(ui->toolButtonConnect);
	ui->toolBarDevice->addWidget(ui->toolButtonDisconnect);
	ui->toolBarDisplay->addWidget(ui->toolButtonSend);
	ui->toolBarDisplay->addWidget(ui->toolButtonClear);
}

QBluetooth::~QBluetooth() {
	qDebug() << "qbluetooth: Bye";
    delete ui;
}

/*
  * Device tab buttons
  */
void QBluetooth::on_toolButtonScan_clicked() {
	qDebug() << "qbluetooth: Scan clicked";
	ui->listWidget->clear();
	ui->statusbar->showMessage("Scanning");
	int found = serial.inquiry();
	for(int i = 0; i < found; i++) {
		bdaddr_t temp = serial.getRemoteAddress(i);
		ui->listWidget->addItem(QString::fromStdString(serial.getRemoteName(temp)));
	}
	ui->statusbar->showMessage("Ready");
}

void QBluetooth::on_toolButtonConnect_clicked() {
	qDebug() << "qbluetooth: Connect clicked";
	ui->statusbar->showMessage("Connecting");
	if(ui->listWidget->selectedItems().count() != 0)
		serial.connecting(ui->listWidget->row(ui->listWidget->selectedItems()[0]), 1);
	else {
		qDebug() << "qbluetooth: Choose a remote device from list";
		return;
	}
	if((serial.getStatus()) < 0)
		ui->statusbar->showMessage("Disconnected");
	else {
		ui->statusbar->showMessage("Connected");
	}
}

void QBluetooth::on_toolButtonDisconnect_clicked() {
	qDebug() << "qbluetooth: Disconnect clicked";
	ui->statusbar->showMessage("Disconnected");
	serial.disconnecting();
}

/*
  * Display tab buttons
  */
void QBluetooth::on_toolButtonSend_clicked() {
	qDebug() << "qbluetooth: Send clicked";
	uint8_t pixels[128][64] = {{'\x00'}};
	QList<QTableWidgetItem *> selection = ui->tableWidget->selectedItems();
	qDebug() << "Items selected " << selection.count();
	foreach(QTableWidgetItem *selected, selection)
		pixels[selected->column()][selected->row()] = '\x01';

	/* Send row by row (horizontal) in bytes.
	for(unsigned short i = 0; i < 64; i++) {
		for(unsigned short j = 0; j < 128; j+=8) {
			serial.send((pixels[j][i] << 7)
			            | (pixels[j+1][i] << 6)
			            | (pixels[j+2][i] << 5)
			            | (pixels[j+3][i] << 4)
			            | (pixels[j+4][i] << 3)
			            | (pixels[j+5][i] << 2)
			            | (pixels[j+6][i] << 1)
			            | pixels[j+7][i]);
			qDebug() << ((pixels[j][i] << 7)
			            | (pixels[j+1][i] << 6)
			            | (pixels[j+2][i] << 5)
			            | (pixels[j+3][i] << 4)
			            | (pixels[j+4][i] << 3)
			            | (pixels[j+5][i] << 2)
			            | (pixels[j+6][i] << 1)
			            | pixels[j+7][i]);
		}
	}*/

	/* Send page by page height (vertical) in bytes. */
	for(unsigned short i = 0; i < 64; i+=8) {
		for(unsigned short j = 0; j < 128; j++) {
			serial.send(pixels[j][i]
			            | (pixels[j][i+1] << 1)
			            | (pixels[j][i+2] << 2)
			            | (pixels[j][i+3] << 3)
			            | (pixels[j][i+4] << 4)
			            | (pixels[j][i+5] << 5)
			            | (pixels[j][i+6] << 6)
			            | (pixels[j][i+7] << 7));
			qDebug() << ((pixels[j][i] << 7)
			            | (pixels[j][i+1] << 6)
			            | (pixels[j][i+2] << 5)
			            | (pixels[j][i+3] << 4)
			            | (pixels[j][i+4] << 3)
			            | (pixels[j][i+5] << 2)
			            | (pixels[j][i+6] << 1)
			            | pixels[j][i+7]);
		}
	}
}

void QBluetooth::on_toolButtonClear_clicked() {
	qDebug() << "qbluetooth: Clear clicked";
	/*
	  * Functionality implemented by QTableWidget slot clear()
	  */
}

/*
  * Device tab lists
  */
void QBluetooth::on_listWidget_itemClicked() {
	qDebug() << "qbluetooth: List item clicked";
}

/*
  * Display tab table
  */
void QBluetooth::on_tableWidget_cellActivated(int row, int column) {
	qDebug() << "qbluetooth: Cell " << column << "x" << row << " activated";
}

void QBluetooth::on_tableWidget_cellChanged(int row, int column) {
	qDebug() << "qbluetooth: Cell " << column << "x" << row << " changed";
}

void QBluetooth::on_tableWidget_cellClicked(int row, int column) {
	qDebug() << "qbluetooth: Cell " << column << "x" << row << " clicked";
	QTableWidgetItem *item = new QTableWidgetItem();
	item->setSelected(true);
	ui->tableWidget->setItem(row, column, item);
}

void QBluetooth::on_tableWidget_cellDoubleClicked(int row, int column) {
	qDebug() << "qbluetooth: Cell " << column << "x" << row << " double clicked";
}

void QBluetooth::on_tableWidget_cellEntered(int row, int column) {
	qDebug() << "qbluetooth: Cell " << column << "x" << row << " entered";
	QTableWidgetItem *item = new QTableWidgetItem();
	item->setSelected(true);
	ui->tableWidget->setItem(row, column, item);
}

void QBluetooth::on_tableWidget_cellPressed(int row, int column) {
	qDebug() << "qbluetooth: Cell " << column << "x" << row << " pressed";
	QTableWidgetItem *item = new QTableWidgetItem();
	item->setSelected(true);
	ui->tableWidget->setItem(row, column, item);
}
