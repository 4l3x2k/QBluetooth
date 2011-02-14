#include "rectdialog.hpp"

RectDialog::RectDialog(QWidget *parent) :
    QDialog(parent) {
	spinBoxX = new QSpinBox(this);
}
