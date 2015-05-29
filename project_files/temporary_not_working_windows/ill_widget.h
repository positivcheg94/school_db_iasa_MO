#ifndef ILL_WIDGET_H
#define ILL_WIDGET_H

#include <QWidget>

namespace Ui {
class ill_widget;
}

class ill_widget : public QWidget
{
    Q_OBJECT

public:
    explicit ill_widget(QWidget *parent = 0);
    ~ill_widget();

    QString get_first();


private:
    Ui::ill_widget *ui;
};

#endif // ILL_WIDGET_H
