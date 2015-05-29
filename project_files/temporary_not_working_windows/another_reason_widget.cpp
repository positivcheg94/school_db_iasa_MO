#include "another_reason_widget.h"
#include "ui_another_reason_widget.h"

another_reason_widget::another_reason_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::another_reason_widget)
{
    ui->setupUi(this);
}

another_reason_widget::~another_reason_widget()
{
    delete ui;
}

QString another_reason_widget::get_first(){
    return this->ui->text1->toPlainText();
}

QString another_reason_widget::get_second(){
    return this->ui->text2->toPlainText();
}
