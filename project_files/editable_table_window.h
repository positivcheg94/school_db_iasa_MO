#ifndef EDITABLE_TABLE_WINDOW_H
#define EDITABLE_TABLE_WINDOW_H

#include <QMainWindow>

namespace Ui {
class editable_table_window;
}

class editable_table_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit editable_table_window(QWidget *parent = 0);
    ~editable_table_window();

private:
    Ui::editable_table_window *ui;
};

#endif // EDITABLE_TABLE_WINDOW_H
