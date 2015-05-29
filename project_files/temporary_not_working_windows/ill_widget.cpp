#include "ill_widget.h"
#include "ui_ill_widget.h"

ill_widget::ill_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ill_widget)
{
    ui->setupUi(this);
}

ill_widget::~ill_widget()
{
    delete ui;
}
