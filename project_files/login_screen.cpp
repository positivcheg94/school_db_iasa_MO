#include "login_screen.h"
#include "ui_login_screen.h"

login_screen::login_screen(QSqlDatabase &database, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login_screen),
    db(database)
{
    ui->setupUi(this);
    this->installEventFilter(this);
    ui->username->installEventFilter(this);
    ui->password->installEventFilter(this);
    connect(this,SIGNAL(returnPressed()),SLOT(on_log_in_button_clicked()));
}

login_screen::~login_screen()
{
    delete ui;
}

bool login_screen::eventFilter(QObject *obj, QEvent *event) {
    if(event->type() == QEvent::KeyPress){
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter){
            emit returnPressed();
            return true;
        }
    }
    return QMainWindow::eventFilter(obj, event);
}

void login_screen::on_log_in_button_clicked(){
    QString username = this->ui->username->text();
    QString password = this->ui->password->text();
    db.setUserName(username);
    db.setPassword(password);
    if(!db.open()){
        this->ui->username->clear();
        this->ui->password->clear();
        QMessageBox msg;
        msg.setText("Cannot connect to database");
        msg.exec();
    }
    else{
        QMessageBox msg;
        msg.setText("200 OK");
        msg.exec();
    }
    db.close();
}
