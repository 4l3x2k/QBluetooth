#include "bluetooth.hpp"


Bluetooth::Bluetooth() {
	std::cout << "bleutooth: hello" << std::endl;
}

Bluetooth::~Bluetooth() {
	//std::cout << "bleutooth: bye" << std::endl;
}

void Bluetooth::scan() {
	std::cout << "bluetooth: hci inquiry" << std::endl;

	inquiry_info *ii;
	int devId;
	int sock;
	int numRsp;
	char addr[19] = {0};
	char name[248] = {0};

	devId = hci_get_route(NULL);
	sock = hci_open_dev(devId);
	if(devId < 0 || sock < 0) {
		std::cout << "bluetooth: error opening socket" << std::endl;
		return;
	}
	ii = (inquiry_info *)malloc(10 * sizeof(inquiry_info));
	numRsp = hci_inquiry(devId, 8, 10, NULL, &ii, IREQ_CACHE_FLUSH);
	if(numRsp < 0)
		std::cout << "bluetooth: error inquiry" << std::endl;
	for(int i = 0; i < numRsp; i++) {
		ba2str(&(ii+i)->bdaddr, addr);
		memset(name, 0, sizeof(name));
		if(hci_read_remote_name(sock, &(ii+i)->bdaddr, sizeof(name), name, 0) < 0)
			strcpy(name, "[unknown]");
		Devices[addr] = name;
	}
	free(ii);
	close(sock);

	std::cout << "bluetooth: hci inquiry end" << std::endl;
}
