#include "manager_menu.h"
#include "ui_manager_menu.h"

manager_menu::manager_menu(QWidget *parent) :
    menu_base(parent),
    ui(new Ui::manager_menu)
{
    ui->setupUi(this);
    n_human_picker = new new_human_picker();
    a_new_subjects = new add_new_subject();

    //connects
    connect(n_human_picker,SIGNAL(restore_main_menu()),this,SLOT(restore_menu()));
    connect(a_new_subjects,SIGNAL(restore_main_menu()),this,SLOT(restore_menu()));
}

manager_menu::~manager_menu()
{
    delete ui;
}


//slots
void manager_menu::on_show_humans_button_clicked()
{
    QString qtext("SELECT * FROM people_workers");
    QSqlQuery query(qtext);
    qDebug() << query.lastError().text();
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);
    emit open_main_window(model);
    this->hide();
}

void manager_menu::restore_menu()
{
    this->show();
}

void manager_menu::on_add_new_human_button_clicked()
{
    this->n_human_picker->show();
    this->hide();

}



void manager_menu::on_add_new_subject_button_clicked()
{
    this->a_new_subjects->show();
    this->hide();
}
