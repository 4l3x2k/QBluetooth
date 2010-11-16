#include "bluetoothrfcomm.hpp"


BluetoothRFComm::BluetoothRFComm() :
BluetoothDevice() {
}

BluetoothRFComm::BluetoothRFComm(std::string localAddress) :
BluetoothDevice(localAddress) {
}

BluetoothRFComm::BluetoothRFComm(std::string localAddress, std::string remoteAddress) :
BluetoothDevice(localAddress) {
	connecting(remoteAddress);
}

BluetoothRFComm::BluetoothRFComm(std::string localAddress, std::string remoteAddress, int channel) :
BluetoothDevice(localAddress) {
	connecting(remoteAddress, channel);
}

BluetoothRFComm::~BluetoothRFComm() {
	close(sock);
}

int BluetoothRFComm::getStatus() {
	return status;
}

int BluetoothRFComm::connecting(std::string remoteAddress) {
	return connecting(remoteAddress, 0);
}

/*
  * Conversion functions of bluez seem to be inconsistent.
  * Use a index pointing to the right remote device in neighbors array.
  * int BluetoothRFComm::connecting(int to, int channel)
  */
int BluetoothRFComm::connecting(std::string remoteAddress, int channel) {
	struct sockaddr_rc addr;

	addr.rc_family = AF_BLUETOOTH;
	str2ba(remoteAddress.c_str(), &addr.rc_bdaddr);
	addr.rc_channel = channel;
	sock = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
	status = connect(sock, (struct sockaddr *)&addr, sizeof(addr));

	return status;
}

int BluetoothRFComm::connecting(int to, int channel) {
	struct sockaddr_rc addr;

	addr.rc_family = AF_BLUETOOTH;
	addr.rc_bdaddr = neighbors[to].bdaddr;
	addr.rc_channel = channel;
	sock = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
	status = connect(sock, (struct sockaddr *)&addr, sizeof(addr));

	return status;
}

int BluetoothRFComm::send(std::string data) {
	return write(sock, data.c_str(), data.length());
}

int BluetoothRFComm::send(void *data, size_t length) {
	return write(sock, &data, length);
}
