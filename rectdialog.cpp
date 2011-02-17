#include "rectdialog.hpp"

RectDialog::RectDialog(QWidget *parent) :
    QDialog(parent),
    layoutRect(new QFormLayout(this)),
    hboxLayoutRect(new QHBoxLayout(this)),
    pushButtonAccept(new QPushButton(this)),
    pushButtonReject(new QPushButton(this)),
	spinBoxX(new QSpinBox(this)),
	spinBoxY(new QSpinBox(this)),
	spinBoxW(new QSpinBox(this)),
	spinBoxH(new QSpinBox(this)) {
	qDebug() << "RectDialog: Hello";

	spinBoxX->setRange(0, 127);
	spinBoxY->setRange(0, 63);
	spinBoxW->setRange(0, 127);
	spinBoxH->setRange(0, 63);

	pushButtonAccept->setText("Annehmen");
	pushButtonReject->setText("Abbrechen");
	hboxLayoutRect->addWidget(pushButtonAccept);
	hboxLayoutRect->addWidget(pushButtonReject);

	layoutRect->addRow("X position:", spinBoxX);
	layoutRect->addRow("Y position:", spinBoxY);
	layoutRect->addRow("width:", spinBoxW);
	layoutRect->addRow("height:", spinBoxH);
	layoutRect->addRow(hboxLayoutRect);
	setLayout(layoutRect);

	connect(pushButtonAccept, SIGNAL(clicked()), SLOT(accept()));
	connect(pushButtonReject, SIGNAL(clicked()), SLOT(reject()));
}

RectDialog::~RectDialog() {
	qDebug() << "RectDialog: Bye";
	delete spinBoxH;
	delete spinBoxW;
	delete spinBoxY;
	delete spinBoxX;
	delete pushButtonReject;
	delete pushButtonAccept;
	delete hboxLayoutRect;
	delete layoutRect;
}
