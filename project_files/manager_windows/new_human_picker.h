#ifndef NEW_HUMAN_PICKER_H
#define NEW_HUMAN_PICKER_H

#include <QWidget>

namespace Ui {
class new_human_picker;
}

class new_human_picker : public QWidget
{
    Q_OBJECT

public:
    explicit new_human_picker(QWidget *parent = 0);
    ~new_human_picker();

private:
    Ui::new_human_picker *ui;
};

#endif // NEW_HUMAN_PICKER_H
