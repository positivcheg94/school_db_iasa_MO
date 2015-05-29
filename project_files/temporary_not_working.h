#ifndef TEMPORARY_NOT_WORKING_H
#define TEMPORARY_NOT_WORKING_H

#include <QWidget>

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
};

#endif // TEMPORARY_NOT_WORKING_H
