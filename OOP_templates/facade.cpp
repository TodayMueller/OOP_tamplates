#include "facade.h"

Facade::Facade(QObject *parent)
    : QObject{parent}
{
}

int Facade::calculate(int type, Cars *value){
    Abstract *calc = calcFactory.createCalc(type);
    int cost = calc->getCost(value);
    delete calc;
    return cost;
}
