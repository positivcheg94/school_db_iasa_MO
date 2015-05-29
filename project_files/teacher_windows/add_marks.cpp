#include "add_marks.h"
#include "ui_add_marks.h"

void add_marks::show_add_marks(int staff_id) {
    if(staff_id) {
        loadSubjects(staff_id);
        loadClasses(0);
        loadMarks();
        this->show();
    }
}

add_marks::add_marks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_marks)
{
    ui->setupUi(this);

    QStringList types= QStringList() << "normal" << "control" << "exam" << "semester";
    ui->mark_type->addItems(types);
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

void add_marks::loadSubjects(int staff_id) {
    QString qtext = "SELECT DISTINCT ON (pw.id_human,id_subject) "
                    " s.subject_name, s.id_subject, p.id_personnel "
                    "FROM people_workers pw "
                    "JOIN personnel p ON pw.id_human=p.id_human "
                    "JOIN positions pos ON p.id_position=pos.id_position "
                    "JOIN subjects s ON s.id_subject=pos.id_subject "
                    "WHERE pw.id_human = ? "
                    "ORDER BY pw.id_human, id_subject, s.subject_name ASC, end_working_date DESC;";

    //TODO: UNION with changes

    QSqlQuery query;
    query.prepare(qtext);
    query.addBindValue(staff_id);
    query.exec();
    qDebug() << query.lastError().text();
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);
    ui->cbSubjects->setModel(model);
}

void add_marks::loadClasses(int index) {
    QString qtext = "SELECT DISTINCT class_num(creation_date) || letter AS class_name, id_class "
                    "FROM ("
                        "SELECT  DISTINCT ON (s.day_of_week, s.lesson_number, s.id_class) s.*, c.creation_date, c.letter "
                        "FROM schedule s "
                        "LEFT JOIN classes c ON s.id_class=c.id_class"
                    ") this_sched"
                    " WHERE class_num(creation_date)<=11 AND id_personnel = ? ORDER BY class_name ASC";

    //TODO: changes

    QSqlQuery query;
    query.prepare(qtext);
    qDebug() << "id personnel " << this->ui->cbSubjects->model()->index(this->ui->cbSubjects->currentIndex(),2).data().toInt();
    query.addBindValue(this->ui->cbSubjects->model()->index(this->ui->cbSubjects->currentIndex(),2).data().toInt());
    query.exec();
    qDebug() << query.lastError().text();


    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);

    if(ui->cbClasses->model()) ui->cbClasses->model()->deleteLater();
    ui->cbClasses->setModel(model);
}



void add_marks::on_cbSubjects_currentIndexChanged(int index)
{
   loadClasses(index);
   loadMarks();
}

void add_marks::loadMarks() {
    if(ui->tableView->model()) ui->tableView->model()->deleteLater();

    QString qtext = "select s.last_name || ' ' || s.first_name || ' ' || s.patronim as ПІБ, m.date AS Дата, m.type AS Тип, m.mark AS Оцінка, "
                    " fio(t.last_name,t.first_name,t.patronymic) AS Викладач"
            " from markings m "
                    "LEFT JOIN schoolers s on m.id_pupil=s.id_pupil "
                    "left join ( "
                        "select distinct on(id_pupil) * "
                        "from admission_schoolers "
                        "order by id_pupil, date desc"
                    ") a_s "
                    "on s.id_pupil=a_s.id_pupil "
                    "LEFT JOIN personnel pp "
                    "ON m.id_teacher=pp.id_personnel "
                    "LEFT JOIN people_workers t "
                    "ON t.id_human=pp.id_human "
                    "WHERE id_teacher=? AND a_s.id_class=? AND age(cast(m.date as date)) < '1 week' "
                    "ORDER BY Дата, Тип, ПІБ;";

    //TODO: changes

    QSqlQuery query;
    query.prepare(qtext);
    query.addBindValue(this->ui->cbSubjects->model()->index(this->ui->cbSubjects->currentIndex(),2).data().toInt());
    query.addBindValue(this->ui->cbClasses->model()->index(this->ui->cbClasses->currentIndex(),1).data().toInt());
    qDebug() <<"class_id" << this->ui->cbClasses->model()->index(this->ui->cbClasses->currentIndex(),1).data().toInt();
    query.exec();
    qDebug() << query.lastError().text();
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);

    if(ui->tableView->model()) ui->tableView->model()->deleteLater();
    ui->tableView->setModel(model);


    QString qschoolers("select last_name || ' ' || first_name || ' ' || patronim as ПІБ, s.id_pupil "
            "from schoolers s "
            "left join ("
                "select distinct on(id_pupil) * "
                "from admission_schoolers "
                "order by id_pupil, date desc"
            ") a_s "
            "on s.id_pupil=a_s.id_pupil "
            "WHERE a_s.id_class=?;");
    QSqlQuery querys;
    querys.prepare(qschoolers);
    querys.addBindValue(this->ui->cbClasses->model()->index(this->ui->cbClasses->currentIndex(),1).data().toInt());
    querys.exec();
    qDebug() << querys.lastError().text();

    QSqlQueryModel* schoolers_model = new QSqlQueryModel();
    schoolers_model->setQuery(querys);

    if(ui->mark_pupil->model()) ui->mark_pupil->model()->deleteLater();
    ui->mark_pupil->setModel(schoolers_model);
}

void add_marks::on_cbClasses_currentIndexChanged(int index)
{
   loadMarks();
}

void add_marks::on_submit_button_clicked()
{
    int id_pupil = this->ui->mark_pupil->model()->index(this->ui->mark_pupil->currentIndex(),1).data().toInt();
    int id_teacher = this->ui->cbSubjects->model()->index(this->ui->cbSubjects->currentIndex(),2).data().toInt();
    int val_mark = this->ui->mark->text().toInt();
    QString val_type = this->ui->mark_type->model()->index(this->ui->mark_type->currentIndex(),0).data().toString();

    QSqlQuery query;
    query.prepare("insert into markings (date, id_pupil, id_teacher,mark,type) values(current_date,?,?,?,?)");
    query.addBindValue(id_pupil);
    query.addBindValue(id_teacher);
    query.addBindValue(val_mark);
    query.addBindValue(val_type);

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

    this->ui->mark->setText("0");
    int ind=this->ui->mark_pupil->currentIndex();
    loadMarks();
    if (ind+1<this->ui->mark_pupil->count())
        this->ui->mark_pupil->setCurrentIndex(ind+1);

}
