/********************************************************************************
** Form generated from reading UI file 'Creation.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATION_H
#define UI_CREATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Creation
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *VLayout_0;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QSpacerItem *spacerItem;
    QToolBox *pagination;
    QWidget *Item;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *VLayout_1;
    QLabel *item_outputLabel;
    QSpacerItem *verticalSpacer;
    QFormLayout *FLayout_1_1;
    QLabel *item_form_quantityLabel;
    QSpinBox *item_form_quantitySpinbox;
    QLabel *item_form_nameLabel;
    QLineEdit *item_form_nameEdit;
    QLabel *item_form_barcodeLabel;
    QLineEdit *item_form_barcodeEdit;
    QLabel *item_form_manufacturerLabel;
    QLineEdit *item_form_manufacturerEdit;
    QLabel *item_form_providerLabel;
    QLineEdit *item_form_providerEdit;
    QLabel *item_form_descriptionLabel;
    QTextEdit *item_form_descriptionEdit;
    QLabel *item_form_restockLabel;
    QSpinBox *item_form_restockSpinbox;
    QLabel *item_form_categoryLabel;
    QComboBox *item_form_categoryCB;
    QLabel *item_form_contactLabel;
    QComboBox *item_form_contactCB;
    QWidget *Configuration;

    void setupUi(QDialog *Creation)
    {
        if (Creation->objectName().isEmpty())
            Creation->setObjectName(QString::fromUtf8("Creation"));
        Creation->resize(419, 629);
        layoutWidget = new QWidget(Creation);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(310, 20, 95, 106));
        VLayout_0 = new QVBoxLayout(layoutWidget);
        VLayout_0->setSpacing(6);
        VLayout_0->setObjectName(QString::fromUtf8("VLayout_0"));
        VLayout_0->setContentsMargins(0, 0, 0, 0);
        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        VLayout_0->addWidget(okButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        VLayout_0->addWidget(cancelButton);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        VLayout_0->addItem(spacerItem);

        pagination = new QToolBox(Creation);
        pagination->setObjectName(QString::fromUtf8("pagination"));
        pagination->setGeometry(QRect(10, 10, 291, 601));
        Item = new QWidget();
        Item->setObjectName(QString::fromUtf8("Item"));
        Item->setGeometry(QRect(0, 0, 291, 539));
        verticalLayoutWidget = new QWidget(Item);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 261, 526));
        VLayout_1 = new QVBoxLayout(verticalLayoutWidget);
        VLayout_1->setObjectName(QString::fromUtf8("VLayout_1"));
        VLayout_1->setContentsMargins(0, 0, 0, 0);
        item_outputLabel = new QLabel(verticalLayoutWidget);
        item_outputLabel->setObjectName(QString::fromUtf8("item_outputLabel"));

        VLayout_1->addWidget(item_outputLabel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        VLayout_1->addItem(verticalSpacer);

        FLayout_1_1 = new QFormLayout();
        FLayout_1_1->setObjectName(QString::fromUtf8("FLayout_1_1"));
        item_form_quantityLabel = new QLabel(verticalLayoutWidget);
        item_form_quantityLabel->setObjectName(QString::fromUtf8("item_form_quantityLabel"));

        FLayout_1_1->setWidget(1, QFormLayout::LabelRole, item_form_quantityLabel);

        item_form_quantitySpinbox = new QSpinBox(verticalLayoutWidget);
        item_form_quantitySpinbox->setObjectName(QString::fromUtf8("item_form_quantitySpinbox"));

        FLayout_1_1->setWidget(1, QFormLayout::FieldRole, item_form_quantitySpinbox);

        item_form_nameLabel = new QLabel(verticalLayoutWidget);
        item_form_nameLabel->setObjectName(QString::fromUtf8("item_form_nameLabel"));

        FLayout_1_1->setWidget(2, QFormLayout::LabelRole, item_form_nameLabel);

        item_form_nameEdit = new QLineEdit(verticalLayoutWidget);
        item_form_nameEdit->setObjectName(QString::fromUtf8("item_form_nameEdit"));

        FLayout_1_1->setWidget(2, QFormLayout::FieldRole, item_form_nameEdit);

        item_form_barcodeLabel = new QLabel(verticalLayoutWidget);
        item_form_barcodeLabel->setObjectName(QString::fromUtf8("item_form_barcodeLabel"));

        FLayout_1_1->setWidget(3, QFormLayout::LabelRole, item_form_barcodeLabel);

        item_form_barcodeEdit = new QLineEdit(verticalLayoutWidget);
        item_form_barcodeEdit->setObjectName(QString::fromUtf8("item_form_barcodeEdit"));

        FLayout_1_1->setWidget(3, QFormLayout::FieldRole, item_form_barcodeEdit);

        item_form_manufacturerLabel = new QLabel(verticalLayoutWidget);
        item_form_manufacturerLabel->setObjectName(QString::fromUtf8("item_form_manufacturerLabel"));

        FLayout_1_1->setWidget(4, QFormLayout::LabelRole, item_form_manufacturerLabel);

        item_form_manufacturerEdit = new QLineEdit(verticalLayoutWidget);
        item_form_manufacturerEdit->setObjectName(QString::fromUtf8("item_form_manufacturerEdit"));

        FLayout_1_1->setWidget(4, QFormLayout::FieldRole, item_form_manufacturerEdit);

        item_form_providerLabel = new QLabel(verticalLayoutWidget);
        item_form_providerLabel->setObjectName(QString::fromUtf8("item_form_providerLabel"));

        FLayout_1_1->setWidget(5, QFormLayout::LabelRole, item_form_providerLabel);

        item_form_providerEdit = new QLineEdit(verticalLayoutWidget);
        item_form_providerEdit->setObjectName(QString::fromUtf8("item_form_providerEdit"));

        FLayout_1_1->setWidget(5, QFormLayout::FieldRole, item_form_providerEdit);

        item_form_descriptionLabel = new QLabel(verticalLayoutWidget);
        item_form_descriptionLabel->setObjectName(QString::fromUtf8("item_form_descriptionLabel"));

        FLayout_1_1->setWidget(6, QFormLayout::LabelRole, item_form_descriptionLabel);

        item_form_descriptionEdit = new QTextEdit(verticalLayoutWidget);
        item_form_descriptionEdit->setObjectName(QString::fromUtf8("item_form_descriptionEdit"));

        FLayout_1_1->setWidget(6, QFormLayout::FieldRole, item_form_descriptionEdit);

        item_form_restockLabel = new QLabel(verticalLayoutWidget);
        item_form_restockLabel->setObjectName(QString::fromUtf8("item_form_restockLabel"));

        FLayout_1_1->setWidget(7, QFormLayout::LabelRole, item_form_restockLabel);

        item_form_restockSpinbox = new QSpinBox(verticalLayoutWidget);
        item_form_restockSpinbox->setObjectName(QString::fromUtf8("item_form_restockSpinbox"));
        item_form_restockSpinbox->setMinimum(1);

        FLayout_1_1->setWidget(7, QFormLayout::FieldRole, item_form_restockSpinbox);

        item_form_categoryLabel = new QLabel(verticalLayoutWidget);
        item_form_categoryLabel->setObjectName(QString::fromUtf8("item_form_categoryLabel"));

        FLayout_1_1->setWidget(8, QFormLayout::LabelRole, item_form_categoryLabel);

        item_form_categoryCB = new QComboBox(verticalLayoutWidget);
        item_form_categoryCB->setObjectName(QString::fromUtf8("item_form_categoryCB"));

        FLayout_1_1->setWidget(8, QFormLayout::FieldRole, item_form_categoryCB);

        item_form_contactLabel = new QLabel(verticalLayoutWidget);
        item_form_contactLabel->setObjectName(QString::fromUtf8("item_form_contactLabel"));

        FLayout_1_1->setWidget(9, QFormLayout::LabelRole, item_form_contactLabel);

        item_form_contactCB = new QComboBox(verticalLayoutWidget);
        item_form_contactCB->setObjectName(QString::fromUtf8("item_form_contactCB"));

        FLayout_1_1->setWidget(9, QFormLayout::FieldRole, item_form_contactCB);


        VLayout_1->addLayout(FLayout_1_1);

        pagination->addItem(Item, QString::fromUtf8("Item"));
        Configuration = new QWidget();
        Configuration->setObjectName(QString::fromUtf8("Configuration"));
        Configuration->setGeometry(QRect(0, 0, 291, 539));
        pagination->addItem(Configuration, QString::fromUtf8("Configuration"));

        retranslateUi(Creation);
        QObject::connect(cancelButton, SIGNAL(clicked()), Creation, SLOT(reject()));

        pagination->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Creation);
    } // setupUi

    void retranslateUi(QDialog *Creation)
    {
        Creation->setWindowTitle(QApplication::translate("Creation", "Creation", nullptr));
        okButton->setText(QApplication::translate("Creation", "OK", nullptr));
        cancelButton->setText(QApplication::translate("Creation", "Cancel", nullptr));
        item_outputLabel->setText(QApplication::translate("Creation", "<html><head/><body><p><span style=\" font-weight:600; color:#c5220d;\"></span></p></body></html>", nullptr));
        item_form_quantityLabel->setText(QApplication::translate("Creation", "Quantity", nullptr));
        item_form_nameLabel->setText(QApplication::translate("Creation", "Name", nullptr));
        item_form_barcodeLabel->setText(QApplication::translate("Creation", "Barcode", nullptr));
        item_form_manufacturerLabel->setText(QApplication::translate("Creation", "Manufacturer", nullptr));
        item_form_providerLabel->setText(QApplication::translate("Creation", "Provider", nullptr));
        item_form_descriptionLabel->setText(QApplication::translate("Creation", "Description", nullptr));
        item_form_restockLabel->setText(QApplication::translate("Creation", "Restock", nullptr));
        item_form_categoryLabel->setText(QApplication::translate("Creation", "Category", nullptr));
        item_form_contactLabel->setText(QApplication::translate("Creation", "Contact", nullptr));
        pagination->setItemText(pagination->indexOf(Item), QApplication::translate("Creation", "Item", nullptr));
        pagination->setItemText(pagination->indexOf(Configuration), QApplication::translate("Creation", "Configuration", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Creation: public Ui_Creation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATION_H
