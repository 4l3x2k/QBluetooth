#include "primitive.hpp"


Primitive::Primitive() {
	qDebug() << "Primitive: Hello";
}

Primitive::~Primitive() {
	qDebug() << "Primitive: Bye";
}

void Primitive::draw() {
	qDebug() << "Primitive: Drawing";
}
