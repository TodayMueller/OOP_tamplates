#ifndef ABSTRACT_H
#define ABSTRACT_H

#include <QObject>
#include <owners.h>
#include <cars.h>

class Abstract : public QObject
{
    Q_OBJECT
public:
    explicit Abstract(QObject *parent = nullptr);
    virtual int getCost(Cars *value) = 0;
signals:

};

#endif // ABSTRACT_H
