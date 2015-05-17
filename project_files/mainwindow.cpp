#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QTableView* MainWindow::getTable(){
    return this->ui->query_table;
}

void MainWindow::loadModel(QSqlQueryModel* model) {

    qDebug() << model->lastError().text();
    getTable()->setModel(model);

}

void MainWindow::closeEvent (QCloseEvent *event) {
    event->ignore();
    getTable()->model()->deleteLater();
    emit close_main_window();
}
