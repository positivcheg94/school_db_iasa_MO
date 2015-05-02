#include "new_human_picker.h"
#include "ui_new_human_picker.h"

new_human_picker::new_human_picker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::new_human_picker)
{
    ui->setupUi(this);
}

new_human_picker::~new_human_picker()
{
    delete ui;
}
