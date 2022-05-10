#ifndef SCHEDULEMODEL_H
#define SCHEDULEMODEL_H

#include <QAbstractTableModel>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QDateTime>
#include "schedule.h"
#include "counter.h"
class ScheduleModel : public QAbstractTableModel
{
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QList<Schedule*> list;
public:
    explicit ScheduleModel(QObject *parent = nullptr);
    void append(Schedule* schedule);
    void write(QString filename);
    void clear();
    void removeRows(int pos,int row);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    void edit(int pos, int row);
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Counter *counter;
};

#endif // SCHEDULEMODEL_H
