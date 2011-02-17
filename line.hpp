#ifndef LINE_H
#define LINE_H

#include <QDebug>
#include <QPoint>
#include "primitive.hpp"


class Line: public Primitive {
	QPoint xy;
	QPoint wh;

	public:
		Line(QPoint, QPoint);
		~Line();

		virtual void draw();
};
#endif
