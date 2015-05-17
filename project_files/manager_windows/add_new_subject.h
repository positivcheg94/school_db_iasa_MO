#ifndef ADD_NEW_SUBJECT_H
#define ADD_NEW_SUBJECT_H

#include <QWidget>

namespace Ui {
class add_new_subject;
}

class add_new_subject : public QWidget
{
    Q_OBJECT

public:
    explicit add_new_subject(QWidget *parent = 0);
    ~add_new_subject();

private:
    Ui::add_new_subject *ui;
};

#endif // ADD_NEW_SUBJECT_H
