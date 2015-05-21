#ifndef LOGIN_SCREEN_H
#define LOGIN_SCREEN_H

#include <QKeyEvent>
#include <QMainWindow>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class login_screen;
}

class login_screen : public QMainWindow
{
    Q_OBJECT

public:
    explicit login_screen(QSqlDatabase& database, QWidget *parent = 0);
    ~login_screen();

protected:
    bool eventFilter(QObject *obj, QEvent *ev);

signals:
    void returnPressed();
    void loginSucceed(QString role, QString username);


private slots:
    void on_log_in_button_clicked();

private:
    Ui::login_screen *ui;
    QSqlDatabase& db;
};

#endif // LOGIN_SCREEN_H
