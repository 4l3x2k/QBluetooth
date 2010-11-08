#include <QApplication>
#include "qbluetooth.hpp"


int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	QBluetooth qbt;

	qbt.show();

	return app.exec();
}
