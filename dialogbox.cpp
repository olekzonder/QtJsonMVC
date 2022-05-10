#include "dialogbox.h"
DialogBox::DialogBox(QWidget *parent)
    : QDialog{parent}
{
    setModal(true);
    resize(500,500);
    setVisible(true);
    setWindowTitle("Добавление нового маршрута");
    layout = new QVBoxLayout(this);
    labelId = new QLabel(this);
    labelDepart = new QLabel(this);
    labelDest = new QLabel(this);
    labelDateDepart = new QLabel(this);
    labelDateDest = new QLabel(this);
    labelTicketCount = new QLabel(this);



    editId = new QLineEdit(this);
    editDepart = new QLineEdit(this);
    editDest = new QLineEdit(this);
    editDateDepart = new QDateTimeEdit(this);
    editDateDest = new QDateTimeEdit(this);
    editTicketCount = new QLineEdit(this);

    labelDepart->setText("Город отправления:");
    labelDepart->setAlignment(Qt::AlignCenter);
    layout->addWidget(labelDepart);
    layout->addWidget(editDepart);

    labelDest->setText("Город назначения:");
    labelDest->setAlignment(Qt::AlignCenter);
    layout->addWidget(labelDest);
    layout->addWidget(editDest);

    labelDateDepart->setText("Дата отправления:");
    labelDateDepart->setAlignment(Qt::AlignCenter);
    layout->addWidget(labelDateDepart);
    editDateDepart->setMinimumDateTime(QDateTime::currentDateTime());
    layout->addWidget(editDateDepart);

    labelDateDest->setText("Дата приезда:");
    labelDateDest->setAlignment(Qt::AlignCenter);
    layout->addWidget(labelDateDest);
    editDateDest->setMinimumDateTime(QDateTime::currentDateTime());
    layout->addWidget(editDateDest);

    labelTicketCount->setText("Кол-во билетов:");
    labelTicketCount->setAlignment(Qt::AlignCenter);
    layout->addWidget(labelTicketCount);
    layout->addWidget(editTicketCount);

    confirmButton = new QPushButton(this);
    cancelButton = new QPushButton(this);

    confirmButton->setText("OK");
    layout->addWidget(confirmButton);
    cancelButton->setText("Отмена");
    layout->addWidget(cancelButton);
    setLayout(layout);

    connect(this->cancelButton,SIGNAL(clicked()),this,SLOT(on_cancel()));
    connect(this->confirmButton,SIGNAL(clicked()),this,SLOT(on_confirm()));
}

Schedule *DialogBox::getData(){
    int id = 0;
    QString depart = editDepart->text();
    QString dest = editDest->text();
    QDateTime dateDepart = editDateDepart->dateTime();
    QDateTime dateDest = editDateDest->dateTime();
    int ticketCount = editTicketCount->text().toInt();
    return new Schedule(id,depart,dest,dateDepart.toString("dd/MM/yyyy hh:mm"),dateDest.toString("dd/MM/yyyy hh:mm"),ticketCount);
};

void DialogBox::on_cancel(){
    this->close();
};

void DialogBox::on_confirm(){
    controller->addNew(this->getData());
    this->close();
};

void DialogBox::setController(Controller *_controller){
    controller = _controller;
};
