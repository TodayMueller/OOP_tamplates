#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QObject>

class Registration : public QObject
{
    Q_OBJECT
public:
    explicit Registration(QObject *parent = nullptr);
    int getCost() const;
    QString getStatus() const;
    QString getName() const;
    QString getNumber() const;
    void setCost(int cost);
    void setStatus(QString status);
    void setName(QString name);
    void setNumber(QString number);

signals:

private:
    QString name;
    QString number;
    QString status;
    int cost;
};

#endif // REGISTRATION_H
