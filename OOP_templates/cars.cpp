#include "cars.h"

Cars::Cars(QObject *parent)
    : QObject{parent}
{}

int Cars::getClass() const{
    return carClass;
}

int Cars::getType() const{
        return repair_type;
    }

QString Cars::getModel() const{
    return model;
}

QString Cars::getNumber() const{
    return number;
}

void Cars::setClass(int carClass){
    this->carClass = carClass;
}

void Cars::setModel(QString model){
    this->model = model;
}

void Cars::setNumder(QString number){
    this->number = number;
}

void Cars::setType(int repair_type){
        this->repair_type = repair_type;
    }
