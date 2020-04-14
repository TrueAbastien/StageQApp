/********************************************************************************
** Form generated from reading UI file 'ItemCreation.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITEMCREATION_H
#define UI_ITEMCREATION_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ItemCreation
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *VLayout_1;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QSpacerItem *spacerItem;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *VLayout_2;
    QLabel *outputLabel;
    QSpacerItem *verticalSpacer;
    QFormLayout *FLayout_2_1;
    QLabel *form_nameLabel;
    QLabel *form_barcodeLabel;
    QLabel *form_manufacturerLabel;
    QLabel *form_providerLabel;
    QLabel *form_descriptionLabel;
    QLabel *form_restockLabel;
    QLabel *form_categoryLabel;
    QLabel *form_contactLabel;
    QLineEdit *form_nameEdit;
    QLineEdit *form_barcodeEdit;
    QLineEdit *form_manufacturerEdit;
    QLineEdit *form_providerEdit;
    QTextEdit *form_descriptionEdit;
    QSpinBox *form_restockSpinbox;
    QComboBox *form_categoryCB;
    QComboBox *form_contactCB;
    QSpinBox *form_quantitySpinbox;
    QLabel *form_quantityLabel;

    void setupUi(QDialog *ItemCreation)
    {
        if (ItemCreation->objectName().isEmpty())
            ItemCreation->setObjectName(QString::fromUtf8("ItemCreation"));
        ItemCreation->resize(426, 477);
        layoutWidget = new QWidget(ItemCreation);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(300, 20, 95, 106));
        VLayout_1 = new QVBoxLayout(layoutWidget);
        VLayout_1->setSpacing(6);
        VLayout_1->setObjectName(QString::fromUtf8("VLayout_1"));
        VLayout_1->setContentsMargins(0, 0, 0, 0);
        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        VLayout_1->addWidget(okButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        VLayout_1->addWidget(cancelButton);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        VLayout_1->addItem(spacerItem);

        verticalLayoutWidget = new QWidget(ItemCreation);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 10, 261, 451));
        VLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        VLayout_2->setObjectName(QString::fromUtf8("VLayout_2"));
        VLayout_2->setContentsMargins(0, 0, 0, 0);
        outputLabel = new QLabel(verticalLayoutWidget);
        outputLabel->setObjectName(QString::fromUtf8("outputLabel"));

        VLayout_2->addWidget(outputLabel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        VLayout_2->addItem(verticalSpacer);

        FLayout_2_1 = new QFormLayout();
        FLayout_2_1->setObjectName(QString::fromUtf8("FLayout_2_1"));
        form_nameLabel = new QLabel(verticalLayoutWidget);
        form_nameLabel->setObjectName(QString::fromUtf8("form_nameLabel"));

        FLayout_2_1->setWidget(2, QFormLayout::LabelRole, form_nameLabel);

        form_barcodeLabel = new QLabel(verticalLayoutWidget);
        form_barcodeLabel->setObjectName(QString::fromUtf8("form_barcodeLabel"));

        FLayout_2_1->setWidget(3, QFormLayout::LabelRole, form_barcodeLabel);

        form_manufacturerLabel = new QLabel(verticalLayoutWidget);
        form_manufacturerLabel->setObjectName(QString::fromUtf8("form_manufacturerLabel"));

        FLayout_2_1->setWidget(4, QFormLayout::LabelRole, form_manufacturerLabel);

        form_providerLabel = new QLabel(verticalLayoutWidget);
        form_providerLabel->setObjectName(QString::fromUtf8("form_providerLabel"));

        FLayout_2_1->setWidget(5, QFormLayout::LabelRole, form_providerLabel);

        form_descriptionLabel = new QLabel(verticalLayoutWidget);
        form_descriptionLabel->setObjectName(QString::fromUtf8("form_descriptionLabel"));

        FLayout_2_1->setWidget(6, QFormLayout::LabelRole, form_descriptionLabel);

        form_restockLabel = new QLabel(verticalLayoutWidget);
        form_restockLabel->setObjectName(QString::fromUtf8("form_restockLabel"));

        FLayout_2_1->setWidget(7, QFormLayout::LabelRole, form_restockLabel);

        form_categoryLabel = new QLabel(verticalLayoutWidget);
        form_categoryLabel->setObjectName(QString::fromUtf8("form_categoryLabel"));

        FLayout_2_1->setWidget(8, QFormLayout::LabelRole, form_categoryLabel);

        form_contactLabel = new QLabel(verticalLayoutWidget);
        form_contactLabel->setObjectName(QString::fromUtf8("form_contactLabel"));

        FLayout_2_1->setWidget(9, QFormLayout::LabelRole, form_contactLabel);

        form_nameEdit = new QLineEdit(verticalLayoutWidget);
        form_nameEdit->setObjectName(QString::fromUtf8("form_nameEdit"));

        FLayout_2_1->setWidget(2, QFormLayout::FieldRole, form_nameEdit);

        form_barcodeEdit = new QLineEdit(verticalLayoutWidget);
        form_barcodeEdit->setObjectName(QString::fromUtf8("form_barcodeEdit"));

        FLayout_2_1->setWidget(3, QFormLayout::FieldRole, form_barcodeEdit);

        form_manufacturerEdit = new QLineEdit(verticalLayoutWidget);
        form_manufacturerEdit->setObjectName(QString::fromUtf8("form_manufacturerEdit"));

        FLayout_2_1->setWidget(4, QFormLayout::FieldRole, form_manufacturerEdit);

        form_providerEdit = new QLineEdit(verticalLayoutWidget);
        form_providerEdit->setObjectName(QString::fromUtf8("form_providerEdit"));

        FLayout_2_1->setWidget(5, QFormLayout::FieldRole, form_providerEdit);

        form_descriptionEdit = new QTextEdit(verticalLayoutWidget);
        form_descriptionEdit->setObjectName(QString::fromUtf8("form_descriptionEdit"));

        FLayout_2_1->setWidget(6, QFormLayout::FieldRole, form_descriptionEdit);

        form_restockSpinbox = new QSpinBox(verticalLayoutWidget);
        form_restockSpinbox->setObjectName(QString::fromUtf8("form_restockSpinbox"));
        form_restockSpinbox->setMinimum(1);

        FLayout_2_1->setWidget(7, QFormLayout::FieldRole, form_restockSpinbox);

        form_categoryCB = new QComboBox(verticalLayoutWidget);
        form_categoryCB->setObjectName(QString::fromUtf8("form_categoryCB"));

        FLayout_2_1->setWidget(8, QFormLayout::FieldRole, form_categoryCB);

        form_contactCB = new QComboBox(verticalLayoutWidget);
        form_contactCB->setObjectName(QString::fromUtf8("form_contactCB"));

        FLayout_2_1->setWidget(9, QFormLayout::FieldRole, form_contactCB);

        form_quantitySpinbox = new QSpinBox(verticalLayoutWidget);
        form_quantitySpinbox->setObjectName(QString::fromUtf8("form_quantitySpinbox"));

        FLayout_2_1->setWidget(1, QFormLayout::FieldRole, form_quantitySpinbox);

        form_quantityLabel = new QLabel(verticalLayoutWidget);
        form_quantityLabel->setObjectName(QString::fromUtf8("form_quantityLabel"));

        FLayout_2_1->setWidget(1, QFormLayout::LabelRole, form_quantityLabel);


        VLayout_2->addLayout(FLayout_2_1);


        retranslateUi(ItemCreation);
        QObject::connect(cancelButton, SIGNAL(clicked()), ItemCreation, SLOT(reject()));

        QMetaObject::connectSlotsByName(ItemCreation);
    } // setupUi

    void retranslateUi(QDialog *ItemCreation)
    {
        ItemCreation->setWindowTitle(QApplication::translate("ItemCreation", "ItemCreation", nullptr));
        okButton->setText(QApplication::translate("ItemCreation", "OK", nullptr));
        cancelButton->setText(QApplication::translate("ItemCreation", "Cancel", nullptr));
        outputLabel->setText(QApplication::translate("ItemCreation", "<html><head/><body><p><span style=\" font-weight:600; color:#c5220d;\"></span></p></body></html>", nullptr));
        form_nameLabel->setText(QApplication::translate("ItemCreation", "Name", nullptr));
        form_barcodeLabel->setText(QApplication::translate("ItemCreation", "Barcode", nullptr));
        form_manufacturerLabel->setText(QApplication::translate("ItemCreation", "Manufacturer", nullptr));
        form_providerLabel->setText(QApplication::translate("ItemCreation", "Provider", nullptr));
        form_descriptionLabel->setText(QApplication::translate("ItemCreation", "Description", nullptr));
        form_restockLabel->setText(QApplication::translate("ItemCreation", "Restock", nullptr));
        form_categoryLabel->setText(QApplication::translate("ItemCreation", "Category", nullptr));
        form_contactLabel->setText(QApplication::translate("ItemCreation", "Contact", nullptr));
        form_quantityLabel->setText(QApplication::translate("ItemCreation", "Quantity", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ItemCreation: public Ui_ItemCreation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITEMCREATION_H
