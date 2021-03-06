#ifndef CONFERENTION_WIDGET_H
#define CONFERENTION_WIDGET_H

#include <QWidget>

namespace Ui {
class conferention_widget;
}

class conferention_widget : public QWidget
{
    Q_OBJECT

public:
    explicit conferention_widget(QWidget *parent = 0);
    ~conferention_widget();

    QString get_first();
    QString get_second();
    QString get_third();

private:
    Ui::conferention_widget *ui;
};

#endif // CONFERENTION_WIDGET_H
