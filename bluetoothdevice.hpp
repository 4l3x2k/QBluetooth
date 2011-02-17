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
/*! Klasse die Nachrichten asynchroner Funktionen auf Mac OS X Systemen
	empfängt. */
@interface BluetoothDeviceDelegate : NSObject {
}
@end
#endif // Q_OS_MAC


/*! BluetoothDevice ist dafür verantwortlich, entfernte Bluetooth-Geräte zu
	finden. Über inquiry wird der Scanvorgang gestartet.

	Diese Klasse wird Betriebssystemabhängig implementiert. */
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
	/*! Geräte in der Umgebung werden mit ihrerer Adresse und ihren Namen
		gespeichert. */
	QMap<QString, QString> neighboors;

public:
	/*! Der Standard-Konstruktor findet ein Bluetooth-Gerät im System. */
    BluetoothDevice();

	/*! Der Standrd-Destruktor gibt allozierten Speicher frei. */
	~BluetoothDevice();

	/*! Inquiry startet einen Scanvorgang und liefert die Anzahl gefundener
		Geräte zurück.
		\return Anzahl Geräte */
	qint32 inquiry();

	/*! Gibt die Adresse eines entfernten Bluetooth-Geräts zurück sofern es
		sich in der näheren Umgebung befindet.
		\param name Gerätename
		\return Geräteadresse */
	QString getRemoteAddress(QString) const;

	/*! Gibt den Namen eines entfernten Bluetooth-Geräts zurück, sofern es
		sich in der näheren Umgebung befindet.
		\param address Geräteadresse
		\return Gerätename */
	QString getRemoteName(QString) const;

	/*! Gibt die Namen aller in der Umgebung befindlichen Geräte zurück.
		\return Liste der Gerätenamen */
	QList<QString> getRemoteNames() const;
};
#endif // BLUETOOTHDEVICE_HPP
