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


#ifndef BLUETOOTHDISPLAYTABLE_HPP
#define BLUETOOTHDISPLAYTABLE_HPP

#include <QDebug>
#include <QTableWidget>
#include <QHeaderView>
#include <QImage>


class BluetoothDisplayTable : public QTableWidget, public QImage {
    Q_OBJECT

public:
    explicit BluetoothDisplayTable(QWidget *parent = 0);
	~BluetoothDisplayTable();
	void addRect(QPoint, QSize);

signals:

private slots:
	void cellSelected(int, int); // NOT a slot (signal?)

public slots:
	void openImage(QString);
	void saveImage(QString);
};

#endif // BLUETOOTHDISPLAYTABLE_HPP
