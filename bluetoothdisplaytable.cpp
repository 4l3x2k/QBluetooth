/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2011	Alexander Meinke <ameinke at online dot de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include "bluetoothdisplaytable.hpp"


BluetoothDisplayTable::BluetoothDisplayTable(QWidget *parent):
    QTableWidget(parent),
	QImage(QSize(128, 64), QImage::Format_Mono) {
	qDebug() << "BluetoothDisplayTable: Hello";
	fill(0);
	setColumnCount(128);
	setRowCount(64);
	setShowGrid(true);
	horizontalHeader()->setVisible(false);
	verticalHeader()->setVisible(false);
	for(quint8 i = 0; i < 128; ++i) {
		setColumnWidth(i, 10);
		setRowHeight(i, 10);
	}
	setEditTriggers(QAbstractItemView::NoEditTriggers);
	setSelectionMode(QAbstractItemView::MultiSelection);
	setSelectionBehavior(QAbstractItemView::SelectItems);

	connect(this, SIGNAL(cellClicked(int,int)), SLOT(cellSelected(int,int)));
	connect(this, SIGNAL(cellEntered(int,int)), SLOT(cellSelected(int,int)));
}

BluetoothDisplayTable::~BluetoothDisplayTable() {
	qDebug() << "BluetoothDisplayTable: Bye";
}

void BluetoothDisplayTable::addPrimitive(Primitive *primitive) {
	primitives.push_back(primitive);
	primitive->draw();
}

unsigned short BluetoothDisplayTable::getPrimitiveSize() {
	return primitives.size();
}

void BluetoothDisplayTable::cellSelected(int row, int column) {
	qDebug() << "BluetoothDisplayTable: Cell " << column << "x" << row << " selected";
	QTableWidgetItem *item = new QTableWidgetItem();
	item->setSelected(true);
	setItem(row, column, item);
	setPixel(column, row, 1);
}

void BluetoothDisplayTable::openImage(QString file) {
	qDebug() << "BluetoothDisplayTable: Opening";
	if(load(file))
		qDebug() << "BluetoothDisplayTable: Opening success";
	qDebug() << "BluetoothDisplayTable: Bytes" << byteCount();
	for(quint16 y = 0; y < 64; y++)
		for(quint16 x = 0; x < 128; x++)
			if(pixel(x, y) == QColor(Qt::white).rgb())
				setCurrentCell(y, x, QItemSelectionModel::Select);
}

void BluetoothDisplayTable::saveImage(QString file) {
	qDebug() << "BluetoothDisplayTable: Saving";
	save(file);
}
