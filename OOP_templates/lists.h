#ifndef LISTS_H
#define LISTS_H

#include <QObject>
#include <cars.h>
#include <owners.h>
#include <registration.h>
#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>

class Lists : public QObject
{
    Q_OBJECT
public:
    explicit Lists(QObject *parent = nullptr);
    ~Lists();
    void addCar(Cars *value);
    void addOwner(Owners *value);
    void addReg(Registration *value);
    void delAll(const QString& name);
    void delCar(const QString& num);
    bool uniqNum(QString inpNum);
    bool uniqName(QString inpName);
    void Display(QTableView* tableView);
    void HighlightVal(QTableView* tableView, const QString& fieldValue);
    void Change(const QString& name);
    QString findName(const QString& name);
    Cars* findNum(const QString& num);

private:
    QList<Cars *> CarArray;
    QList<Owners *> OwnerArray;
    Cars *actualCarData;
    Owners *actualOwnerData;
    Registration *actualRegData;
    QList<Registration *> RegArray;
signals:

};

#endif // LISTS_H
