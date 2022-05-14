/********************************************************************************
** Form generated from reading UI file 'single.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINGLE_H
#define UI_SINGLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <realtimeplot.h>

QT_BEGIN_NAMESPACE

class Ui_single
{
public:
    QVBoxLayout *verticalLayout;
    realtimeplot *customplot;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *singlelineEdit;
    QPushButton *singlebuttuon;
    QPushButton *singlebuttuon_2;
    QSlider *horizontalSlider;

    void setupUi(QWidget *single)
    {
        if (single->objectName().isEmpty())
            single->setObjectName(QStringLiteral("single"));
        single->resize(400, 300);
        verticalLayout = new QVBoxLayout(single);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        customplot = new realtimeplot(single);
        customplot->setObjectName(QStringLiteral("customplot"));

        verticalLayout->addWidget(customplot);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(single);
        label->setObjectName(QStringLiteral("label"));
        label->setScaledContents(false);

        horizontalLayout->addWidget(label);

        singlelineEdit = new QLineEdit(single);
        singlelineEdit->setObjectName(QStringLiteral("singlelineEdit"));

        horizontalLayout->addWidget(singlelineEdit);

        singlebuttuon = new QPushButton(single);
        singlebuttuon->setObjectName(QStringLiteral("singlebuttuon"));

        horizontalLayout->addWidget(singlebuttuon);

        singlebuttuon_2 = new QPushButton(single);
        singlebuttuon_2->setObjectName(QStringLiteral("singlebuttuon_2"));

        horizontalLayout->addWidget(singlebuttuon_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalSlider = new QSlider(single);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMaximum(1000);
        horizontalSlider->setValue(500);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setInvertedControls(false);
        horizontalSlider->setTickPosition(QSlider::NoTicks);
        horizontalSlider->setTickInterval(10);

        verticalLayout->addWidget(horizontalSlider);


        retranslateUi(single);
        QObject::connect(singlebuttuon, SIGNAL(clicked()), singlelineEdit, SLOT(copy()));

        QMetaObject::connectSlotsByName(single);
    } // setupUi

    void retranslateUi(QWidget *single)
    {
        single->setWindowTitle(QApplication::translate("single", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("single", "ID: \350\276\223\345\205\245\345\200\274:", Q_NULLPTR));
        singlelineEdit->setText(QApplication::translate("single", "500", Q_NULLPTR));
        singlebuttuon->setText(QApplication::translate("single", "\345\217\221\351\200\201", Q_NULLPTR));
        singlebuttuon_2->setText(QApplication::translate("single", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class single: public Ui_single {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINGLE_H
