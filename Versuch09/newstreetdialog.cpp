#include "newstreetdialog.h"
#include "ui_newstreetdialog.h"
#include "mainwindow.h"

#include <string>
#include <vector>

#include <QCompleter>
#include <QDebug>
#include <QStringList>

NewStreetDialog::NewStreetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewStreetDialog)
{
    ui->setupUi(this);

    // setup auto complete
    QStringList list;
    for(City* city : getMainWindow()->getMap()->getCities())
    {
        list.push_back(city->getName());
    }

    QCompleter* completer = new QCompleter(list, this);
    completer->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->from->setCompleter(completer);
    ui->to->setCompleter(completer);
    qDebug() << list.size();
}

NewStreetDialog::~NewStreetDialog()
{
    delete ui;
}

MainWindow* NewStreetDialog::getMainWindow()
{
    return (MainWindow*) parent();
}

void NewStreetDialog::on_buttonBox_accepted()
{
    City* c1 = getMainWindow()->getMap()->find_city(ui->from->text());
    City* c2 = getMainWindow()->getMap()->find_city(ui->to->text());

    Street* s = new Street(c1, c2);
    getMainWindow()->getMap()->addStreet(s);
}
