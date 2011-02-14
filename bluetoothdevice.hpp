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


#ifndef BLUETOOTHDEVICE_HPP
#define BLUETOOTHDEVICE_HPP

#include <QtCore>

#ifdef Q_OS_LINUX
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#endif

#ifdef Q_OS_MAC
#include <Foundation.h>
#include <Bluetooth.h>
#include <IOBluetooth.h>
#endif


#ifdef Q_OS_MAC
@interface BluetoothDeviceDelegate : NSObject {
}
@end
#endif // Q_OS_MAC

class BluetoothDevice {
#ifdef Q_OS_LINUX
	qint32 deviceId;
	qint32 device;
#endif

#ifdef Q_OS_MAC
	BluetoothDeviceDelegate *delegate;
	IOBluetoothDeviceInquiry *deviceInquiry;
#endif

protected:
	QMap<QString, QString> neighboors;

public:
    BluetoothDevice();
	~BluetoothDevice();

	qint32 inquiry();
	QString getRemoteAddress(QString) const;
	QString getRemoteName(QString) const;
	QList<QString> getRemoteNames() const;
};

#endif // BLUETOOTHDEVICE_HPP
