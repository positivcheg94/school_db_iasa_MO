#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQueryModel>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void loadModel(QSqlQueryModel* model);
    QTableView* getTable();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
