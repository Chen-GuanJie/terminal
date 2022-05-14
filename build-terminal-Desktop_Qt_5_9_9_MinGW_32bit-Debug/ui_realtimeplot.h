/********************************************************************************
** Form generated from reading UI file 'realtimeplot.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REALTIMEPLOT_H
#define UI_REALTIMEPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_realtimeplot
{
public:
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *realtimeplot)
    {
        if (realtimeplot->objectName().isEmpty())
            realtimeplot->setObjectName(QStringLiteral("realtimeplot"));
        realtimeplot->resize(469, 343);
        verticalLayout = new QVBoxLayout(realtimeplot);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        retranslateUi(realtimeplot);

        QMetaObject::connectSlotsByName(realtimeplot);
    } // setupUi

    void retranslateUi(QWidget *realtimeplot)
    {
        realtimeplot->setWindowTitle(QApplication::translate("realtimeplot", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class realtimeplot: public Ui_realtimeplot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REALTIMEPLOT_H
