#include "schedule.h"
#include <QString>

Schedule::Schedule(
        int _id,
        QString _depart,
        QString _dest,
        QString _dateDepart,
        QString _dateDest,
        int _ticketCount
        ){
    id = _id;
    depart = _depart;
    dest = _dest;
    dateDepart = _dateDepart;
    dateDest = _dateDest;
    ticketCount = _ticketCount;
};

void Schedule::setId(int _id){
    id = _id;
};
void Schedule::setDepart(QString _depart){
    depart = _depart;
};
void Schedule::setDest(QString _dest){
    dest = _dest;
};
void Schedule::setDateDepart(QString _dateDepart){
    dateDepart = _dateDepart;
};
void Schedule::setDateDest(QString _dateDest){
    dateDest = _dateDest;
};
void Schedule::setTicketCount(int _ticketCount){
    ticketCount = _ticketCount;
};

QJsonObject Schedule::toJson() const{
    return {
        {"id", id},
        {"depart", depart},
        {"dest", dest},
        {"dateDepart", dateDepart},
        {"dateDest",dateDest},
        {"ticketCount",ticketCount}};
};

int Schedule::getId(){
    return id;
};
QString Schedule::getDepart(){
    return depart;
};
QString Schedule::getDest(){
    return dest;
};
QString Schedule::getDateDepart(){
    return dateDepart;
};
QString Schedule::getDateDest(){
    return dateDest;
};
int Schedule::getTicketCount(){
    return ticketCount;
};
