#include "expire_human_on_position.h"
#include "ui_expire_human_on_position.h"

expire_human_on_position::expire_human_on_position(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::expire_human_on_position)
{
    ui->setupUi(this);
}

expire_human_on_position::~expire_human_on_position()
{
    delete ui;
}
