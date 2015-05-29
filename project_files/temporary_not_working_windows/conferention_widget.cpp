#include "conferention_widget.h"
#include "ui_conferention_widget.h"

conferention_widget::conferention_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::conferention_widget)
{
    ui->setupUi(this);
}

conferention_widget::~conferention_widget()
{
    delete ui;
}
