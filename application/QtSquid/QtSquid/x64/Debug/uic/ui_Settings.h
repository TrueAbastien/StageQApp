/********************************************************************************
** Form generated from reading UI file 'Settings.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *VLayout_Container;
    QTabWidget *pagination;
    QWidget *Stylesheet;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *style_VLayout_1;
    QComboBox *style_dropdownMenu;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *style_GBox_1;
    QFormLayout *style_FLayout_1;
    QPushButton *style_btnTest;
    QLabel *style_labelTest;
    QCheckBox *style_checkboxTest;
    QLineEdit *style_editTest;
    QSpacerItem *verticalSpacer;
    QWidget *unknown;
    QHBoxLayout *HLayout_0;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(267, 423);
        verticalLayoutWidget = new QWidget(Settings);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 248, 391));
        VLayout_Container = new QVBoxLayout(verticalLayoutWidget);
        VLayout_Container->setObjectName(QString::fromUtf8("VLayout_Container"));
        VLayout_Container->setContentsMargins(0, 0, 0, 0);
        pagination = new QTabWidget(verticalLayoutWidget);
        pagination->setObjectName(QString::fromUtf8("pagination"));
        Stylesheet = new QWidget();
        Stylesheet->setObjectName(QString::fromUtf8("Stylesheet"));
        verticalLayoutWidget_2 = new QWidget(Stylesheet);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, 0, 248, 311));
        style_VLayout_1 = new QVBoxLayout(verticalLayoutWidget_2);
        style_VLayout_1->setObjectName(QString::fromUtf8("style_VLayout_1"));
        style_VLayout_1->setContentsMargins(0, 0, 0, 0);
        style_dropdownMenu = new QComboBox(verticalLayoutWidget_2);
        style_dropdownMenu->setObjectName(QString::fromUtf8("style_dropdownMenu"));

        style_VLayout_1->addWidget(style_dropdownMenu);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        style_VLayout_1->addItem(verticalSpacer_2);

        style_GBox_1 = new QGroupBox(verticalLayoutWidget_2);
        style_GBox_1->setObjectName(QString::fromUtf8("style_GBox_1"));
        style_GBox_1->setFlat(false);
        style_FLayout_1 = new QFormLayout(style_GBox_1);
        style_FLayout_1->setObjectName(QString::fromUtf8("style_FLayout_1"));
        style_btnTest = new QPushButton(style_GBox_1);
        style_btnTest->setObjectName(QString::fromUtf8("style_btnTest"));

        style_FLayout_1->setWidget(1, QFormLayout::LabelRole, style_btnTest);

        style_labelTest = new QLabel(style_GBox_1);
        style_labelTest->setObjectName(QString::fromUtf8("style_labelTest"));

        style_FLayout_1->setWidget(1, QFormLayout::FieldRole, style_labelTest);

        style_checkboxTest = new QCheckBox(style_GBox_1);
        style_checkboxTest->setObjectName(QString::fromUtf8("style_checkboxTest"));

        style_FLayout_1->setWidget(2, QFormLayout::LabelRole, style_checkboxTest);

        style_editTest = new QLineEdit(style_GBox_1);
        style_editTest->setObjectName(QString::fromUtf8("style_editTest"));

        style_FLayout_1->setWidget(2, QFormLayout::FieldRole, style_editTest);


        style_VLayout_1->addWidget(style_GBox_1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        style_VLayout_1->addItem(verticalSpacer);

        pagination->addTab(Stylesheet, QString());
        unknown = new QWidget();
        unknown->setObjectName(QString::fromUtf8("unknown"));
        pagination->addTab(unknown, QString());

        VLayout_Container->addWidget(pagination);

        HLayout_0 = new QHBoxLayout();
        HLayout_0->setSpacing(6);
        HLayout_0->setObjectName(QString::fromUtf8("HLayout_0"));
        HLayout_0->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        HLayout_0->addItem(spacerItem);

        okButton = new QPushButton(verticalLayoutWidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        HLayout_0->addWidget(okButton);

        cancelButton = new QPushButton(verticalLayoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        HLayout_0->addWidget(cancelButton);


        VLayout_Container->addLayout(HLayout_0);


        retranslateUi(Settings);
        QObject::connect(cancelButton, SIGNAL(clicked()), Settings, SLOT(reject()));

        pagination->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Settings", nullptr));
        style_dropdownMenu->setCurrentText(QString());
        style_btnTest->setText(QApplication::translate("Settings", "This is a Button", nullptr));
        style_labelTest->setText(QApplication::translate("Settings", "This is a Label", nullptr));
        style_checkboxTest->setText(QApplication::translate("Settings", "This is a CheckBox", nullptr));
        style_editTest->setInputMask(QString());
        style_editTest->setText(QApplication::translate("Settings", "This is a LineEdit", nullptr));
        pagination->setTabText(pagination->indexOf(Stylesheet), QApplication::translate("Settings", "Stylesheet", nullptr));
        pagination->setTabText(pagination->indexOf(unknown), QApplication::translate("Settings", "...", nullptr));
        okButton->setText(QApplication::translate("Settings", "Ok", nullptr));
        cancelButton->setText(QApplication::translate("Settings", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
