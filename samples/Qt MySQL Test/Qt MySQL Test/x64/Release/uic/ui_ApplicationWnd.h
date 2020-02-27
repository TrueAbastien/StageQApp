/********************************************************************************
** Form generated from reading UI file 'ApplicationWnd.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLICATIONWND_H
#define UI_APPLICATIONWND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ApplicationWndClass
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *resultTable;
    QPushButton *connectBtn;
    QHBoxLayout *horizontalLayout;
    QPushButton *runBtn;
    QLineEdit *queryEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ApplicationWndClass)
    {
        if (ApplicationWndClass->objectName().isEmpty())
            ApplicationWndClass->setObjectName(QString::fromUtf8("ApplicationWndClass"));
        ApplicationWndClass->resize(600, 400);
        centralWidget = new QWidget(ApplicationWndClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 601, 341));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        resultTable = new QTableWidget(verticalLayoutWidget);
        resultTable->setObjectName(QString::fromUtf8("resultTable"));

        verticalLayout->addWidget(resultTable);

        connectBtn = new QPushButton(verticalLayoutWidget);
        connectBtn->setObjectName(QString::fromUtf8("connectBtn"));

        verticalLayout->addWidget(connectBtn);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        runBtn = new QPushButton(verticalLayoutWidget);
        runBtn->setObjectName(QString::fromUtf8("runBtn"));

        horizontalLayout->addWidget(runBtn);

        queryEdit = new QLineEdit(verticalLayoutWidget);
        queryEdit->setObjectName(QString::fromUtf8("queryEdit"));

        horizontalLayout->addWidget(queryEdit);


        verticalLayout->addLayout(horizontalLayout);

        ApplicationWndClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ApplicationWndClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        ApplicationWndClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ApplicationWndClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ApplicationWndClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ApplicationWndClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ApplicationWndClass->setStatusBar(statusBar);

        retranslateUi(ApplicationWndClass);

        QMetaObject::connectSlotsByName(ApplicationWndClass);
    } // setupUi

    void retranslateUi(QMainWindow *ApplicationWndClass)
    {
        ApplicationWndClass->setWindowTitle(QApplication::translate("ApplicationWndClass", "ApplicationWnd", nullptr));
        connectBtn->setText(QApplication::translate("ApplicationWndClass", "Connect to Database", nullptr));
        runBtn->setText(QApplication::translate("ApplicationWndClass", "Run Query", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ApplicationWndClass: public Ui_ApplicationWndClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLICATIONWND_H
