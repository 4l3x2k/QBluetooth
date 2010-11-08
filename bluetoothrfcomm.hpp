#ifndef BLUETOOTHRFCOMM_HPP
#define BLUETOOTHRFCOMM_HPP

#include <string>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>
#include "bluetoothdevice.hpp"


class BluetoothRFComm : public BluetoothDevice {
	int sock;
	int status;

public:
	BluetoothRFComm();
	BluetoothRFComm(std::string);
	BluetoothRFComm(std::string, std::string);
	BluetoothRFComm(std::string, std::string, int);
	~BluetoothRFComm();

	int getStatus();

	int connecting(std::string);
	int connecting(std::string, int);
	int connecting(int, int);
	int send(std::string);
};
#endif
