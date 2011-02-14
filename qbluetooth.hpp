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


#ifndef QBLUETOOTH_HPP
#define QBLUETOOTH_HPP

#include <QtCore>
#include <QtGui>

#include "bluetoothdisplaytable.hpp"
#include "bluetoothrfcomm.hpp"

namespace Ui {
    class QBluetooth;
}


class QBluetooth : public QMainWindow {
    Q_OBJECT
    Ui::QBluetooth *ui;
	BluetoothDisplayTable *display;
	BluetoothRFComm *channel;

public:
    explicit QBluetooth(QWidget *parent = 0);
    ~QBluetooth();

private slots:
	// Context menu actions
	void on_actionOpen_triggered();
	void on_actionSave_triggered();

	// Device tab buttons
	void on_toolButtonScan_clicked();

	// Device tab lists
	//void on_listWidget_itemClicked();
	void on_listWidget_itemDoubleClicked();

	// Display tab buttons
	void on_toolButtonSend_clicked();
	void on_toolButtonClear_clicked();

	// Disply edit buttons
	void on_toolButtonRectangle_clicked();
};

#endif // QBLUETOOTH_HPP
