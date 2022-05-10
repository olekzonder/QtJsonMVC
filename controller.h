#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "schedule.h"
#include "schedulemodel.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QDateTime>
class Controller
{
ScheduleModel* model;
public:
    Controller();
    void setScheduleModel(ScheduleModel* _model);
    void read(QString);
    void write(QString);
    void clear();
    void addNew(Schedule*);
    void remove(int pos,int row);
    void edit(int pos, int row);
private:
};

#endif // CONTROLLER_H
