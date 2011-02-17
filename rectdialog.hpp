#ifndef RECTDIALOG_HP
#define RECTDIALOG_HP

#include <QtGui>
#include <QDebug>


class RectDialog : public QDialog {
    Q_OBJECT
	QFormLayout *layoutRect;
	QHBoxLayout *hboxLayoutRect;
	QPushButton *pushButtonAccept;
	QPushButton *pushButtonReject;

public:
	QSpinBox *spinBoxX;
	QSpinBox *spinBoxY;
	QSpinBox *spinBoxW;
	QSpinBox *spinBoxH;

    explicit RectDialog(QWidget *parent = 0);
	~RectDialog();

signals:

public slots:

};

#endif // RECTDIALOG_HP
