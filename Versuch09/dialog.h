#ifndef DIALOG_H
#define DIALOG_H

#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_txt_name_cursorPositionChanged(int arg1, int arg2);

    void on_txt_x_cursorPositionChanged(int arg1, int arg2);

    void on_txt_y_cursorPositionChanged(int arg1, int arg2);

    void on_button_box_accepted();

private:
    Ui::Dialog *ui;

    bool isValidInput();
    bool isNumber(QString string);
    void updateButton();
};

#endif // DIALOG_H
