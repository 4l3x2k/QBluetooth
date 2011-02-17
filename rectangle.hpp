#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QDebug>
#include <QPoint>
#include <QSize>
#include "bluetoothdisplaytable.hpp"
#include "primitive.hpp"


class Rectangle: public Primitive {
	QPoint point;
	QSize size;

	public:
		BluetoothDisplayTable *display;

		Rectangle(BluetoothDisplayTable *, QPoint, QSize);
		~Rectangle();

		virtual void draw();
};
#endif
