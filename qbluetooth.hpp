#ifndef QBLUETOOTH_HPP
#define QBLUETOOTH_HPP

#include <QMainWindow>
#include <QListWidgetItem>
#include <QDebug>

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

private slots:
	// Device tab buttons
	void on_toolButtonScan_clicked(bool);
	void on_toolButtonConnect_clicked(bool);

	// Device tab list
	void on_listWidget_itemClicked(QListWidgetItem *);

	// Display tab buttons
	void on_toolButtonSend_clicked(bool);
	void on_toolButtonClear_clicked(bool);
};

#endif // QBLUETOOTH_HPP
