#ifndef RECTDIALOG_HP
#define RECTDIALOG_HP

#include <QtGui>
#include <QDialog>

class RectDialog : public QDialog {
    Q_OBJECT
	QSpinBox *spinBoxX;
public:
    explicit RectDialog(QWidget *parent = 0);

signals:

public slots:

};

#endif // RECTDIALOG_HP
