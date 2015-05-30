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
    getTable()->setModel(model);
    this->ui->query_table->resizeColumnsToContents();

}

void MainWindow::closeEvent (QCloseEvent *event) {
    event->ignore();
    getTable()->model()->deleteLater();
    emit close_main_window();
}
