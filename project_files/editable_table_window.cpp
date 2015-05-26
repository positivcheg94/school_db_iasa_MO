#include "editable_table_window.h"
#include "ui_editable_table_window.h"

editable_table_window::editable_table_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::editable_table_window)
{
    ui->setupUi(this);
}

editable_table_window::~editable_table_window()
{
    delete ui;
}
