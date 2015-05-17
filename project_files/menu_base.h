#ifndef MENU_BASE_H
#define MENU_BASE_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlError>
#include <QSqlQueryModel>

class menu_base : public QMainWindow
{
    Q_OBJECT
public:
    explicit menu_base(QWidget *parent = 0);
    virtual ~menu_base();

signals:
    void open_main_window(QSqlQueryModel* model);

public slots:
    virtual void restore_menu() = 0;
};

#endif // MENU_BASE_H
