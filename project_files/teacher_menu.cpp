#include "teacher_menu.h"
#include "ui_teacher_menu.h"


teacher_menu::teacher_menu(QWidget *parent,QString db_login) :
    menu_base(parent),
    ui(new Ui::teacher_menu)
{

    ui->setupUi(this);

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

    a_marks=new add_marks();

    connect(a_marks,SIGNAL(restore_main_menu()),this,SLOT(restore_menu()));
}

teacher_menu::~teacher_menu()
{
    delete ui;
}

void teacher_menu::restore_menu()
{
    this->show();
}


void teacher_menu::on_marks_clicked()
{
    a_marks->show_add_marks(staff_id);
}

void teacher_menu::on_tnw_button_clicked()
{
    temporary_not_working tnw(0,staff_id);
    if ( tnw.exec() == QDialog::Accepted){

    }
}
