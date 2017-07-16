#ifndef NEWSTREETDIALOG_H
#define NEWSTREETDIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class NewStreetDialog;
}

class NewStreetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewStreetDialog(QWidget *parent = 0);
    ~NewStreetDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::NewStreetDialog *ui;

    MainWindow* getMainWindow();
};

#endif // NEWSTREETDIALOG_H
