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
	serial.connecting(ui->listWidget->row(ui->listWidget->selectedItems()[0]), 1);
	if((serial.getStatus()) < 0)
		ui->statusbar->showMessage("Disconnected");
	else {
		ui->statusbar->showMessage("Connected");
		ui->Display->setEnabled(true);
		ui->toolButtonSend->setEnabled(true);
		ui->toolButtonClear->setEnabled(true);
	}
}

/*
  * Display tab buttons
  */
void QBluetooth::on_toolButtonSend_clicked() {
	qDebug() << "qbluetooth: Send clicked";
	serial.send("qbluetooth: Send button clicked\n");

	QString data(128*64, '0');
	QList<QTableWidgetItem *> selected = ui->tableWidget->selectedItems();
	qDebug() << "Items selected " << selected.count();
	foreach(QTableWidgetItem *selection, selected) {
		data.replace((selection->column()+1) * (selection->row()+1), 1, QChar('1'));
	}
	serial.send(data.toStdString());
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
	ui->toolButtonConnect->setEnabled(true);
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
