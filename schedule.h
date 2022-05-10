#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <QString>
#include <QDateTime>
#include <QJsonObject>
#include <QList>

class Schedule
{
    int id;
    QString depart;
    QString dest;
    QString dateDepart;
    QString dateDest;
    int ticketCount;
public:
    Schedule(
            int _id,
            QString _depart,
            QString _dest,
            QString _dateDepart,
            QString _dateDest,
            int _ticketCount
            );
    Schedule* getData();
    QJsonObject toJson() const;

    void setId(int _id);
    void setDepart(QString _depart);
    void setDest(QString _dest);
    void setDateDepart(QString _dateDepart);
    void setDateDest(QString _dateDest);
    void setTicketCount(int _ticketCount);

    int getId();
    QString getDepart();
    QString getDest();
    QString getDateDepart();
    QString getDateDest();
    int getTicketCount();
};

#endif // SCHEDULE_H
