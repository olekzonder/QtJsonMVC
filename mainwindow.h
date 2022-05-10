#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialogbox.h"
#include "schedulemodel.h"
#include "controller.h"
#include <QFileDialog>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString fileName="";
private slots:

    void on_addButton_clicked();

    void on_exit_triggered();

    void on_clean_triggered();

    void on_saveAs_triggered();

    void on_newFile_triggered();

    void on_save_triggered();

    void on_open_triggered();

    void on_deleteButton_clicked();

private:
    Ui::MainWindow *ui;
    ScheduleModel* model;
    Controller *controller;

};
#endif // MAINWINDOW_H
