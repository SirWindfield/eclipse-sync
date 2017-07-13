/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionAdd_separator;
    QAction *actionExit;
    QAction *actionClear_Scene;
    QAction *actionAbout;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QCheckBox *chkbox;
    QPushButton *test_cities;
    QPushButton *btn_create;
    QGraphicsView *graphicsView;
    QLineEdit *from;
    QPushButton *fill_map;
    QSpacerItem *verticalSpacer;
    QPushButton *test_search;
    QPushButton *create_street;
    QPushButton *test_abstract_map;
    QPushButton *btn_create_city;
    QLabel *lbl_input;
    QLineEdit *to;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuScene;
    QMenu *menuInfo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(658, 518);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionOpen->setEnabled(false);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave->setEnabled(false);
        actionAdd_separator = new QAction(MainWindow);
        actionAdd_separator->setObjectName(QStringLiteral("actionAdd_separator"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionClear_Scene = new QAction(MainWindow);
        actionClear_Scene->setObjectName(QStringLiteral("actionClear_Scene"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        chkbox = new QCheckBox(centralWidget);
        chkbox->setObjectName(QStringLiteral("chkbox"));

        gridLayout->addWidget(chkbox, 8, 0, 1, 1);

        test_cities = new QPushButton(centralWidget);
        test_cities->setObjectName(QStringLiteral("test_cities"));

        gridLayout->addWidget(test_cities, 9, 0, 1, 1);

        btn_create = new QPushButton(centralWidget);
        btn_create->setObjectName(QStringLiteral("btn_create"));

        gridLayout->addWidget(btn_create, 4, 0, 1, 1);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 1, 13, 1);

        from = new QLineEdit(centralWidget);
        from->setObjectName(QStringLiteral("from"));
        from->setClearButtonEnabled(true);

        gridLayout->addWidget(from, 1, 0, 1, 1);

        fill_map = new QPushButton(centralWidget);
        fill_map->setObjectName(QStringLiteral("fill_map"));

        gridLayout->addWidget(fill_map, 7, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 12, 0, 1, 1);

        test_search = new QPushButton(centralWidget);
        test_search->setObjectName(QStringLiteral("test_search"));

        gridLayout->addWidget(test_search, 11, 0, 1, 1);

        create_street = new QPushButton(centralWidget);
        create_street->setObjectName(QStringLiteral("create_street"));

        gridLayout->addWidget(create_street, 6, 0, 1, 1);

        test_abstract_map = new QPushButton(centralWidget);
        test_abstract_map->setObjectName(QStringLiteral("test_abstract_map"));

        gridLayout->addWidget(test_abstract_map, 10, 0, 1, 1);

        btn_create_city = new QPushButton(centralWidget);
        btn_create_city->setObjectName(QStringLiteral("btn_create_city"));

        gridLayout->addWidget(btn_create_city, 5, 0, 1, 1);

        lbl_input = new QLabel(centralWidget);
        lbl_input->setObjectName(QStringLiteral("lbl_input"));

        gridLayout->addWidget(lbl_input, 0, 0, 1, 1);

        to = new QLineEdit(centralWidget);
        to->setObjectName(QStringLiteral("to"));

        gridLayout->addWidget(to, 2, 0, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 3, 0, 1, 1);

        gridLayout->setColumnStretch(1, 1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 658, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuScene = new QMenu(menuBar);
        menuScene->setObjectName(QStringLiteral("menuScene"));
        menuInfo = new QMenu(menuBar);
        menuInfo->setObjectName(QStringLiteral("menuInfo"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuScene->menuAction());
        menuBar->addAction(menuInfo->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuScene->addAction(actionClear_Scene);
        menuInfo->addAction(actionAbout);

        retranslateUi(MainWindow);

        pushButton->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        actionAdd_separator->setText(QApplication::translate("MainWindow", "Add Separator", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("MainWindow", "Alt+E", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionClear_Scene->setText(QApplication::translate("MainWindow", "Clear Scene", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionClear_Scene->setShortcut(QApplication::translate("MainWindow", "Alt+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionAbout->setText(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        chkbox->setText(QApplication::translate("MainWindow", "Top Secret Buttons", Q_NULLPTR));
        test_cities->setText(QApplication::translate("MainWindow", "Test Cities", Q_NULLPTR));
        btn_create->setText(QApplication::translate("MainWindow", "Create", Q_NULLPTR));
        from->setPlaceholderText(QApplication::translate("MainWindow", "From...", Q_NULLPTR));
        fill_map->setText(QApplication::translate("MainWindow", "Fill Map", Q_NULLPTR));
        test_search->setText(QApplication::translate("MainWindow", "Test Search", Q_NULLPTR));
        create_street->setText(QApplication::translate("MainWindow", "Create Street", Q_NULLPTR));
        test_abstract_map->setText(QApplication::translate("MainWindow", "Test Abstract Map", Q_NULLPTR));
        btn_create_city->setText(QApplication::translate("MainWindow", "Create City", Q_NULLPTR));
        lbl_input->setText(QApplication::translate("MainWindow", "Input", Q_NULLPTR));
        to->setPlaceholderText(QApplication::translate("MainWindow", "To...", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuScene->setTitle(QApplication::translate("MainWindow", "Scene", Q_NULLPTR));
        menuInfo->setTitle(QApplication::translate("MainWindow", "Info", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
