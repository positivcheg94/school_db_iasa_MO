#include "student_menu.h"
#include "ui_student_menu.h"

student_menu::student_menu(QWidget *parent, QString db_login) :
    menu_base(parent),
    ui(new Ui::student_menu)
{
    ui->setupUi(this);
    if(db_login.length()) {
        QString qtext("SELECT DISTINCT ON(l.id_pupil) \
                      s.id_pupil,class_num(c.creation_date)||c.letter AS class, fio(s.last_name, s.first_name, s.patronim) AS fio\
                      FROM schooler_logins l \
                      LEFT JOIN schoolers s ON l.id_pupil=s.id_pupil \
                      LEFT JOIN admission_schoolers ass ON s.id_pupil=ass.id_pupil \
                      LEFT JOIN classes c ON ass.id_class=c.id_class \
                      WHERE l.db_login=? \
                      ORDER BY l.id_pupil ASC,date DESC; ");

        QSqlQuery query;
        query.prepare(qtext);
        query.addBindValue(db_login);
        query.exec();
        if (query.lastError().type()!=QSqlError::NoError){
            QMessageBox msg;
            msg.setText(query.lastError().text());
            msg.exec();
            return;
        }
        if(query.next()) {
            student_id = query.value(0).toInt();
            class_name = query.value(1).toString();
            QString fio = query.value(2).toString();
            this->setWindowTitle(fio);
        }
        query.finish();
    }
    else {
        student_id=0;
        class_name=QString("");
    }
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
    QString qtext("SELECT День,№,Предмет, Вчитель FROM current_schedule cs "
                  "ORDER BY День, №; "
                  "WHERE Клас = ?");
    QSqlQuery query;
    query.prepare(qtext);
    query.addBindValue(class_name);
    query.exec();
    qDebug() << query.lastError().text();
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);
    emit open_main_window(model);
    this->hide();

}


void student_menu::on_show_marks_clicked()
{
    QString qtext("SELECT * FROM markings WHERE id_pupil=? and date > current_date-7");
    QSqlQuery query;
    query.prepare(qtext);
    query.addBindValue(student_id);
    query.exec();
    qDebug() << query.lastError().text();
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);
    emit open_main_window(model);
    this->hide();
}
