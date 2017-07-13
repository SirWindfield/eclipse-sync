#ifndef NEWSTREETDIALOG_H
#define NEWSTREETDIALOG_H

#include <QDialog>

namespace Ui {
class NewStreetDialog;
}

class NewStreetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewStreetDialog(QWidget *parent = 0);
    ~NewStreetDialog();

private:
    Ui::NewStreetDialog *ui;
};

#endif // NEWSTREETDIALOG_H
