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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ApplicationWndClass
{
public:
    QWidget *centralWidget;
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
    } // retranslateUi

};

namespace Ui {
    class ApplicationWndClass: public Ui_ApplicationWndClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLICATIONWND_H
