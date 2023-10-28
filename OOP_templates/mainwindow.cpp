#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Add_clicked()
{
    if (ui->FIO->text().size()!= 0 && ui->Num->text().size()!= 0 && !info.uniqNum(ui->Num->text())){
        if (!info.uniqName(ui->FIO->text())){
            Owners *owner = new Owners();
            owner->setName(ui->FIO->text());
            owner->setTel(ui->Tel->text());
            info.addOwner(owner);
        }
        Cars *car = new Cars();
        car->setClass(ui->Class_type->currentIndex());
        car->setModel(ui->Model->text());
        car->setNumder(ui->Num->text());
        car->setType(ui->Rep_type->currentIndex());
        info.addCar(car);
        Registration *reg = new Registration();
        reg->setName(ui->FIO->text());
        reg->setNumber(ui->Num->text());
        reg->setStatus(ui->Status->currentText());
        Facade *calcFacade = new Facade();
        reg->setCost(calcFacade->calculate(ui->Rep_type->currentIndex(),car));
        ui->Cost->setText(QString::number(reg->getCost()));
        info.addReg(reg);
        info.Display(ui->Out);
    }
    else {
        ui->Error->setText("Добавление невозможно");
    }
}


void MainWindow::on_Del_owner_clicked()
{
    if (!ui->FIO->text().isEmpty() && info.uniqName(ui->FIO->text())) {
            info.delAll(ui->FIO->text());
            info.Display(ui->Out);
        }
    else ui->Error->setText("Удаление невозможно");
}


void MainWindow::on_Find_owner_clicked()
{
    if (!ui->FIO->text().isEmpty() && info.uniqName(ui->FIO->text())) {
        info.HighlightVal(ui->Out, ui->FIO->text());
        ui->Tel->setText(info.findName(ui->FIO->text()));
    }
    else ui->Error->setText("Поиск невозможен");
}


void MainWindow::on_Del_car_clicked()
{
    if (!ui->Num->text().isEmpty() && info.uniqNum(ui->Num->text())) {
            info.delCar(ui->Num->text());
            info.Display(ui->Out);
        }
    else ui->Error->setText("Удаление невозможно");
}


void MainWindow::on_Find_car_clicked()
{
    if (!ui->Num->text().isEmpty() && info.uniqNum(ui->Num->text())) {
        info.HighlightVal(ui->Out, ui->Num->text());
        Cars *car = info.findNum(ui->Num->text());
        ui->Model->setText(car->getModel());
        ui->Class_type->setCurrentIndex(car->getClass());
        ui->Rep_type->setCurrentIndex(car->getType());
    }
    else ui->Error->setText("Поиск невозможен");
}

void MainWindow::on_pushButton_clicked()
{
    info.Change(ui->Num->text());
    info.Display(ui->Out);
}

