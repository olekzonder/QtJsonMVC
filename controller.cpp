#include "controller.h"

Controller::Controller()
{

}

void Controller::setScheduleModel(ScheduleModel* _model){
    model = _model;
};

void Controller::read(QString filename) {
            QFile file(filename);
            file.open(QIODevice::ReadOnly);
            QTextStream text(&file);
            QByteArray rawJson = text.readAll().toUtf8();
            file.close();
            QJsonDocument doc = QJsonDocument::fromJson(rawJson);
            QJsonArray array = doc.object()["Schedule"].toArray();
            for (QJsonValue jsonval : array) {
                QJsonObject object = jsonval.toObject();
                model->append(new Schedule(
                        object["id"].toInt(),
                        object["depart"].toString(),
                        object["dest"].toString(),
                        object["dateDepart"].toString(),
                        object["dateDest"].toString(),
                        object["ticketCount"].toInt()
                        )
                        );
            }
};

void Controller::write(QString fileName){
    model->write(fileName);
}

void Controller::clear(){
    model->clear();

};
void Controller::addNew(Schedule* sched){
    model->append(sched);
};

void Controller::remove(int pos,int row){
    model->removeRows(pos,row);
};

//void Controller::edit(int pos, int row){
//    model->edit(pos,row);
//}
