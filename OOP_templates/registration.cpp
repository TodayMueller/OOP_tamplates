#include "registration.h"

Registration::Registration(QObject *parent)
    : QObject{parent}
{}

QString Registration::getStatus() const{
    return status;
}

int Registration::getCost() const{
    return cost;
}

QString Registration::getName() const{
    return name;
}

QString Registration::getNumber() const{
    return number;
}

void Registration::setCost(int cost){
    this->cost = cost;
}

void Registration::setName(QString name){
    this->name = name;
}

void Registration::setNumber(QString number){
    this->number = number;
}

void Registration::setStatus(QString status){
    this->status = status;
}
