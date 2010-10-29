#ifndef QBLUETOOTH_HPP
#define QBLUETOOTH_HPP

#include <QMainWindow>
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
};

#endif // QBLUETOOTH_HPP
