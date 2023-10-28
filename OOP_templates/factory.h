#ifndef FACTORY_H
#define FACTORY_H

#include <QObject>
#include <abstract.h>

class factory : public QObject
{
    Q_OBJECT
public:
    explicit factory(QObject *parent = nullptr);
    int type;
    Abstract* createCalc(int type);

signals:

};

#endif // FACTORY_H
