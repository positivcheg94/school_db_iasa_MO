#include "manager_menu.h"
#include "ui_manager_menu.h"

manager_menu::manager_menu(QWidget *parent, QString db_login) :
    menu_base(parent),
    ui(new Ui::manager_menu)
{
    ui->setupUi(this);
    n_human_picker = new new_human_picker();
    a_new_subject = new add_new_subject();
    a_new_job = new add_new_job();
    ch_job = new change_job();

    //connects
    connect(n_human_picker,SIGNAL(restore_main_menu()),this,SLOT(restore_menu()));
    connect(a_new_subject,SIGNAL(restore_main_menu()),this,SLOT(restore_menu()));
    connect(a_new_job,SIGNAL(restore_main_menu()),this,SLOT(restore_menu()));
    connect(ch_job,SIGNAL(restore_main_menu()),this,SLOT(restore_menu()));

    connect(this,SIGNAL(show_add_job_dialog(QSqlQueryModel*)),a_new_job,SLOT(show_add_new_job_dialog(QSqlQueryModel*)));
    connect(this,SIGNAL(show_change_job_dialog(QSqlQueryModel*,QSqlQueryModel*)),ch_job,SLOT(show_change_job_dialog(QSqlQueryModel*,QSqlQueryModel*)));

    //Get the staff id

    if(db_login.length()) {
        QString qtext("SELECT sl.id_human, fio(last_name, first_name, patronymic) AS fio "
                      "FROM staff_logins sl "
                      "LEFT JOIN people_workers p ON sl.id_human=p.id_human "
                      "WHERE sl.db_login =?;");

        QSqlQuery query;
        query.prepare(qtext);
        query.addBindValue(db_login);
        query.exec();
        if (query.lastError().type()!=QSqlError::NoError){
            QMessageBox msg;
            qDebug() << query.lastError().text();
            msg.setText(query.lastError().text());
            msg.exec();
            return;
        }
        if(query.next()) {
            staff_id = query.value(0).toInt();
            QString fio = query.value(1).toString();
            this->setWindowTitle(fio);
        }
        query.finish();
    }
    else {
        staff_id=0;
    }
}

manager_menu::~manager_menu()
{
    delete n_human_picker;
    delete a_new_subject;
    delete a_new_job;

    delete ui;
}


//slots
void manager_menu::on_show_humans_button_clicked()
{
    QString qtext("SELECT * FROM people_workers");
    QSqlQuery query(qtext);
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
    this->a_new_subject->show();
    this->hide();
}

void manager_menu::on_add_new_job_button_clicked()
{
    QSqlQuery query("select subject_name,id_subject from subjects order by subject_name asc");
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);
    emit show_add_job_dialog(model);
    this->hide();
}

void manager_menu::on_change_job_button_clicked()
{
    QSqlQuery query("select position_name,id_subject,id_position from positions order by position_name asc");
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);
    QSqlQuery query_subj("select subject_name,id_subject from subjects order by subject_name asc");
    QSqlQueryModel* model_subj = new QSqlQueryModel();
    model_subj->setQuery(query_subj);
    emit show_change_job_dialog(model,model_subj);
    this->hide();
}
