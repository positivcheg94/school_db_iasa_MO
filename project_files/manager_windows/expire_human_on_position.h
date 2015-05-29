#ifndef EXPIRE_HUMAN_ON_POSITION_H
#define EXPIRE_HUMAN_ON_POSITION_H

#include <QWidget>

namespace Ui {
class expire_human_on_position;
}

class expire_human_on_position : public QWidget
{
    Q_OBJECT

public:
    explicit expire_human_on_position(QWidget *parent = 0);
    ~expire_human_on_position();

private:
    Ui::expire_human_on_position *ui;
};

#endif // EXPIRE_HUMAN_ON_POSITION_H
