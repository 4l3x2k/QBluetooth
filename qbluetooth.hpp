#ifndef QBLUETOOTH_HPP
#define QBLUETOOTH_HPP

#include <QMainWindow>
#include <QList>
#include <QListWidgetItem>
#include <QGraphicsScene>
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
	QGraphicsScene qgs;

private slots:
	// Device tab buttons
	void on_toolButtonScan_clicked();
	void on_toolButtonConnect_clicked();

	// Device tab lists
	void on_listWidget_itemClicked(QListWidgetItem *);

	// Display tab buttons
	void on_toolButtonSend_clicked();
	void on_toolButtonClear_clicked();

	// Display tab graphics view
	void on_verticalSliderZoom_valueChanged(int);
};

#endif // QBLUETOOTH_HPP
