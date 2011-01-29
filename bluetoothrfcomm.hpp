#ifndef BLUETOOTHRFCOMM_HPP
#define BLUETOOTHRFCOMM_HPP

#include <string>
#include <bitset>
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
	void disconnecting();
	int send(uint8_t);
	int send(char *, int);
};
#endif
