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


@implementation BluetoothDeviceDelegate
-(void) deviceInquiryStarted:(IOBluetoothDeviceInquiry*)sender {
	qDebug() << "BluetoothDeviceDelegate: Inquiry started";
}

-(void) deviceInquiryDeviceFound:(IOBluetoothDeviceInquiry*)sender
		device:(IOBluetoothDevice*)device {
	qDebug() << "BluetoothDeviceDelegate: Device found";
}

-(void) deviceInquiryUpdatingDeviceNamesStarted:(IOBluetoothDeviceInquiry*)sender
		devicesRemaining:(uint32_t)devicesRemaining {
	qDebug() << "BluetoothDeviceDelegate: Updating names";
}

-(void) deviceInquiryDeviceNameUpdated:(IOBluetoothDeviceInquiry*)sender
		device:(IOBluetoothDevice*)device
		devicesRemaining:(uint32_t)devicesRemaining {
	qDebug() << "BluetoothDeviceDelegate: Names updated";
}

-(void) deviceInquiryComplete:(IOBluetoothDeviceInquiry*)sender
		error:(IOReturn)error
		aborted:(BOOL)aborted {
	qDebug() << "BluetoothDeviceDelegate: Inquiry complete";
}
@end

BluetoothDevice::BluetoothDevice():
    delegate([BluetoothDeviceDelegate new]),
	deviceInquiry([IOBluetoothDeviceInquiry inquiryWithDelegate:delegate]) {
	qDebug() << "BluetoothDevice: Hello";
}

BluetoothDevice::~BluetoothDevice() {
	delete deviceInquiry;
	delete delegate;
	qDebug() << "BluetoothDevice: Bye";
}

qint32 BluetoothDevice::inquiry() {
	qDebug() << "BluetoothDevice: Inquiry";
	NSArray *result;
	if([deviceInquiry start] == kIOReturnSuccess) {
		sleep(10);
		[deviceInquiry stop];
		result = [deviceInquiry foundDevices];
		for(quint32 i = 0; i < [result count]; i++) {
			qDebug() << "BluetoothDevice: "
					<< [[[result objectAtIndex:i] getAddressString] UTF8String]
					<< " ("
					<< [[[result objectAtIndex:i] name] UTF8String] << ")";
			neighboors.insert([[[result objectAtIndex:i] getAddressString] UTF8String],
							  [[[result objectAtIndex:i] name] UTF8String]);
		}
	}
	return neighboors.size();
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
	for(i = neighboors.begin();	i != neighboors.end();	i++)
		devices.append(i.value());
	return devices;
}
