#include "qbluetooth.hpp"
#include "ui_qbluetooth.h"


QBluetooth::QBluetooth(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QBluetooth) {
    ui->setupUi(this);
	qDebug() << "qbluetooth: Hello";
}

QBluetooth::~QBluetooth() {
	qDebug() << "qbluetooth: Bye";
    delete ui;
}

void QBluetooth::on_toolButtonClear_clicked(bool checked) {
	qDebug() << "qbluetooth: Clear clicked";
}

void QBluetooth::on_toolButtonConnect_clicked(bool checked) {
	qDebug() << "qbluetooth: Connect clicked";
}

void QBluetooth::on_toolButtonScan_clicked(bool checked) {
	qDebug() << "qbluetooth: Scan clicked";
}

void QBluetooth::on_toolButtonSend_clicked(bool checked) {
	qDebug() << "qbluetooth: Send clicked";
}

void QBluetooth::on_listWidget_itemClicked(QListWidgetItem *item) {
	qDebug() << "qbluetooth: List item clicked";
}
