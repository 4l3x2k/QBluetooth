#ifndef QBLUETOOTH_HPP
#define QBLUETOOTH_HPP

#include <string>
#include <QMainWindow>
#include <QTableWidgetItem>
#include <QDebug>
#include "bluetoothrfcomm.hpp"

namespace Ui {
    class QBluetooth;
}


class QBluetooth : public QMainWindow {
    Q_OBJECT

public:
    explicit QBluetooth(QWidget *parent = 0);
    ~QBluetooth();

private:
    Ui::QBluetooth *ui;
	BluetoothRFComm serial;

private slots:
	// Device tab buttons
	void on_toolButtonScan_clicked();
	void on_toolButtonConnect_clicked();
	void on_toolButtonDisconnect_clicked();

	// Device tab lists
	void on_listWidget_itemClicked();

	// Display tab buttons
	void on_toolButtonSend_clicked();
	void on_toolButtonClear_clicked();

	// Display tab table
	void on_tableWidget_cellActivated(int, int);
	void on_tableWidget_cellChanged(int, int);
	void on_tableWidget_cellClicked(int, int);
	void on_tableWidget_cellDoubleClicked(int, int);
	void on_tableWidget_cellEntered(int, int);
	void on_tableWidget_cellPressed(int, int);
};

#endif // QBLUETOOTH_HPP
