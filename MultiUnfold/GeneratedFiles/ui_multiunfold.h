/********************************************************************************
** Form generated from reading UI file 'multiunfold.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIUNFOLD_H
#define UI_MULTIUNFOLD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MultiUnfoldClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *spnInput;
    QSpinBox *spnNHiden;
    QSpinBox *spnSHiden;
    QSpinBox *spnOutput;
    QLineEdit *lineEdit;
    QPushButton *pbTrain;
    QPushButton *pbExecute;
    QCustomPlot *qcpOutput;
    QCustomPlot *qcpError;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MultiUnfoldClass)
    {
        if (MultiUnfoldClass->objectName().isEmpty())
            MultiUnfoldClass->setObjectName(QStringLiteral("MultiUnfoldClass"));
        MultiUnfoldClass->resize(600, 658);
        centralWidget = new QWidget(MultiUnfoldClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 13));
        label->setMaximumSize(QSize(16777215, 13));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 13));
        label_2->setMaximumSize(QSize(16777215, 13));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 13));
        label_3->setMaximumSize(QSize(16777215, 13));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(0, 13));
        label_4->setMaximumSize(QSize(16777215, 13));

        gridLayout->addWidget(label_4, 0, 3, 1, 1);

        spnInput = new QSpinBox(centralWidget);
        spnInput->setObjectName(QStringLiteral("spnInput"));
        spnInput->setMaximumSize(QSize(16777215, 20));
        spnInput->setMinimum(1);
        spnInput->setMaximum(5);

        gridLayout->addWidget(spnInput, 1, 0, 1, 1);

        spnNHiden = new QSpinBox(centralWidget);
        spnNHiden->setObjectName(QStringLiteral("spnNHiden"));
        spnNHiden->setMaximumSize(QSize(16777215, 20));
        spnNHiden->setMinimum(1);
        spnNHiden->setMaximum(5);
        spnNHiden->setSingleStep(1);
        spnNHiden->setValue(2);

        gridLayout->addWidget(spnNHiden, 1, 1, 1, 1);

        spnSHiden = new QSpinBox(centralWidget);
        spnSHiden->setObjectName(QStringLiteral("spnSHiden"));
        spnSHiden->setMaximumSize(QSize(16777215, 20));
        spnSHiden->setMinimum(1);
        spnSHiden->setMaximum(20);
        spnSHiden->setValue(4);

        gridLayout->addWidget(spnSHiden, 1, 2, 1, 1);

        spnOutput = new QSpinBox(centralWidget);
        spnOutput->setObjectName(QStringLiteral("spnOutput"));
        spnOutput->setMaximumSize(QSize(16777215, 20));
        spnOutput->setMinimum(1);
        spnOutput->setMaximum(20);
        spnOutput->setValue(1);

        gridLayout->addWidget(spnOutput, 1, 3, 1, 1);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 2, 0, 1, 2);

        pbTrain = new QPushButton(centralWidget);
        pbTrain->setObjectName(QStringLiteral("pbTrain"));

        gridLayout->addWidget(pbTrain, 2, 2, 1, 1);

        pbExecute = new QPushButton(centralWidget);
        pbExecute->setObjectName(QStringLiteral("pbExecute"));

        gridLayout->addWidget(pbExecute, 2, 3, 1, 1);

        qcpOutput = new QCustomPlot(centralWidget);
        qcpOutput->setObjectName(QStringLiteral("qcpOutput"));

        gridLayout->addWidget(qcpOutput, 3, 0, 1, 4);

        qcpError = new QCustomPlot(centralWidget);
        qcpError->setObjectName(QStringLiteral("qcpError"));

        gridLayout->addWidget(qcpError, 4, 0, 1, 4);

        MultiUnfoldClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MultiUnfoldClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        MultiUnfoldClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MultiUnfoldClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MultiUnfoldClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MultiUnfoldClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MultiUnfoldClass->setStatusBar(statusBar);

        retranslateUi(MultiUnfoldClass);

        QMetaObject::connectSlotsByName(MultiUnfoldClass);
    } // setupUi

    void retranslateUi(QMainWindow *MultiUnfoldClass)
    {
        MultiUnfoldClass->setWindowTitle(QApplication::translate("MultiUnfoldClass", "MultiUnfold", 0));
        label->setText(QApplication::translate("MultiUnfoldClass", "Size of Input", 0));
        label_2->setText(QApplication::translate("MultiUnfoldClass", "No of Hidden", 0));
        label_3->setText(QApplication::translate("MultiUnfoldClass", "Size of HIdden", 0));
        label_4->setText(QApplication::translate("MultiUnfoldClass", "Size of Output", 0));
        pbTrain->setText(QApplication::translate("MultiUnfoldClass", "TrainerFile", 0));
        pbExecute->setText(QApplication::translate("MultiUnfoldClass", "Execute", 0));
    } // retranslateUi

};

namespace Ui {
    class MultiUnfoldClass: public Ui_MultiUnfoldClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIUNFOLD_H
