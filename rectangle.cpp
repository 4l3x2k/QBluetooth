#include "rectangle.hpp"


Rectangle::Rectangle(BluetoothDisplayTable *_display, QPoint xy, QSize wh):
	point(xy),
	size(wh) {
	qDebug() << "Rectangle: Hello";
	display = _display;
}

Rectangle::~Rectangle() {
	qDebug() << "Rectangle: Bye";
}

void Rectangle::draw() {
	qDebug() << "Rectangle: Drawing";
	for(qint16 x = point.x(); x < point.x()+size.width(); x++) {
		display->setCurrentCell(point.y(), x, QItemSelectionModel::Select);
		display->setPixel(x, point.y(), 1);
		display->setCurrentCell(point.y()+size.height(), x, QItemSelectionModel::Select);
		display->setPixel(x, point.y()+size.height(), 1);
	}
	for(qint16 y = point.y(); y < point.y()+size.height(); y++) {
		display->setCurrentCell(y, point.x(), QItemSelectionModel::Select);
		display->setPixel(point.x(), y, 1);
		display->setCurrentCell(y, point.x()+size.width(), QItemSelectionModel::Select);
		display->setPixel(point.x()+size.width(), y, 1);
	}
	display->setPixel(point.x()+size.width(), point.y()+size.height(), 1);
	display->setCurrentCell(point.y()+size.height(), point.x()+size.width(), QItemSelectionModel::Select);
}
