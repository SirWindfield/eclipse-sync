#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "map.h"
#include "mapio.h"
#include "dijkstra.h"
#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Map* getMap();

private slots:
    void on_btn_create_clicked();

    void on_actionExit_triggered();

    void on_actionClear_Scene_triggered();

    void on_actionAbout_triggered();

    void on_test_cities_clicked();

    void on_chkbox_clicked();

    void on_btn_create_city_clicked();

    void on_fill_map_clicked();

    void on_test_abstract_map_clicked();

    void on_test_search_clicked();

    void on_create_street_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    Map map;
    MapIo* mapIo;


    void toggleButtons();
    void search(QString from, QString to);
    void redraw();
};

#endif // MAINWINDOW_H
