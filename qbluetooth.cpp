#include "qbluetooth.hpp"
#include "ui_qbluetooth.h"


QBluetooth::QBluetooth(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QBluetooth) {
    ui->setupUi(this);

	qDebug() << "qbluetooth: hello";
}

QBluetooth::~QBluetooth() {
	qDebug() << "qbluetooth: bye";
    delete ui;
}
