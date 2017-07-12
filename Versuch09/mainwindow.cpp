#include "city.h"
#include "dialog.h"
#include "mainwindow.h"
#include "map.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // custom
    ui->graphicsView->setScene(&scene);
    ui->chkbox->setChecked(false);
    toggleButtons();

    // map lel
    Map map;
    this->map = map;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_create_clicked()
{
    /*double rand = qrand() * 200.0/ RAND_MAX;
    this->scene.addRect(rand, rand, 20, 20);

    qDebug() << rand;*/
}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

void MainWindow::on_actionClear_Scene_triggered()
{
    scene.clear();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox box;
    box.setText("Streetplanner v1");
    box.exec();
}

void MainWindow::on_test_cities_clicked()
{
    scene.clear();
    City c1(QString("Aachen"), 100, 100);
    City c2(QString("Dueren"), 200, 200);

    Map map;
    map.addCity(&c1);
    map.addCity(&c2);
    map.draw(scene);
}

Map* MainWindow::getMap()
{
    return &map;
}

void MainWindow::toggleButtons()
{
    ui->test_cities->setVisible(ui->chkbox->isChecked());
}

void MainWindow::on_chkbox_clicked()
{
    // set status
    toggleButtons();
}

void MainWindow::on_btn_create_city_clicked()
{
    Dialog dialog(this);
    dialog.exec();

    map.draw(scene);
}
