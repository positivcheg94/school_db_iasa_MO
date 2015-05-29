#include "temporary_not_working.h"
#include "ui_temporary_not_working.h"

temporary_not_working::temporary_not_working(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::temporary_not_working)
{
    ui->setupUi(this);

    ui->reason_stack->addWidget(dynamic_cast<QWidget*>(&this->ill_wget));
    ui->reason_stack->addWidget(dynamic_cast<QWidget*>(&this->conferention_wget));
    ui->reason_stack->addWidget(dynamic_cast<QWidget*>(&this->another_reason_wget));
    connect(this->ui->reason_picker, SIGNAL(activated(int)), this->ui->reason_stack, SLOT(setCurrentIndex(int)));
}

temporary_not_working::~temporary_not_working()
{
    delete ui;
}

void temporary_not_working::closeEvent(QCloseEvent* event)
{
    event->ignore();
    this->reject();
}

void temporary_not_working::on_submit_button_clicked()
{
    int index = this->ui->reason_picker->currentIndex();
    id_reason = index;
    start = this->ui->dateEdit->text();
    end = this->ui->dateEdit_2->text();
    switch (index) {
    case 0:
        field1 = this->ill_wget.get_first();
        break;
    case 1:
        field1 = this->conferention_wget.get_first();
        field1 = this->conferention_wget.get_second();
        field1 = this->conferention_wget.get_third();
        break;
    case 2:
        field1 = this->another_reason_wget.get_first();
        field1 = this->another_reason_wget.get_second();
        break;
    default:
        break;
    }
    this->accept();
}
