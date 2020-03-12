/********************************************************************************
** Form generated from reading UI file 'QtSquid.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTSQUID_H
#define UI_QTSQUID_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtSquidClass
{
public:
    QAction *actionStyle;
    QAction *actionStyleSheet;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *Search;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *search_VLayout;
    QHBoxLayout *search_HLayout_1;
    QTableWidget *search_resultTable;
    QVBoxLayout *search_VLayout_1_1;
    QFormLayout *search_FLayout_1_1_1;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *search_scanEdit;
    QPushButton *search_scanBtn;
    QHBoxLayout *search_HLayout_2;
    QPushButton *search_runBtn;
    QLabel *search_outputLabel;
    QSpacerItem *horizontalSpacer_2;
    QWidget *Edit;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *edit_VLayout;
    QHBoxLayout *edit_HLayout_2;
    QPushButton *edit_addBtn;
    QPushButton *edit_removeBtn;
    QFormLayout *edit_FLayout_1;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *edit_HLayout_3;
    QPushButton *edit_runBtn;
    QLabel *edit_outputLabel;
    QSpacerItem *horizontalSpacer_3;
    QWidget *Connection;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *conn_VLayout;
    QHBoxLayout *conn_HLayout_1;
    QFormLayout *conn_FLayout_1_1;
    QLabel *conn_labelAddress;
    QLineEdit *conn_editAddress;
    QLabel *conn_labelPort;
    QLineEdit *conn_editPort;
    QPushButton *conn_btnSaveDatabase;
    QFormLayout *conn_FLayout_1_2;
    QLabel *conn_labelPassword;
    QLineEdit *conn_editPassword;
    QPushButton *conn_btnSaveUser;
    QLineEdit *conn_editUsername;
    QLabel *conn_labelUsername;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *conn_HLayout_2;
    QPushButton *conn_runBtn;
    QLabel *conn_outputLabel;
    QSpacerItem *horizontalSpacer;
    QWidget *Permission;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *perm_VLayout;
    QHBoxLayout *perm_HLayout_1;
    QTreeView *perm_permTree;
    QFormLayout *perm_FLayout_1_2;
    QHBoxLayout *perm_HLayout_2;
    QPushButton *perm_refreshBtn;
    QLabel *perm_outputLabel;
    QSpacerItem *horizontalSpacer_4;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuEdition;
    QMenu *menuOutils;
    QMenu *menuOptions;
    QMenu *menuRaccourcis;
    QMenu *menuAide;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtSquidClass)
    {
        if (QtSquidClass->objectName().isEmpty())
            QtSquidClass->setObjectName(QString::fromUtf8("QtSquidClass"));
        QtSquidClass->resize(632, 403);
        actionStyle = new QAction(QtSquidClass);
        actionStyle->setObjectName(QString::fromUtf8("actionStyle"));
        actionStyleSheet = new QAction(QtSquidClass);
        actionStyleSheet->setObjectName(QString::fromUtf8("actionStyleSheet"));
        centralWidget = new QWidget(QtSquidClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(-1, -1, 621, 351));
        Search = new QWidget();
        Search->setObjectName(QString::fromUtf8("Search"));
        verticalLayoutWidget = new QWidget(Search);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 10, 611, 311));
        search_VLayout = new QVBoxLayout(verticalLayoutWidget);
        search_VLayout->setSpacing(6);
        search_VLayout->setContentsMargins(11, 11, 11, 11);
        search_VLayout->setObjectName(QString::fromUtf8("search_VLayout"));
        search_VLayout->setContentsMargins(0, 0, 0, 0);
        search_HLayout_1 = new QHBoxLayout();
        search_HLayout_1->setSpacing(6);
        search_HLayout_1->setObjectName(QString::fromUtf8("search_HLayout_1"));
        search_resultTable = new QTableWidget(verticalLayoutWidget);
        search_resultTable->setObjectName(QString::fromUtf8("search_resultTable"));

        search_HLayout_1->addWidget(search_resultTable);

        search_VLayout_1_1 = new QVBoxLayout();
        search_VLayout_1_1->setSpacing(6);
        search_VLayout_1_1->setObjectName(QString::fromUtf8("search_VLayout_1_1"));
        search_FLayout_1_1_1 = new QFormLayout();
        search_FLayout_1_1_1->setSpacing(6);
        search_FLayout_1_1_1->setObjectName(QString::fromUtf8("search_FLayout_1_1_1"));

        search_VLayout_1_1->addLayout(search_FLayout_1_1_1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        search_VLayout_1_1->addItem(verticalSpacer_3);

        search_scanEdit = new QLineEdit(verticalLayoutWidget);
        search_scanEdit->setObjectName(QString::fromUtf8("search_scanEdit"));
        search_scanEdit->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(search_scanEdit->sizePolicy().hasHeightForWidth());
        search_scanEdit->setSizePolicy(sizePolicy1);
        search_scanEdit->setMinimumSize(QSize(133, 20));

        search_VLayout_1_1->addWidget(search_scanEdit);

        search_scanBtn = new QPushButton(verticalLayoutWidget);
        search_scanBtn->setObjectName(QString::fromUtf8("search_scanBtn"));

        search_VLayout_1_1->addWidget(search_scanBtn);


        search_HLayout_1->addLayout(search_VLayout_1_1);


        search_VLayout->addLayout(search_HLayout_1);

        search_HLayout_2 = new QHBoxLayout();
        search_HLayout_2->setSpacing(6);
        search_HLayout_2->setObjectName(QString::fromUtf8("search_HLayout_2"));
        search_runBtn = new QPushButton(verticalLayoutWidget);
        search_runBtn->setObjectName(QString::fromUtf8("search_runBtn"));
        sizePolicy1.setHeightForWidth(search_runBtn->sizePolicy().hasHeightForWidth());
        search_runBtn->setSizePolicy(sizePolicy1);

        search_HLayout_2->addWidget(search_runBtn);

        search_outputLabel = new QLabel(verticalLayoutWidget);
        search_outputLabel->setObjectName(QString::fromUtf8("search_outputLabel"));

        search_HLayout_2->addWidget(search_outputLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        search_HLayout_2->addItem(horizontalSpacer_2);


        search_VLayout->addLayout(search_HLayout_2);

        tabWidget->addTab(Search, QString());
        Edit = new QWidget();
        Edit->setObjectName(QString::fromUtf8("Edit"));
        verticalLayoutWidget_2 = new QWidget(Edit);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(-1, 9, 611, 311));
        edit_VLayout = new QVBoxLayout(verticalLayoutWidget_2);
        edit_VLayout->setSpacing(6);
        edit_VLayout->setContentsMargins(11, 11, 11, 11);
        edit_VLayout->setObjectName(QString::fromUtf8("edit_VLayout"));
        edit_VLayout->setContentsMargins(0, 0, 0, 0);
        edit_HLayout_2 = new QHBoxLayout();
        edit_HLayout_2->setSpacing(6);
        edit_HLayout_2->setObjectName(QString::fromUtf8("edit_HLayout_2"));
        edit_addBtn = new QPushButton(verticalLayoutWidget_2);
        edit_addBtn->setObjectName(QString::fromUtf8("edit_addBtn"));

        edit_HLayout_2->addWidget(edit_addBtn);

        edit_removeBtn = new QPushButton(verticalLayoutWidget_2);
        edit_removeBtn->setObjectName(QString::fromUtf8("edit_removeBtn"));

        edit_HLayout_2->addWidget(edit_removeBtn);


        edit_VLayout->addLayout(edit_HLayout_2);

        edit_FLayout_1 = new QFormLayout();
        edit_FLayout_1->setSpacing(6);
        edit_FLayout_1->setObjectName(QString::fromUtf8("edit_FLayout_1"));

        edit_VLayout->addLayout(edit_FLayout_1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        edit_VLayout->addItem(verticalSpacer);

        edit_HLayout_3 = new QHBoxLayout();
        edit_HLayout_3->setSpacing(6);
        edit_HLayout_3->setObjectName(QString::fromUtf8("edit_HLayout_3"));
        edit_runBtn = new QPushButton(verticalLayoutWidget_2);
        edit_runBtn->setObjectName(QString::fromUtf8("edit_runBtn"));

        edit_HLayout_3->addWidget(edit_runBtn);

        edit_outputLabel = new QLabel(verticalLayoutWidget_2);
        edit_outputLabel->setObjectName(QString::fromUtf8("edit_outputLabel"));

        edit_HLayout_3->addWidget(edit_outputLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        edit_HLayout_3->addItem(horizontalSpacer_3);


        edit_VLayout->addLayout(edit_HLayout_3);

        tabWidget->addTab(Edit, QString());
        Connection = new QWidget();
        Connection->setObjectName(QString::fromUtf8("Connection"));
        verticalLayoutWidget_3 = new QWidget(Connection);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(-1, 9, 611, 311));
        conn_VLayout = new QVBoxLayout(verticalLayoutWidget_3);
        conn_VLayout->setSpacing(6);
        conn_VLayout->setContentsMargins(11, 11, 11, 11);
        conn_VLayout->setObjectName(QString::fromUtf8("conn_VLayout"));
        conn_VLayout->setContentsMargins(0, 0, 0, 0);
        conn_HLayout_1 = new QHBoxLayout();
        conn_HLayout_1->setSpacing(6);
        conn_HLayout_1->setObjectName(QString::fromUtf8("conn_HLayout_1"));
        conn_FLayout_1_1 = new QFormLayout();
        conn_FLayout_1_1->setSpacing(6);
        conn_FLayout_1_1->setObjectName(QString::fromUtf8("conn_FLayout_1_1"));
        conn_labelAddress = new QLabel(verticalLayoutWidget_3);
        conn_labelAddress->setObjectName(QString::fromUtf8("conn_labelAddress"));
        conn_labelAddress->setFrameShape(QFrame::NoFrame);

        conn_FLayout_1_1->setWidget(1, QFormLayout::LabelRole, conn_labelAddress);

        conn_editAddress = new QLineEdit(verticalLayoutWidget_3);
        conn_editAddress->setObjectName(QString::fromUtf8("conn_editAddress"));
        conn_editAddress->setMaxLength(32);

        conn_FLayout_1_1->setWidget(1, QFormLayout::FieldRole, conn_editAddress);

        conn_labelPort = new QLabel(verticalLayoutWidget_3);
        conn_labelPort->setObjectName(QString::fromUtf8("conn_labelPort"));

        conn_FLayout_1_1->setWidget(2, QFormLayout::LabelRole, conn_labelPort);

        conn_editPort = new QLineEdit(verticalLayoutWidget_3);
        conn_editPort->setObjectName(QString::fromUtf8("conn_editPort"));
        conn_editPort->setContextMenuPolicy(Qt::NoContextMenu);
        conn_editPort->setMaxLength(4);

        conn_FLayout_1_1->setWidget(2, QFormLayout::FieldRole, conn_editPort);

        conn_btnSaveDatabase = new QPushButton(verticalLayoutWidget_3);
        conn_btnSaveDatabase->setObjectName(QString::fromUtf8("conn_btnSaveDatabase"));

        conn_FLayout_1_1->setWidget(3, QFormLayout::FieldRole, conn_btnSaveDatabase);


        conn_HLayout_1->addLayout(conn_FLayout_1_1);

        conn_FLayout_1_2 = new QFormLayout();
        conn_FLayout_1_2->setSpacing(6);
        conn_FLayout_1_2->setObjectName(QString::fromUtf8("conn_FLayout_1_2"));
        conn_labelPassword = new QLabel(verticalLayoutWidget_3);
        conn_labelPassword->setObjectName(QString::fromUtf8("conn_labelPassword"));

        conn_FLayout_1_2->setWidget(2, QFormLayout::LabelRole, conn_labelPassword);

        conn_editPassword = new QLineEdit(verticalLayoutWidget_3);
        conn_editPassword->setObjectName(QString::fromUtf8("conn_editPassword"));
        conn_editPassword->setMaxLength(128);
        conn_editPassword->setEchoMode(QLineEdit::Password);

        conn_FLayout_1_2->setWidget(2, QFormLayout::FieldRole, conn_editPassword);

        conn_btnSaveUser = new QPushButton(verticalLayoutWidget_3);
        conn_btnSaveUser->setObjectName(QString::fromUtf8("conn_btnSaveUser"));

        conn_FLayout_1_2->setWidget(3, QFormLayout::FieldRole, conn_btnSaveUser);

        conn_editUsername = new QLineEdit(verticalLayoutWidget_3);
        conn_editUsername->setObjectName(QString::fromUtf8("conn_editUsername"));
        conn_editUsername->setMaxLength(128);

        conn_FLayout_1_2->setWidget(1, QFormLayout::FieldRole, conn_editUsername);

        conn_labelUsername = new QLabel(verticalLayoutWidget_3);
        conn_labelUsername->setObjectName(QString::fromUtf8("conn_labelUsername"));

        conn_FLayout_1_2->setWidget(1, QFormLayout::LabelRole, conn_labelUsername);


        conn_HLayout_1->addLayout(conn_FLayout_1_2);


        conn_VLayout->addLayout(conn_HLayout_1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        conn_VLayout->addItem(verticalSpacer_2);

        conn_HLayout_2 = new QHBoxLayout();
        conn_HLayout_2->setSpacing(6);
        conn_HLayout_2->setObjectName(QString::fromUtf8("conn_HLayout_2"));
        conn_runBtn = new QPushButton(verticalLayoutWidget_3);
        conn_runBtn->setObjectName(QString::fromUtf8("conn_runBtn"));

        conn_HLayout_2->addWidget(conn_runBtn);

        conn_outputLabel = new QLabel(verticalLayoutWidget_3);
        conn_outputLabel->setObjectName(QString::fromUtf8("conn_outputLabel"));

        conn_HLayout_2->addWidget(conn_outputLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        conn_HLayout_2->addItem(horizontalSpacer);


        conn_VLayout->addLayout(conn_HLayout_2);

        tabWidget->addTab(Connection, QString());
        Permission = new QWidget();
        Permission->setObjectName(QString::fromUtf8("Permission"));
        verticalLayoutWidget_4 = new QWidget(Permission);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(-1, 9, 611, 311));
        perm_VLayout = new QVBoxLayout(verticalLayoutWidget_4);
        perm_VLayout->setSpacing(6);
        perm_VLayout->setContentsMargins(11, 11, 11, 11);
        perm_VLayout->setObjectName(QString::fromUtf8("perm_VLayout"));
        perm_VLayout->setContentsMargins(0, 0, 0, 0);
        perm_HLayout_1 = new QHBoxLayout();
        perm_HLayout_1->setSpacing(6);
        perm_HLayout_1->setObjectName(QString::fromUtf8("perm_HLayout_1"));
        perm_permTree = new QTreeView(verticalLayoutWidget_4);
        perm_permTree->setObjectName(QString::fromUtf8("perm_permTree"));

        perm_HLayout_1->addWidget(perm_permTree);

        perm_FLayout_1_2 = new QFormLayout();
        perm_FLayout_1_2->setSpacing(6);
        perm_FLayout_1_2->setObjectName(QString::fromUtf8("perm_FLayout_1_2"));

        perm_HLayout_1->addLayout(perm_FLayout_1_2);


        perm_VLayout->addLayout(perm_HLayout_1);

        perm_HLayout_2 = new QHBoxLayout();
        perm_HLayout_2->setSpacing(6);
        perm_HLayout_2->setObjectName(QString::fromUtf8("perm_HLayout_2"));
        perm_refreshBtn = new QPushButton(verticalLayoutWidget_4);
        perm_refreshBtn->setObjectName(QString::fromUtf8("perm_refreshBtn"));

        perm_HLayout_2->addWidget(perm_refreshBtn);

        perm_outputLabel = new QLabel(verticalLayoutWidget_4);
        perm_outputLabel->setObjectName(QString::fromUtf8("perm_outputLabel"));

        perm_HLayout_2->addWidget(perm_outputLabel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        perm_HLayout_2->addItem(horizontalSpacer_4);


        perm_VLayout->addLayout(perm_HLayout_2);

        tabWidget->addTab(Permission, QString());
        QtSquidClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtSquidClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 632, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuEdition = new QMenu(menuBar);
        menuEdition->setObjectName(QString::fromUtf8("menuEdition"));
        menuOutils = new QMenu(menuBar);
        menuOutils->setObjectName(QString::fromUtf8("menuOutils"));
        menuOptions = new QMenu(menuOutils);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        menuRaccourcis = new QMenu(menuBar);
        menuRaccourcis->setObjectName(QString::fromUtf8("menuRaccourcis"));
        menuAide = new QMenu(menuBar);
        menuAide->setObjectName(QString::fromUtf8("menuAide"));
        QtSquidClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtSquidClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtSquidClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtSquidClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtSquidClass->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuEdition->menuAction());
        menuBar->addAction(menuOutils->menuAction());
        menuBar->addAction(menuRaccourcis->menuAction());
        menuBar->addAction(menuAide->menuAction());
        menuOutils->addAction(menuOptions->menuAction());
        menuOptions->addAction(actionStyleSheet);

        retranslateUi(QtSquidClass);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(QtSquidClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtSquidClass)
    {
        QtSquidClass->setWindowTitle(QApplication::translate("QtSquidClass", "QtSquid", nullptr));
        actionStyle->setText(QApplication::translate("QtSquidClass", "Options", nullptr));
        actionStyleSheet->setText(QApplication::translate("QtSquidClass", "Style", nullptr));
        search_scanBtn->setText(QApplication::translate("QtSquidClass", "Scan", nullptr));
        search_runBtn->setText(QApplication::translate("QtSquidClass", "Select", nullptr));
        search_outputLabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Search), QApplication::translate("QtSquidClass", "Search", nullptr));
        edit_addBtn->setText(QApplication::translate("QtSquidClass", "Add", nullptr));
        edit_removeBtn->setText(QApplication::translate("QtSquidClass", "Remove", nullptr));
        edit_runBtn->setText(QApplication::translate("QtSquidClass", "Run", nullptr));
        edit_outputLabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Edit), QApplication::translate("QtSquidClass", "Edit", nullptr));
        conn_labelAddress->setText(QApplication::translate("QtSquidClass", "Address", nullptr));
        conn_labelPort->setText(QApplication::translate("QtSquidClass", "Port", nullptr));
        conn_btnSaveDatabase->setText(QApplication::translate("QtSquidClass", "Save", nullptr));
        conn_labelPassword->setText(QApplication::translate("QtSquidClass", "Password", nullptr));
        conn_btnSaveUser->setText(QApplication::translate("QtSquidClass", "Save", nullptr));
        conn_labelUsername->setText(QApplication::translate("QtSquidClass", "Username", nullptr));
        conn_runBtn->setText(QApplication::translate("QtSquidClass", "Connect", nullptr));
        conn_outputLabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Connection), QApplication::translate("QtSquidClass", "Connection", nullptr));
        perm_refreshBtn->setText(QApplication::translate("QtSquidClass", "Refresh", nullptr));
        perm_outputLabel->setText(QApplication::translate("QtSquidClass", "text", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Permission), QApplication::translate("QtSquidClass", "Permission", nullptr));
        menuFichier->setTitle(QApplication::translate("QtSquidClass", "Fichier", nullptr));
        menuEdition->setTitle(QApplication::translate("QtSquidClass", "Edition", nullptr));
        menuOutils->setTitle(QApplication::translate("QtSquidClass", "Outils", nullptr));
        menuOptions->setTitle(QApplication::translate("QtSquidClass", "Options", nullptr));
        menuRaccourcis->setTitle(QApplication::translate("QtSquidClass", "Raccourcis", nullptr));
        menuAide->setTitle(QApplication::translate("QtSquidClass", "Aide", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtSquidClass: public Ui_QtSquidClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTSQUID_H
