#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cars.h>
#include <owners.h>
#include <registration.h>
#include <facade.h>
#include <factory.h>
#include <lists.h>
#include <QTableView>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Add_clicked();

    void on_Del_owner_clicked();

    void on_Find_owner_clicked();

    void on_Del_car_clicked();

    void on_Find_car_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Lists info;
};
#endif // MAINWINDOW_H
