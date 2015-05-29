#include "add_schedule_entry.h"
#include "ui_add_schedule_entry.h"

add_schedule_entry::add_schedule_entry(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_schedule_entry)
{
    ui->setupUi(this);

    QStringList types= QStringList() << "Понеділок" << "Вівторок" << "Середа" << "Четвер" << "П`ятниця" << "Субота";
    ui->day_of_week->addItems(types);
}

add_schedule_entry::~add_schedule_entry()
{
    delete ui;
}

void add_schedule_entry::reload_current_schedule()
{
    QString qtext("SELECT №,Предмет, Вчитель AS Викладач FROM current_schedule cs "
                  "WHERE Клас = ? AND День = ? "
                  "ORDER BY № ");
    QSqlQuery query;
    query.prepare(qtext);
    qDebug() << "\n" << this->ui->class_select->model()->index(this->ui->class_select->currentIndex(),0).data().toString();
    query.addBindValue(this->ui->class_select->model()->index(this->ui->class_select->currentIndex(),0).data().toString());
    qDebug() << "\n" << this->ui->day_of_week->model()->index(this->ui->day_of_week->currentIndex(),0).data().toString();
    query.addBindValue(this->ui->day_of_week->model()->index(this->ui->day_of_week->currentIndex(),0).data().toString());
    query.exec();
    qDebug() << query.lastError().text();
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);
    if(this->ui->tableView->model()) this->ui->tableView->model()->deleteLater();
    this->ui->tableView->setModel(model);
}

void add_schedule_entry::load_teachers_by_subj()
{

    QString qtext("select distinct on (p.id_human, p.id_position) "
                  "fio(pw.last_name, pw.first_name, pw.patronymic), id_personnel"
                  " from personnel p "
                  "JOIN people_workers PW "
                  "on p.id_human=pw.id_human"
                  " WHERE id_position = ?"
                  " order by p.id_human, p.id_position, end_date desc;");
    QSqlQuery query;
    query.prepare(qtext);
    query.addBindValue(this->ui->subject_select->model()->index(this->ui->subject_select->currentIndex(),1).data().toInt());
    query.exec();
    qDebug() << query.lastError().text();
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);
    this->ui->teacher->setModel(model);
}

void add_schedule_entry::show_add_schedule_entry() {

    QString qtext("select class_num(c.creation_date) || c.letter as Клас, id_class "
                  "from classes c "
                  "where class_num(c.creation_date) <=12");
    QSqlQuery query;
    query.prepare(qtext);
    query.exec();
    qDebug() << query.lastError().text();
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);
    this->ui->class_select->setModel(model);

    QString qstext(" select distinct on(s.id_subject) "
                      "subject_name, id_position"
                      " from subjects s "
                      "join positions p"
                      " on s.id_subject=p.id_subject "
                      "order by s.id_subject asc;");
    QSqlQuery querys;
    querys.prepare(qstext);
    querys.exec();
    qDebug() << querys.lastError().text();
    QSqlQueryModel* models = new QSqlQueryModel();
    models->setQuery(querys);
    this->ui->subject_select->setModel(models);

    this->show();

}

void add_schedule_entry::on_class_select_currentIndexChanged(int index)
{
    this->reload_current_schedule();
}

void add_schedule_entry::on_day_of_week_currentIndexChanged(int index)
{
    this->reload_current_schedule();
}

void add_schedule_entry::on_subject_select_currentIndexChanged(int index)
{
    this->load_teachers_by_subj();
}



void add_schedule_entry::on_add_button_clicked()
{
    QString day_of_week = this->ui->day_of_week->model()->index(this->ui->day_of_week->currentIndex(),0).data().toString();
    int id_class = this->ui->class_select->model()->index(this->ui->class_select->currentIndex(),1).data().toInt();

    int lesson_num = this->ui->number->text().toInt();
    int id_personnel = this->ui->teacher->model()->index(this->ui->teacher->currentIndex(),1).data().toInt();

        QSqlQuery query;
    query.prepare("insert into schedule (addition_date, day_of_week, lesson_number, id_class, id_personnel)"
                  " values(current_date,?,?,?,?)");
    query.addBindValue(day_of_week);
    query.addBindValue(lesson_num);
        query.addBindValue(id_class);
    query.addBindValue(id_personnel);

    query.exec();

    //error
    QMessageBox msg;
    if (query.lastError().type()!=QSqlError::NoError){
        msg.setText(query.lastError().text());
        msg.exec();
        return;
    }
    else{
        msg.setText("Rows affected - "+QString::number(query.numRowsAffected()));
        msg.exec();
    }

    if(lesson_num<8) this->ui->number->setValue(lesson_num +1);
    else {
        if(this->ui->day_of_week->currentIndex() +1 < this->ui->day_of_week->count()) {

            this->ui->day_of_week->setCurrentIndex(this->ui->day_of_week->currentIndex() +1);
            this->ui->number->setValue(1);
        }
    }

    this->reload_current_schedule();
}
