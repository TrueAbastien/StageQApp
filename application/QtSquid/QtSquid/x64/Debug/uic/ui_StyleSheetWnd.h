/********************************************************************************
** Form generated from reading UI file 'StyleSheetWnd.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STYLESHEETWND_H
#define UI_STYLESHEETWND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *style_VLayout;
    QComboBox *style_dropdownMenu;
    QSpacerItem *verticalSpacer_2;
    QFormLayout *style_FLayout_1;
    QPushButton *style_btnTest;
    QLabel *style_labelTest;
    QCheckBox *style_checkboxTest;
    QLineEdit *style_editTest;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *style_HLayout_2;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(267, 249);
        verticalLayoutWidget = new QWidget(Dialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 241, 221));
        style_VLayout = new QVBoxLayout(verticalLayoutWidget);
        style_VLayout->setObjectName(QString::fromUtf8("style_VLayout"));
        style_VLayout->setContentsMargins(0, 0, 0, 0);
        style_dropdownMenu = new QComboBox(verticalLayoutWidget);
        style_dropdownMenu->setObjectName(QString::fromUtf8("style_dropdownMenu"));

        style_VLayout->addWidget(style_dropdownMenu);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        style_VLayout->addItem(verticalSpacer_2);

        style_FLayout_1 = new QFormLayout();
        style_FLayout_1->setObjectName(QString::fromUtf8("style_FLayout_1"));
        style_btnTest = new QPushButton(verticalLayoutWidget);
        style_btnTest->setObjectName(QString::fromUtf8("style_btnTest"));

        style_FLayout_1->setWidget(0, QFormLayout::LabelRole, style_btnTest);

        style_labelTest = new QLabel(verticalLayoutWidget);
        style_labelTest->setObjectName(QString::fromUtf8("style_labelTest"));

        style_FLayout_1->setWidget(0, QFormLayout::FieldRole, style_labelTest);

        style_checkboxTest = new QCheckBox(verticalLayoutWidget);
        style_checkboxTest->setObjectName(QString::fromUtf8("style_checkboxTest"));

        style_FLayout_1->setWidget(1, QFormLayout::LabelRole, style_checkboxTest);

        style_editTest = new QLineEdit(verticalLayoutWidget);
        style_editTest->setObjectName(QString::fromUtf8("style_editTest"));

        style_FLayout_1->setWidget(1, QFormLayout::FieldRole, style_editTest);


        style_VLayout->addLayout(style_FLayout_1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        style_VLayout->addItem(verticalSpacer);

        style_HLayout_2 = new QHBoxLayout();
        style_HLayout_2->setSpacing(6);
        style_HLayout_2->setObjectName(QString::fromUtf8("style_HLayout_2"));
        style_HLayout_2->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        style_HLayout_2->addItem(spacerItem);

        okButton = new QPushButton(verticalLayoutWidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        style_HLayout_2->addWidget(okButton);

        cancelButton = new QPushButton(verticalLayoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        style_HLayout_2->addWidget(cancelButton);


        style_VLayout->addLayout(style_HLayout_2);


        retranslateUi(Dialog);
        QObject::connect(okButton, SIGNAL(clicked()), Dialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        style_dropdownMenu->setCurrentText(QString());
        style_btnTest->setText(QApplication::translate("Dialog", "This is a Button", nullptr));
        style_labelTest->setText(QApplication::translate("Dialog", "This is a Label", nullptr));
        style_checkboxTest->setText(QApplication::translate("Dialog", "This is a CheckBox", nullptr));
        style_editTest->setInputMask(QString());
        style_editTest->setText(QApplication::translate("Dialog", "This is a LineEdit", nullptr));
        okButton->setText(QApplication::translate("Dialog", "OK", nullptr));
        cancelButton->setText(QApplication::translate("Dialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STYLESHEETWND_H
