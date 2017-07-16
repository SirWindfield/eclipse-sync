/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QFormLayout *formLayout;
    QLineEdit *txt_name;
    QLineEdit *txt_x;
    QLineEdit *txt_y;
    QDialogButtonBox *button_box;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(212, 151);
        formLayout = new QFormLayout(Dialog);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        txt_name = new QLineEdit(Dialog);
        txt_name->setObjectName(QStringLiteral("txt_name"));

        formLayout->setWidget(0, QFormLayout::LabelRole, txt_name);

        txt_x = new QLineEdit(Dialog);
        txt_x->setObjectName(QStringLiteral("txt_x"));

        formLayout->setWidget(1, QFormLayout::LabelRole, txt_x);

        txt_y = new QLineEdit(Dialog);
        txt_y->setObjectName(QStringLiteral("txt_y"));

        formLayout->setWidget(2, QFormLayout::LabelRole, txt_y);

        button_box = new QDialogButtonBox(Dialog);
        button_box->setObjectName(QStringLiteral("button_box"));
        button_box->setOrientation(Qt::Horizontal);
        button_box->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(3, QFormLayout::LabelRole, button_box);


        retranslateUi(Dialog);
        QObject::connect(button_box, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(button_box, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        txt_name->setPlaceholderText(QApplication::translate("Dialog", "Name", Q_NULLPTR));
        txt_x->setPlaceholderText(QApplication::translate("Dialog", "X", Q_NULLPTR));
        txt_y->setPlaceholderText(QApplication::translate("Dialog", "Y", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
