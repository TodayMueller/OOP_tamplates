#ifndef FACADE_H
#define FACADE_H

#include <QObject>
#include <abstract.h>
#include <factory.h>
#include <cars.h>

class Facade : public QObject
{
    Q_OBJECT
public:
    explicit Facade(QObject *parent = nullptr);
    int calculate(int type, Cars *value);
private:
    factory calcFactory;
signals:

};

#endif // FACADE_H
