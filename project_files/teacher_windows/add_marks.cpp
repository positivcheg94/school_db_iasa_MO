#include "add_marks.h"
#include "ui_add_marks.h"

add_marks::add_marks(QWidget *parent, int staff_id) :
    QWidget(parent),
    ui(new Ui::add_marks)
{
    ui->setupUi(this);
    if(staff_id) {
        QString qtext = "SELECT s.subject_name, s.id_subject, p.id_personnel FROM people_workers pw "
                        " JOIN personnel p ON pw.id_human=p.id_human "
                        " JOIN positions pos ON p.id_position=pos.id_position "
                        " JOIN subjects s ON s.id_subject=pos.id_subject"
                        " WHERE pw.id_human = ?"
                        " ORDER BY s.subject_name ASC;";

        //TODO: UNION with changes

        QSqlQuery query;
        query.prepare(qtext);
        query.addBindValue(staff_id);
        query.exec();
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery(query);
        ui->cbSubjects->setModel(model);
    }

}

add_marks::~add_marks()
{
    delete ui;
}

void add_marks::closeEvent(QCloseEvent *event) {
    event->ignore();
    ui->cbSubjects->model()->deleteLater();
     emit restore_main_menu();
    this->hide();
}


void add_marks::on_cbSubjects_currentIndexChanged(int index)
{
    QString qtext = "SELECT DISTINCT class_num(creation_date) || letter AS class_name, id_class "
                    "FROM ("
                        "SELECT  DISTINCT ON (s.day_of_week, s.lesson_number, s.id_class) * "
                        "FROM schedule s "
                        "LEFT JOIN classes c ON s.id_class=c.id_class"
                    ") this_sched"
                    " WHERE class_num(creation_date)<=11 AND id_personnel = ? ORDER BY class_name ASC";

    //TODO: changes

    QSqlQuery query;
    query.prepare(qtext);
    query.addBindValue(this->ui->cbSubjects->model()->index(index,2).data().toInt());
    query.exec();

    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);

    if(ui->cbClasses->model()) ui->cbClasses->model()->deleteLater();
    ui->cbClasses->setModel(model);
}



void add_marks::on_cbClasses_currentIndexChanged(int index)
{
    if(ui->tableView->model()) ui->tableView->model()->deleteLater();

    QString qtext = "SELECT * from markings"
                    " WHERE class_num(creation_date)<=11 AND id_class = ? ORDER BY class_name ASC";

    //TODO: changes

    QSqlQuery query;
    query.prepare(qtext);
    query.addBindValue(this->ui->cbClasses->model()->index(index,1).data().toInt());
    query.exec();

    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);

    if(ui->cbClasses->model()) ui->cbClasses->model()->deleteLater();
    ui->cbClasses->setModel(model);
}
