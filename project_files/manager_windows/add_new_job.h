#ifndef ADD_NEW_JOB_H
#define ADD_NEW_JOB_H

#include <QWidget>

namespace Ui {
class add_new_job;
}

class add_new_job : public QWidget
{
    Q_OBJECT

public:
    explicit add_new_job(QWidget *parent = 0);
    ~add_new_job();

private:
    Ui::add_new_job *ui;
};

#endif // ADD_NEW_JOB_H
