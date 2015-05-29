#include "learning_manager_menu.h"
#include "ui_learningmanagermenu.h"

learning_manager_menu::learning_manager_menu(QWidget *parent) :
    menu_base(parent),
    ui(new Ui::LearningManagerMenu)
{
    a_n_s = new add_new_student();
    a_n_c = new add_new_class();
    a_p_t_c = new assign_pupil_to_class();
    ui->setupUi(this);
}

learning_manager_menu::~learning_manager_menu()
{
    if(a_n_s) delete a_n_s;
    if(a_n_c) delete a_n_c;
    if(a_p_t_c) delete a_p_t_c;
    delete ui;
}

void learning_manager_menu::restore_menu()
{
    this->show();
}

void learning_manager_menu::closeEvent (QCloseEvent *event) {

}

void learning_manager_menu::on_addPupil_clicked()
{
    a_n_s->show();
}

void learning_manager_menu::on_addPupilToClass_clicked()
{
    a_p_t_c->show_assign_pupil_to_class_dialog();
}

void learning_manager_menu::on_addClass_clicked()
{
    a_n_c->show();
}

void learning_manager_menu::on_view_classes_clicked()
{
    QString qtext("select class_num(c.creation_date) || c.letter as Клас, count(ca.id_pupil_in_class) as Учнів "
                  "from classes c "
                  "LEFT JOIN ("
                      "select distinct on (id_pupil) * "
                      "from admission_schoolers "
                      "order by id_pupil, date desc"
                  ") ca "
                  "on c.id_class=ca.id_class "
                  "group by c.id_class, c.creation_date, c.letter");
    QSqlQuery query;
    query.prepare(qtext);
    query.exec();
    qDebug() << query.lastError().text();
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);
    emit open_main_window(model);
    this->hide();
}
