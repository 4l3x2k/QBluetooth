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


#include "bluetoothrfcomm.hpp"


BluetoothRFComm::BluetoothRFComm() {
	qDebug() << "BluetoothRFComm: Hello";
}

BluetoothRFComm::~BluetoothRFComm() {
	qDebug() << "BluetoothRFComm: Bye";
	disconnecting();
}

bool BluetoothRFComm::getStatus() {
	if(status == 0)
		return true;
	return false;
}

bool BluetoothRFComm::connecting(QString name, qint32 channel) {
	qDebug() << "BluetoothRFComm: Connecting to" << neighboors.key(name);
	struct sockaddr_rc addr;

	addr.rc_family = AF_BLUETOOTH;
	str2ba(neighboors.key(name).toStdString().c_str(), &addr.rc_bdaddr);
	addr.rc_channel = channel;
	sock = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
	status = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
	if(status == 0) {
		qDebug() << "BluetoothRFComm: Connecting success";
		return true;
	}
	else {
		qDebug() << "BluetoothRFComm: Error" << errno;
		return false;
	}
}

bool BluetoothRFComm::disconnecting() {
	qDebug() << "BluetoothRFComm: Disconnecting";
	close(sock);
	return true;
}

int BluetoothRFComm::send(void *data, qint32 size) {
	qDebug() << "BluetoothRFComm: Sending " << data;
	return write(sock, data, size);
}
