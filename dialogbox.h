#ifndef DIALOGBOX_H
#define DIALOGBOX_H

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QDateTimeEdit>
#include "schedule.h"
#include <controller.h>
class DialogBox : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBox(QWidget *parent = nullptr);
    QVBoxLayout *layout;

    QLabel *labelId;
    QLabel *labelDepart;
    QLabel *labelDest;
    QLabel *labelDateDepart;
    QLabel *labelDateDest;
    QLabel *labelTicketCount;

    QLineEdit *editId;
    QLineEdit *editDepart;
    QLineEdit *editDest;
    QDateTimeEdit *editDateDepart;
    QDateTimeEdit *editDateDest;
    QLineEdit *editTicketCount;

    QPushButton *confirmButton;
    QPushButton *cancelButton;

    Schedule *getData();
    void setController(Controller *_controller);
private:
    Controller *controller;
private slots:
    void on_cancel();
    void on_confirm();
};

#endif // DIALOGBOX_H
