#ifndef CARS_H
#define CARS_H

#include <QObject>

class Cars : public QObject
{
    Q_OBJECT
public:

    explicit Cars(QObject *parent = nullptr);
    int getClass() const;
    int getType() const;
    QString getModel() const;
    QString getNumber() const;
    void setClass(int carClass);
    void setModel(QString model);
    void setNumder(QString number);
    void setType(int type);

signals:

private:
    int repair_type;
    int carClass;
    QString model;
    QString number;
};

#endif // CARS_H
