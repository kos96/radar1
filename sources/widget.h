#ifndef WIDGET_H
#define WIDGET_H
#include <QFile>
#include <QDebug>
#include <QByteArray>
#include <QString>
#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public:
    void readFile();

private:
    Ui::Widget *ui;
};


#endif // WIDGET_H
