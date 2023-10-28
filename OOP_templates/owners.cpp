#include "owners.h"

Owners::Owners(QObject *parent)
    : QObject{parent}
{}

    QString Owners::getName() const{
        return name;
    }

    QString Owners::getTel() const{
        return tel;
    }

    void Owners::setName(QString name){
        this->name = name;
    }

    void Owners::setTel(QString tel){
        this->tel = tel;
    }
