#ifndef BLUETOOTH_HPP
#define BLUETOOTH_HPP

#include <iostream>
#include <map>
#include <string>

#include <cstdlib>

#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>


class Bluetooth {
public:
	std::map<std::string, std::string> Devices;

    Bluetooth();
	~Bluetooth();

	void scan();
};

#endif // BLUETOOTH_HPP
