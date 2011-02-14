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


#include "bluetoothdevice.hpp"


BluetoothDevice::BluetoothDevice():
	deviceId(hci_get_route(NULL)),
	device(hci_open_dev(deviceId)) {
	qDebug() << "BluetoothDevice: Hello";
}

qint32 BluetoothDevice::inquiry() {
	qDebug() << "BluetoothDevice: Inquiry";
	inquiry_info neighboorsTemp[10];
	inquiry_info *neighboorsp = &neighboorsTemp[0];
	bdaddr_t address;

	qint32 neighboorsFound = hci_inquiry(deviceId, 10, 10, NULL,
		&neighboorsp, IREQ_CACHE_FLUSH);
	for(qint32 i = 0; i < neighboorsFound; i++) {
		char remoteName[254] = {0};
		hci_read_remote_name(device, &neighboorsTemp[i].bdaddr,
		                     sizeof(remoteName), &remoteName[0], 0);
		baswap(&address, &neighboorsTemp[i].bdaddr);
		neighboors.insert(batostr(&address),
		                  remoteName);
	}
	return neighboors.size();
}

BluetoothDevice::~BluetoothDevice() {
	qDebug() << "BluetoothDevice: Bye";
}

QString BluetoothDevice::getRemoteAddress(QString name) const {
	qDebug() << "BluetoothDevice: Remote name" << neighboors.key(name);
	return neighboors.key(name);
}

QString BluetoothDevice::getRemoteName(QString address) const {
	qDebug() << "BluetoothDevice: Remote address" << neighboors.value(address);
	return neighboors.value(address);
}

QList<QString> BluetoothDevice::getRemoteNames() const {
	qDebug() << "BluetoothDevice: Remote names";
	QList<QString> devices;
	QMap<QString, QString>::const_iterator i;
	for(i = neighboors.begin(); i != neighboors.end(); i++)
		devices.append(i.value());
	return devices;
}
