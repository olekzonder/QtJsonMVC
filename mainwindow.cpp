#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Редактор расписания поездов");
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ScheduleModel *model = new ScheduleModel();
    controller = new Controller();
    controller->setScheduleModel(model);
    ui->tableView->setModel(model);

    connect(ui->tableView->model(), SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(onModelsDataChanged(const QModelIndex&, const QModelIndex&)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addButton_clicked()
{
    DialogBox *dialog = new DialogBox(this);
    dialog->setController(controller);
    dialog->show();
}



void MainWindow::on_exit_triggered()
{
    this->close();
}


void MainWindow::on_clean_triggered()
{
    this->controller->clear();
}


void MainWindow::on_saveAs_triggered()
{
    QFileDialog dialog(this);
    dialog.setViewMode(QFileDialog::Detail);
    dialog.setNameFilter(tr("JSON (*.json)"));
   fileName = dialog.getSaveFileName(this,tr("Сохранить файл"), QDir::currentPath(), tr("JSON (*.json)"));
   if(!fileName.endsWith(".json")) fileName.append(".json");
   this->controller->write(fileName);
}

void MainWindow::on_newFile_triggered()
{
    this->controller->clear();
    fileName = "";
}


void MainWindow::on_save_triggered()
{
    if(fileName ==""){
        QFileDialog dialog(this);
        dialog.setNameFilter(tr("JSON (*.json)"));
        dialog.setViewMode(QFileDialog::Detail);
       fileName = dialog.getSaveFileName(this,tr("Сохранить файл"), QDir::currentPath(), tr("JSON (*.json)"));
}
    if(!fileName.endsWith(".json")) fileName.append(".json");
    this->controller->write(fileName);
};


void MainWindow::on_open_triggered()
{

    fileName = QFileDialog::getOpenFileName(this,tr("Открыть файл"), QDir::currentPath(), tr("JSON (*.json)"));
    this->controller->clear();
    this->controller->read(fileName);
}


void MainWindow::on_deleteButton_clicked()
{
    QModelIndexList selection = ui->tableView->selectionModel()->selectedRows();
    for(int i=0;i<selection.count();i++){
        QModelIndex index = selection.at(i);
        controller->remove(index.row(),index.column());
    }
}

