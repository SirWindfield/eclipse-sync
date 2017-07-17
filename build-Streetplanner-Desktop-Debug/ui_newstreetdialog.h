/********************************************************************************
** Form generated from reading UI file 'newstreetdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWSTREETDIALOG_H
#define UI_NEWSTREETDIALOG_H

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

class Ui_NewStreetDialog
{
public:
    QFormLayout *formLayout;
    QLineEdit *from;
    QLineEdit *to;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewStreetDialog)
    {
        if (NewStreetDialog->objectName().isEmpty())
            NewStreetDialog->setObjectName(QStringLiteral("NewStreetDialog"));
        NewStreetDialog->resize(212, 106);
        formLayout = new QFormLayout(NewStreetDialog);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        from = new QLineEdit(NewStreetDialog);
        from->setObjectName(QStringLiteral("from"));

        formLayout->setWidget(0, QFormLayout::LabelRole, from);

        to = new QLineEdit(NewStreetDialog);
        to->setObjectName(QStringLiteral("to"));

        formLayout->setWidget(1, QFormLayout::LabelRole, to);

        buttonBox = new QDialogButtonBox(NewStreetDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(2, QFormLayout::LabelRole, buttonBox);


        retranslateUi(NewStreetDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewStreetDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewStreetDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewStreetDialog);
    } // setupUi

    void retranslateUi(QDialog *NewStreetDialog)
    {
        NewStreetDialog->setWindowTitle(QApplication::translate("NewStreetDialog", "Dialog", Q_NULLPTR));
        from->setPlaceholderText(QApplication::translate("NewStreetDialog", "From...", Q_NULLPTR));
        to->setPlaceholderText(QApplication::translate("NewStreetDialog", "To...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NewStreetDialog: public Ui_NewStreetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWSTREETDIALOG_H
