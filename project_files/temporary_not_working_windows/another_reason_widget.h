#ifndef ANOTHER_REASON_WIDGET_H
#define ANOTHER_REASON_WIDGET_H

#include <QWidget>

namespace Ui {
class another_reason_widget;
}

class another_reason_widget : public QWidget
{
    Q_OBJECT

public:
    explicit another_reason_widget(QWidget *parent = 0);
    ~another_reason_widget();

private:
    Ui::another_reason_widget *ui;
};

#endif // ANOTHER_REASON_WIDGET_H
