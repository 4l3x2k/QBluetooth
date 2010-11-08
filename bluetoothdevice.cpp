#include "bluetoothdevice.hpp"


BluetoothDevice::BluetoothDevice() {
	deviceId = hci_get_route(NULL);
	device = hci_open_dev(deviceId);
}

BluetoothDevice::BluetoothDevice(std::string bdaddr) {
	deviceId = hci_get_route(strtoba(bdaddr.c_str()));
	device = hci_open_dev(deviceId);
}

BluetoothDevice::~BluetoothDevice() {
	hci_close_dev(device);
}

bdaddr_t BluetoothDevice::getRemoteAddress(int of) {
	return neighbors[of].bdaddr;
}

std::string BluetoothDevice::getRemoteName(bdaddr_t address) {
	char remoteName[254] = {0};
	hci_read_remote_name(device, &address, sizeof(remoteName), &remoteName[0], 0);
	return std::string(remoteName);
}

int BluetoothDevice::inquiry() {
	inquiry_info *neighborsp = &neighbors[0];
	neighborsFound = hci_inquiry(deviceId, 8, NEIGHBORS, NULL,
		&neighborsp, IREQ_CACHE_FLUSH);
	return neighborsFound;
}
