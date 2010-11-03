#include "qbluetooth.hpp"
#include "ui_qbluetooth.h"


QBluetooth::QBluetooth(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QBluetooth) {
    ui->setupUi(this);
	qDebug() << "qbluetooth: Hello";
	ui->statusbar->showMessage("Ready");

	qgs.addRect(0, 0, 128, 64);
	qgs.addText("QBluetooth");
	ui->graphicsView->setScene(&qgs);

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
}

/*
  * Display tab graphics view
  */
void QBluetooth::on_verticalSliderZoom_valueChanged(int val) {
	ui->graphicsView->scale(val, val);
}
