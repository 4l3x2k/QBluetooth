#include "line.hpp"


Line::Line(QPoint _xy, QPoint _wh) {
	qDebug() << "Line: Hello";
}

Line::~Line() {
	qDebug() << "Line: Bye";
}

void Line::draw() {
	qDebug() << "Line: Drawing";
}
