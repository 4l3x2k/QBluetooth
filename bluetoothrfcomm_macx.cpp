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


@implementation BluetoothRFCommDelegate
-(void) rfcommChannelData:(IOBluetoothRFCOMMChannel*)rfcommChannel
		data:(void *)dataPointer
		length:(size_t)dataLength {
	qDebug() << "BluetoothRFCommDelegate: Incomming data";
}

-(void)	rfcommChannelOpenComplete:(IOBluetoothRFCOMMChannel*)rfcommChannel
		status:(IOReturn)error {
	qDebug() << "BluetoothRFCommDelegate: Channel open";
}

-(void) rfcommChannelClosed:(IOBluetoothRFCOMMChannel*)rfcommChannel {
	qDebug() << "BluetoothRFCommDelegate: Channel close";
}

-(void) rfcommChannelControlSignalsChanged:(IOBluetoothRFCOMMChannel*)rfcommChannel {
	qDebug() << "BluetoothRFCommDelegate: Signals changed";
}

-(void) rfcommChannelFlowControlChanged:(IOBluetoothRFCOMMChannel*)rfcommChannel {
	qDebug() << "BluetoothRFCommDelegate: Flow changed";
}

-(void) rfcommChannelWriteComplete:(IOBluetoothRFCOMMChannel*)rfcommChannel
		refcon:(void*)refcon
		status:(IOReturn)error {
	qDebug() << "BluetoothRFCommDelegate: Write complete";
}

- (void)rfcommChannelQueueSpaceAvailable:(IOBluetoothRFCOMMChannel*)rfcommChannel {
	qDebug() << "BluetoothRFCommDelegate: Queue space available";
}
@end

BluetoothRFComm::BluetoothRFComm():
	delegate([BluetoothRFCommDelegate new]) {
	qDebug() << "BluetoothRFComm: Hello";
}

BluetoothRFComm::~BluetoothRFComm() {
	//delete rfcommChannel;
	//delete remoteDevice;
	delete delegate;
	qDebug() << "BluetoothRFComm: Bye";
}

bool BluetoothRFComm::connecting(QString name, qint32 channel) {
	qDebug() << "BluetoothRFComm: Connecting to" << neighboors.key(name);
	IOBluetoothSDPUUID *sppServiceUUID;
	IOBluetoothSDPServiceRecord *sppServiceRecord;
	BluetoothDeviceAddress addressBluetoothDevice;
	NSString *addressString = [NSString new];

	sppServiceUUID = [IOBluetoothSDPUUID uuid16:kBluetoothSDPUUID16ServiceClassSerialPort];
	addressString = [NSString stringWithCString:neighboors.key(name).toAscii() encoding:NSASCIIStringEncoding];
	if(IOBluetoothNSStringToDeviceAddress(addressString, &addressBluetoothDevice) == kIOReturnSuccess)
		qDebug() << "BluetoothRFComm: Address ok";
	remoteDevice = [IOBluetoothDevice withAddress:&addressBluetoothDevice];
	sppServiceRecord = [remoteDevice getServiceRecordForUUID:sppServiceUUID];
	if(sppServiceRecord == nil)
		qDebug() << "BluetoothRFComm: Error - no spp service in selected device.";
	//[rfcommChannel setSerialParameters:9600 dataBits:8 parity:kBluetoothRFCOMMParityTypeNoParity stopBits:1];
	if([remoteDevice openRFCOMMChannelSync:&rfcommChannel withChannelID:channel delegate:delegate] == kIOReturnSuccess)
	//if([device openRFCOMMChannelAsync:&RFCOMMChannel withChannelID:channel delegate:delegate] == kIOReturnSuccess)
		qDebug() << "BluetoothRFComm: Connecting success";
	return true;
}

bool BluetoothRFComm::getStatus() {
	qDebug() << "BluetoothRFComm: Status" << [rfcommChannel isOpen];
	return [rfcommChannel isOpen];
}

bool BluetoothRFComm::disconnecting() {
	qDebug() << "BluetoothRFComm: Disconnecting";
	return [rfcommChannel closeChannel];
}

qint32 BluetoothRFComm::send(void *data, qint32 size) {
	qDebug() << "BluetoothRFComm: Sending" << data;
	if([rfcommChannel writeSync:data length:size] == kIOReturnSuccess)
			return size;
	return -1;
}
