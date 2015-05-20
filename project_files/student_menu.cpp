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
    QString qtext("SELECT DISTINCT ON (Клас,day_of_week, lesson_number) class_num(creation_date)||letter as Клас, day_of_week as День, lesson_number as №, subject_name as Предмет, "
                  "CASE WHEN EXISTS "
                          "(SELECT * from changes ch NATURAL JOIN temporary_not_working nw WHERE ch.id_schedule = sc.id_rozkl AND nw.start_date > current_date AND (nw.end_date IS NULL OR nw.end_date >current_date) ) "
                      "THEN "
                          "(SELECT fio(last_name, first_name, patronymic) from changes ch JOIN personnel AS p ON (ch.id_who_is_the_changer=p.id_personnel) NATURAL JOIN temporary_not_working nw  WHERE ch.id_schedule = sc.id_rozkl AND nw.start_date > current_date AND (nw.end_date IS NULL OR nw.end_date >current_date) ) "
                      "ELSE fio(last_name, first_name, patronymic) "
                  "END AS Вчитель "
                  "FROM schedule sc "
                  "NATURAL JOIN classes "
                  "NATURAL JOIN personnel t "
                  "NATURAL JOIN positions "
                  "NATURAL JOIN subjects "
                  "NATURAL JOIN people_workers "
                  "ORDER BY Клас ASC, day_of_week ASC, lesson_number ASC, addition_date DESC;");
    QSqlQuery query(qtext);
    qDebug() << query.lastError().text();
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);
    emit open_main_window(model);
    this->hide();
}

