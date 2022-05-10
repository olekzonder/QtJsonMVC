#include "schedulemodel.h"

ScheduleModel::ScheduleModel(QObject *parent)
    : QAbstractTableModel{parent}
{
    counter = new Counter(1);
}

void ScheduleModel::append(Schedule* schedule){
    int cnt = counter->get_counter();
    if(schedule->getId()==0) schedule->setId(cnt);
    beginInsertRows(QModelIndex(),list.size(),list.size());
    list.append(schedule);
    endInsertRows();
    counter->set_counter(++cnt);
};

void ScheduleModel::removeRows(int row,int column){
    beginRemoveRows(QModelIndex(),row,row);
    list.removeAt(row);
    endRemoveRows();
};

Qt::ItemFlags ScheduleModel::flags(const QModelIndex &index) const
{
    if(index.column() != 0)
    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

void ScheduleModel::clear(){
    beginRemoveRows(QModelIndex(),0,list.size());
    list.clear();
    endRemoveRows();
}

int ScheduleModel::rowCount(const QModelIndex &parent) const
{

    return list.size();
};

int ScheduleModel::columnCount(const QModelIndex &parent) const
{
    return 6;
};

QVariant ScheduleModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()){
        return QVariant();
    }
    if(role==Qt::DisplayRole){
            int row = index.row();
            int column = index.column();
            Schedule *schedule = list.at(row);
            if(column==0){
                return schedule->getId();
            }
            if(column==1){
                return schedule->getDepart();
            }
            if(column==2){
                return schedule->getDest();
            }
            if(column==3){
                return schedule->getDateDepart();
            }
            if(column==4){
                return schedule->getDateDest();
            }
            if(column==5){
                return schedule->getTicketCount();
    }
}
    return QVariant();
};

void ScheduleModel::write(QString filename){
            QFile file(filename);
            file.open(QIODevice::WriteOnly);
            QJsonArray array;
            for (auto &schedule : list)
            array.append(schedule->toJson());
            QJsonObject obj;
            obj["Schedule"] = array;
            QJsonDocument doc;
            doc.setObject(obj);
            file.write(doc.toJson());
            file.close();
        };

bool ScheduleModel::setData(const QModelIndex &index, const QVariant &value, int role){
    if (role==Qt::EditRole){
        Schedule *schedule = list.at(index.row());
        if(index.column()==1){
            if(!value.toString().isEmpty())
            schedule->setDepart(value.toString());
        }
        if(index.column()==2){
            if(!value.toString().isEmpty())
            schedule->setDest(value.toString());
        }
        if(index.column()==3){
            if(!value.toString().isNull()){
                QString newValue = QDateTime::fromString(value.toString(),"dd/MM/yyyy hh:mm").toString("dd/MM/yyyy hh:mm");
                if(!newValue.isEmpty()) schedule->setDateDepart(newValue);
            }
        }
        if(index.column()==4){
            if(!value.toString().isNull()){
                QString newValue = QDateTime::fromString(value.toString(),"dd/MM/yyyy hh:mm").toString("dd/MM/yyyy hh:mm");
                if(!newValue.isEmpty()) schedule->setDateDest(newValue);
            }
        }
        if(index.column()==5){
            if(!value.toString().isEmpty())
            schedule->setTicketCount(value.toInt());
        }
        return true;
    }
    return false;
}

QVariant ScheduleModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("ID");
        case 1:
            return QString("Откуда");
        case 2:
            return QString("Куда");
        case 3:
            return QString("Время выезда");
        case 4:
            return QString("Время приезда");
        case 5:
            return QString("Кол-во билетов");
        }
    }
    return QVariant();
}
