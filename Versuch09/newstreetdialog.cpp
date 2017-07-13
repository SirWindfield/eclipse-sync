#include "newstreetdialog.h"
#include "ui_newstreetdialog.h"

NewStreetDialog::NewStreetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewStreetDialog)
{
    ui->setupUi(this);
}

NewStreetDialog::~NewStreetDialog()
{
    delete ui;
}
