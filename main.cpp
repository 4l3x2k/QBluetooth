#include <QApplication>
#include "qbluetooth.hpp"


int main(int argc, char *argv[], char *env[]) {
	QApplication app(argc, argv);
	QBluetooth qbt;

	qbt.show();

	return app.exec();
}
