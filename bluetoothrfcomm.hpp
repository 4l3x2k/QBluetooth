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
/*! Klasse die Nachrichten asynchroner Funktionen auf Mac OS X Systemen
	empfängt. */
@interface BluetoothRFCommDelegate : NSObject <IOBluetoothRFCOMMChannelDelegate> {
}
@end
#endif // Q_OS_MAC

/*! BluetoothRFComm dient als Schnittstelle zu einer seriellen Verbindung
	zwischen dem lokalen Bluetooth-Grät und einem entferntem Bluetooth-Gerät.

	Diese Klasse wird Betriebssystemabhängig implementiert. */
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
	/*! Der Standard-Konstruktor führt keine weiteren Operation durch. */
    BluetoothRFComm();

	/*! Der Standard-Destruktor gibt allozierten Speicher frei. */
	~BluetoothRFComm();

	/*! Stellt eine serielle Verbindung mit einem entfernten Bluetooth-Gerät
		her.
		\param name Gerätename
		\param channel Dienstport
		\return true bei Erfolg, ansonsten false */
	bool connecting(QString, qint32);

	/*! Gibt den aktuellen Status der Verbindung zurück.
		\return true bei hergestellter Verbindung, ansonsten false */
	bool getStatus();

	/*! Baut die Verbindung mit dem entfernten Bluetooth-Gerät ab.
		\return true bei Erfolg, ansonsten false */
	bool disconnecting();

	/*! Sendet Daten über die serielle Verbindung.
		\param data Zeiger auf Anfang der Daten
		\param size Länge der Daten in Byte */
	qint32 send(void *, qint32);
};
#endif // BLUETOOTHRFCOMM_HPP
