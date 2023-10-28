#ifndef OWNERS_H
#define OWNERS_H

#include <QObject>

class Owners : public QObject
{
    Q_OBJECT
public:
    explicit Owners(QObject *parent = nullptr);
    QString getName() const;
    QString getTel() const;
    void setName(QString name);
    void setTel(QString Tel);
signals:

private:
    QString name;
    QString tel;
};

#endif // OWNERS_H
