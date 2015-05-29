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

QString conferention_widget::get_first(){
    return this->ui->line1->text();
}

QString conferention_widget::get_second(){
    return this->ui->line2->text();
}

QString conferention_widget::get_third(){
    return this->ui->line3->text();
}
