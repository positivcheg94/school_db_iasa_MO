#ifndef TEMPORARY_NOT_WORKING_H
#define TEMPORARY_NOT_WORKING_H

#include <QWidget>

#include "temporary_not_working_windows/ill_widget.h"
#include "temporary_not_working_windows/conferention_widget.h"
#include "temporary_not_working_windows/another_reason_widget.h"

namespace Ui {
class temporary_not_working;
}

class temporary_not_working : public QWidget
{
    Q_OBJECT

public:
    explicit temporary_not_working(QWidget *parent = 0);
    ~temporary_not_working();

private:
    Ui::temporary_not_working *ui;
    ill_widget ill_wget;
    conferention_widget conf_wget;
    another_reason_widget another_reason_wget;
};

#endif // TEMPORARY_NOT_WORKING_H
