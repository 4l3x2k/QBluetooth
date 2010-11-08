#ifndef BLUETOOTHDEVICE_HPP
#define BLUETOOTHDEVICE_HPP

#include <string>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

#define NEIGHBORS 10


class BluetoothDevice {
	int				device;
	int				deviceId;

protected:
	inquiry_info	neighbors[NEIGHBORS];
	int				neighborsFound;

public:
	BluetoothDevice();
	BluetoothDevice(std::string);
	~BluetoothDevice();

	bdaddr_t getRemoteAddress(int);
	std::string getRemoteName(bdaddr_t);

	int inquiry();
};
#endif
