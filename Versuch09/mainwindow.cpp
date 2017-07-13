#include "city.h"
#include "dialog.h"
#include "newstreetdialog.h"
#include "dijkstra.h"
#include "mainwindow.h"
#include "map.h"
#include "mapionrw.h"
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

    this->mapIo = new MapIoNrw();
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
    ui->btn_create->setVisible(ui->chkbox->isChecked());
    ui->test_abstract_map->setVisible(ui->chkbox->isChecked());
    ui->test_search->setVisible(ui->chkbox->isChecked());
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

    scene.clear();
    map.draw(scene);
}

void MainWindow::on_fill_map_clicked()
{
    mapIo->fillMap(map);
    map.draw(scene);
}

void MainWindow::on_test_abstract_map_clicked()
{
        City *a = new City("a", 0, 0);
        City *b = new City("b", 0, 100);
        City *c = new City("c", 100, 300);
        Street *s = new Street(a, b);
        Street *s2 = new Street(b, c);


        qDebug() << "MapTest: Start Test of the Map";
        {
            qDebug() << "MapTest: adding wrong street";
            bool t1 = map.addStreet(s);
            if (t1) {
                qDebug() << "-Error: Street should not be added, if cities have not been added.";
            }
        }

        {
            qDebug() << "MapTest: adding correct street";
            map.addCity(a);
            map.addCity(b);
            bool t1 = map.addStreet(s);
            if (!t1) {
                qDebug() << "-Error: It should be possible to add this street.";
            }
        }

        {
            qDebug() << "MapTest: find city";
            City* city = map.find_city("a");
            if (city != a)
                qDebug() << "-Error: City a could not be found.";

            city = map.find_city("b");
            if (city != b)
                qDebug() << "-Error: City b could not be found.";

            city = map.find_city("c");
            if (city != NULL)
                qDebug() << "-Error: If city could not be found 0 should be returned.";
        }

        map.addCity(c);
        map.addStreet(s2);

        {
            qDebug() << "MapTest: get_opposite_city";
            const City *city = map.get_opposite_city(s, a);
            if (city != b)
                qDebug() << "-Error: Opposite city should be b.";

            city = map.get_opposite_city(s, c);
            if (city != 0)
                qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
        }

        {
            qDebug() << "MapTest: street_length";
            double l = map.get_length(s2);
            double expectedLength = 223.6;
            // compare doubles with 5% tolerance
            if (l < expectedLength * 0.95 || l > expectedLength *1.05)
                qDebug() << "-Error: Street Length is not equal to the expected.";

        }

        {
            qDebug() << "MapTest: get_street_list";
            std::vector<Street*> streetList1 = map.get_street_list(a);
            std::vector<Street*> streetList2 = map.get_street_list(b);
            if (streetList1.size() != 1) {
                qDebug() << "-Error: One street should be found for city a.";
            }
            else if (*streetList1.begin() != s) {
                    qDebug() << "-Error: The wrong street has been found for city a.";
            }

            if (streetList2.size() != 2)
                qDebug() << "-Error: Two streets should be found for city b.";
        }

        qDebug() << "MapTest: End Test of the Map.";
}

void MainWindow::on_test_search_clicked()
{
    // load cities
    if(map.getCities().size() == 0)
    {
        mapIo->fillMap(map);
    }
    redraw();

    search("Aachen", "Bonn");
}

void MainWindow::on_create_street_clicked()
{
    NewStreetDialog dialog(this);
    dialog.exec();

    redraw();
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->from->text().isEmpty() || ui->to->text().isEmpty())
    {
        return;
    }

    // search
    search(ui->from->text(), ui->to->text());
}

void MainWindow::redraw()
{
    scene.clear();
    map.draw(scene);
}

void MainWindow::search(QString from, QString to)
{
    // search for shortest route
    std::vector<Street*> result = Dijkstra::search(map, from, to);
    QPen pen(Qt::red);
    pen.setWidth(3);

    redraw();
    for(Street* s : result)
    {
        s->draw(scene, pen);
    }
}
