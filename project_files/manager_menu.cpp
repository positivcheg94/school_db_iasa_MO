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
    ad_positions = new administrate_position();
    exp_position = new expire_position();
    ass_human_to_position = new assign_human_to_position();
    exp_human_on_position = new expire_human_on_position();
    learn_man_menu = new learning_manager_menu();

    //connects
    connect(n_human_picker,SIGNAL(restore_main_menu()),this,SLOT(restore_menu()));
    connect(a_new_subject,SIGNAL(restore_main_menu()),this,SLOT(restore_menu()));
    connect(a_new_job,SIGNAL(restore_main_menu()),this,SLOT(restore_menu()));
    connect(ch_job,SIGNAL(restore_main_menu()),this,SLOT(restore_menu()));
    connect(ad_positions,SIGNAL(restore_main_menu()),this,SLOT(restore_menu()));
    connect(exp_position,SIGNAL(restore_main_menu()),this,SLOT(restore_menu()));
    connect(ass_human_to_position,SIGNAL(restore_main_menu()),this,SLOT(restore_menu()));
    connect(exp_human_on_position,SIGNAL(restore_main_menu()),this,SLOT(restore_menu()));
    connect(learn_man_menu,SIGNAL(restore_main_menu()),this,SLOT(restore_menu()));

    connect(this,SIGNAL(show_add_new_job_dialog()),a_new_job,SLOT(show_add_new_job_dialog()));
    connect(this,SIGNAL(show_change_job_dialog()),ch_job,SLOT(show_change_job_dialog()));
    connect(this,SIGNAL(show_administrating_positions_dialog()),ad_positions,SLOT(show_administrating_positions_dialog()));
    connect(this,SIGNAL(show_expire_position_dialog()),exp_position,SLOT(show_expire_position_dialog()));
    connect(this,SIGNAL(show_assign_human_to_position_dialog()),ass_human_to_position,SLOT(show_assign_human_to_position_dialog()));
    connect(this,SIGNAL(show_expire_human_on_position_dialog()),exp_human_on_position,SLOT(show_expire_human_on_position_dialog()));


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
    if (n_human_picker) delete n_human_picker;
    if (a_new_subject) delete a_new_subject;
    if (a_new_job) delete a_new_job;
    if (ch_job) delete ch_job;
    if (ad_positions) delete ad_positions;
    if (exp_position) delete exp_position;
    if (ass_human_to_position) delete ass_human_to_position;
    if (exp_human_on_position) delete exp_human_on_position;
    if (learn_man_menu) delete learn_man_menu;
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
    emit show_add_new_job_dialog();
    this->hide();
}

void manager_menu::on_change_job_button_clicked()
{
    emit show_change_job_dialog();
    this->hide();
}

void manager_menu::on_administrate_position_button_clicked()
{
    emit show_administrating_positions_dialog();
    this->hide();
}

void manager_menu::on_end_position_button_clicked()
{
    emit show_expire_position_dialog();
    this->hide();
}

void manager_menu::on_assign_human_job_button_clicked()
{
    emit show_assign_human_to_position_dialog();
    this->hide();
}

void manager_menu::on_end_human_job_button_clicked()
{
    emit show_expire_human_on_position_dialog();
    this->hide();
}

void manager_menu::on_show_subjects_button_clicked()
{
    QString qtext("SELECT subject_name as \"Назва предмета\",hours_quantity as \"Кількість годин\",study_programe as \"Програма навчання\" FROM subjects order by subject_name");
    QSqlQuery query(qtext);
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);
    emit open_main_window(model);
    this->hide();
}

void manager_menu::on_show_positions_button_clicked()
{
    QString qtext("SELECT position_name as \"Назва посади\",subject_name as \"Назва предмета\" FROM positions p join subjects s on p.id_subject=s.id_subject order by position_name");
    QSqlQuery query(qtext);
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);
    emit open_main_window(model);
    this->hide();
}

void manager_menu::on_show_administrating_positions_button_clicked()
{
    QString qtext("SELECT position_name as \"Назва посади\",salary as \"Зарплата\",position_quantity as \"Кількість місць\",start_date as \"Дата початку\",end_date as \"Дата закінчення\" FROM administrating_positions a join positions p on a.id_position=p.id_position order by position_name");
    QSqlQuery query(qtext);
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);
    emit open_main_window(model);
    this->hide();
}

void manager_menu::on_show_personel_button_clicked()
{
    QString qtext("SELECT first_name||' '||last_name||' '||patronymic||' - '||passport as \"Людина\", position_name as \"Назва посади\", incentive as \"Надбавка\", start_date as \"Дата початку роботи\", end_date as \"Дата закінчення роботи\" FROM personnel p join people_workers pw on p.id_human=pw.id_human join positions pos on p.id_position=pos.id_position");
    QSqlQuery query(qtext);
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);
    emit open_main_window(model);
    this->hide();
}

void manager_menu::on_show_learning_manager_menu_button_clicked()
{
    learn_man_menu->show();
    this->hide();
}

void manager_menu::on_tnw_button_clicked()
{
    temporary_not_working tnw;
    tnw.exec();

}
