#include "student_menu.h"
#include "ui_student_menu.h"

student_menu::student_menu(QWidget *parent) :
    menu_base(parent),
    ui(new Ui::student_menu)
{
    ui->setupUi(this);
}

student_menu::~student_menu()
{
    delete ui;
}

//slots
void student_menu::restore_menu()
{
    this->show();
}

void student_menu::on_see_rozklad_clicked()
{
    QString qtext("SELECT cs.Клас, cs.День, templ.№, cs.Предмет, cs.Вчитель "
                  "FROM (SELECT * FROM generate_series(1,(SELECT max(№) FROm current_schedule),1) AS nums(№)) templ "
                  "LEFT JOIN current_schedule cs "
                  "ON (templ.№=cs.№) order by Клас,День, №; ");
    QSqlQuery query(qtext);
    qDebug() << query.lastError().text();
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);
    emit open_main_window(model);
    this->hide();
}

