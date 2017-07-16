#include "dialog.h"
#include "mainwindow.h"
#include "ui_dialog.h"

#include <QDialogButtonBox>
#include <QPushButton>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
    updateButton();
}

bool Dialog::isValidInput()
{
    return !ui->txt_name->text().isEmpty() && isNumber(ui->txt_x->text()) && isNumber(ui->txt_y->text());
}

bool Dialog::isNumber(QString string)
{
    bool ok;
    string.toInt(&ok);

    return ok;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::updateButton()
{
    // only enable button if all input is valid
    ui->button_box->button(QDialogButtonBox::Ok)->setEnabled(isValidInput());
}

void Dialog::on_txt_name_cursorPositionChanged(int arg1, int arg2)
{
    updateButton();
}

void Dialog::on_txt_x_cursorPositionChanged(int arg1, int arg2)
{
    updateButton();
}

void Dialog::on_txt_y_cursorPositionChanged(int arg1, int arg2)
{
    updateButton();
}

void Dialog::on_button_box_accepted()
{
    MainWindow *p = (MainWindow*) parent();
    Map* map = p->getMap();
    map->addCity(new City(ui->txt_name->text(), ui->txt_x->text().toInt(), ui->txt_y->text().toInt()));
}
