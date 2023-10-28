#include "lists.h"

Lists::Lists(QObject *parent)
    : QObject{parent}
{
    actualCarData = nullptr;
    actualOwnerData = nullptr;
    actualRegData = nullptr;
}

Lists::~Lists()
{
    if(actualCarData){
    delete actualCarData;
    actualCarData = nullptr;
    }
    qDeleteAll(CarArray);
    CarArray.clear();

    if(actualOwnerData){
    delete actualOwnerData;
    actualOwnerData = nullptr;
    }
    qDeleteAll(OwnerArray);
    OwnerArray.clear();

    if(actualRegData){
    delete actualRegData;
    actualRegData = nullptr;
    }
    qDeleteAll(RegArray);
    RegArray.clear();
}

void Lists::delAll(const QString& name)
{
    for (int i = 0; i < OwnerArray.size(); i++) {
        if (OwnerArray[i]->getName() == name) {
            delete OwnerArray.takeAt(i);
            break;
        }
    }
    for (int i = 0; i < RegArray.size(); i++) {
        if (RegArray[i]->getName() == name) {
            QString numberToRemove = RegArray[i]->getNumber();
            delete RegArray.takeAt(i);
            i--;
            for (int j = 0; j < CarArray.size(); j++) {
                if (CarArray[j]->getNumber() == numberToRemove) {
                    delete CarArray.takeAt(j);
                    break;
                }
            }
        }
    }
}

void Lists::delCar(const QString& number){
    for (int i = 0; i < CarArray.size(); i++) {
        if (CarArray[i]->getNumber() == number) {
            delete CarArray.takeAt(i);
            break;
        }
    }
    for (int i = 0; i < RegArray.size(); i++) {
        if (RegArray[i]->getNumber() == number) {
            delete RegArray.takeAt(i);
            break;
        }
    }
}

bool Lists::uniqName(QString inpName){
    for (int i = 0; i < OwnerArray.size(); i++) {
        if (OwnerArray[i]->getName() == inpName) {
            return 1;
        }
    }
    return 0;
}

bool Lists::uniqNum(QString inpNumber){
    for (int i = 0; i < CarArray.size(); i++) {
        if (CarArray[i]->getNumber() == inpNumber) {
            return 1;
        }
    }
    return 0;
}

void Lists::addCar(Cars *value){
    if (!Lists::uniqNum(value->getNumber()))
        CarArray.append(value);
}

void Lists::addOwner(Owners *value){
    if (!Lists::uniqName(value->getName()))
        OwnerArray.append(value);
}

void Lists::addReg(Registration *value){
    RegArray.append(value);
}


void Lists::Display(QTableView* tableView)
{
    QStandardItemModel* model = new QStandardItemModel();

    model->setHorizontalHeaderLabels({"Клиент", "Номер авто", "Статус", "Цена ремонта"});

    for (int row = 0; row < RegArray.size(); ++row) {
        Registration* reg = RegArray[row];
        QStandardItem* nameItem = new QStandardItem(reg->getName());
        QStandardItem* numItem = new QStandardItem(reg->getNumber());
        QStandardItem* statusItem = new QStandardItem(reg->getStatus());
        QStandardItem* costItem = new QStandardItem(QString::number(reg->getCost()));
        model->setItem(row, 0, nameItem);
        model->setItem(row, 1, numItem);
        model->setItem(row, 2, statusItem);
        model->setItem(row, 3, costItem);
    }

    tableView->setModel(model);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Lists::HighlightVal(QTableView* tableView, const QString& fieldValue)
{
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(tableView->model());
    if (!model)
        return;
    // Проходим по всем элементам модели
    for (int row = 0; row < model->rowCount(); ++row) {
        bool matchFound = false;
        for (int column = 0; column < model->columnCount(); ++column) {
            QModelIndex index = model->index(row, column);
            QString value = model->data(index).toString();
            // Проверяем значение поля
            if (value == fieldValue) {
                matchFound = true;
                break;
            }
        }
        // Подсвечиваем всю строку, если найдено совпадение
        if (matchFound) {
            QModelIndex start = model->index(row, 0);
            QModelIndex end = model->index(row, model->columnCount() - 1);
            QItemSelection selection(start, end);
            tableView->selectionModel()->select(selection, QItemSelectionModel::Select);
        }
    }
}

void Lists::Change(const QString &number){
    for (int i = 0; i < RegArray.size(); i++) {
        if (RegArray[i]->getNumber() == number) {
            if (RegArray[i]->getStatus() == "В ремонте"){
                RegArray[i]->setStatus("Готово к выдаче");
            }
            else RegArray[i]->setStatus("В ремонте");
            break;
        }
    }
}

QString Lists::findName(const QString& name){
    for (int i = 0; i < OwnerArray.size(); i++) {
        if (OwnerArray[i]->getName() == name) {
            return OwnerArray[i]->getTel();
        }
    }
}

Cars* Lists::findNum(const QString& num){
    for (int i = 0; i < CarArray.size(); i++) {
        if (CarArray[i]->getNumber() == num) {
            return CarArray[i];
        }
    }
}
