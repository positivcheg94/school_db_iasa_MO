#include "temporary_not_working.h"
#include "ui_temporary_not_working.h"

temporary_not_working::temporary_not_working(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::temporary_not_working)
{
    ui->setupUi(this);
}

temporary_not_working::~temporary_not_working()
{
    delete ui;
}
