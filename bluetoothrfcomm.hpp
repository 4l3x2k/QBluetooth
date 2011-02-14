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


#ifndef BLUETOOTHRFCOMM_HPP
#define BLUETOOTHRFCOMM_HPP

#include "bluetoothdevice.hpp"

#ifdef Q_OS_LINUX
#include <errno.h>
#include <bluetooth/rfcomm.h>
#endif // Q_OS_LINUX

#ifdef Q_OS_MAC
@interface BluetoothRFCommDelegate : NSObject <IOBluetoothRFCOMMChannelDelegate> {
}
@end
#endif // Q_OS_MAC


class BluetoothRFComm : public BluetoothDevice {
#ifdef Q_OS_LINUX
	qint32 sock;
	qint32 status;
#endif // Q_OS_LINUX

#ifdef Q_OS_MAC
	BluetoothRFCommDelegate *delegate;
	IOBluetoothDevice *remoteDevice;
	IOBluetoothRFCOMMChannel *rfcommChannel;
#endif // Q_OS_MAC

public:
    BluetoothRFComm();
	~BluetoothRFComm();

	bool connecting(QString, qint32);
	bool getStatus();
	bool disconnecting();
	qint32 send(void *, qint32);
};

#endif // BLUETOOTHRFCOMM_HPP
