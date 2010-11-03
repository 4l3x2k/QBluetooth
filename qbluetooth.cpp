#include "qbluetooth.hpp"
#include "ui_qbluetooth.h"


QBluetooth::QBluetooth(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QBluetooth) {
    ui->setupUi(this);
	qDebug() << "qbluetooth: Hello";
	ui->statusbar->showMessage("Ready");
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
	ui->statusbar->showMessage("Scanning");
	bluetooth.scan();
	ui->statusbar->showMessage("Ready");
	for(std::map<std::string, std::string>::iterator it = bluetooth.Devices.begin();
	    it != bluetooth.Devices.end();
	    it++)
		ui->listWidget->addItem(it->second.c_str());
}

void QBluetooth::on_toolButtonConnect_clicked() {
	qDebug() << "qbluetooth: Connect clicked";
}

/*
  * Display tab buttons
  */
void QBluetooth::on_toolButtonSend_clicked() {
	qDebug() << "qbluetooth: Send clicked";
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
void QBluetooth::on_listWidget_itemClicked(QListWidgetItem *item) {
	qDebug() << "qbluetooth: List item clicked";
	for(std::map<std::string, std::string>::iterator it = bluetooth.Devices.begin();
	    it != bluetooth.Devices.end();
	    it++) {
		if((QString)it->second.c_str() == item->text())
			qDebug() << "qbluetooth: Name: " << item->text()
					 <<	" Adresse: " << (QString)it->first.c_str();
	}
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
}

void QBluetooth::on_tableWidget_cellDoubleClicked(int row, int column) {
	qDebug() << "qbluetooth: Cell " << column << "x" << row << " double clicked";
}

void QBluetooth::on_tableWidget_cellEntered(int row, int column) {
	qDebug() << "qbluetooth: Cell " << column << "x" << row << " entered";
	on_tableWidget_cellPressed(row, column);
}

void QBluetooth::on_tableWidget_cellPressed(int row, int column) {
	qDebug() << "qbluetooth: Cell " << column << "x" << row << " pressed";
	QTableWidgetItem *item = new QTableWidgetItem();
	item->setSelected(true);
	ui->tableWidget->setItem(row, column, item);
}
