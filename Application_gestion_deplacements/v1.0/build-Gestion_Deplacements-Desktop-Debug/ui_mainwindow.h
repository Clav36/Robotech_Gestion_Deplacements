/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qviewtable.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QSpinBox *spinBox;
    QSpacerItem *verticalSpacer;
    QPushButton *BtroisD;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QViewTable *QTable;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *qPosLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *AddGroupe;
    QPushButton *AddPoint;
    QPushButton *Supprimer;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter_3;
    QListWidget *qListEtape;
    QTableWidget *qInfosEtape;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1183, 839);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        spinBox = new QSpinBox(frame);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        verticalLayout_2->addWidget(spinBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        BtroisD = new QPushButton(frame);
        BtroisD->setObjectName(QStringLiteral("BtroisD"));

        verticalLayout_2->addWidget(BtroisD);


        horizontalLayout->addWidget(frame);

        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        QTable = new QViewTable(splitter);
        QTable->setObjectName(QStringLiteral("QTable"));
        QTable->setMinimumSize(QSize(950, 700));
        QTable->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        QTable->setMouseTracking(true);
        QTable->setDragMode(QGraphicsView::NoDrag);
        splitter->addWidget(QTable);
        frame_3 = new QFrame(splitter);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        qPosLabel = new QLabel(frame_3);
        qPosLabel->setObjectName(QStringLiteral("qPosLabel"));

        horizontalLayout_2->addWidget(qPosLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        AddGroupe = new QPushButton(frame_3);
        AddGroupe->setObjectName(QStringLiteral("AddGroupe"));
        AddGroupe->setMinimumSize(QSize(0, 35));

        horizontalLayout_2->addWidget(AddGroupe);

        AddPoint = new QPushButton(frame_3);
        AddPoint->setObjectName(QStringLiteral("AddPoint"));
        AddPoint->setMinimumSize(QSize(0, 35));

        horizontalLayout_2->addWidget(AddPoint);

        Supprimer = new QPushButton(frame_3);
        Supprimer->setObjectName(QStringLiteral("Supprimer"));
        Supprimer->setMinimumSize(QSize(110, 35));

        horizontalLayout_2->addWidget(Supprimer);

        splitter->addWidget(frame_3);
        splitter_2->addWidget(splitter);
        frame_2 = new QFrame(splitter_2);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitter_3 = new QSplitter(frame_2);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        qListEtape = new QListWidget(splitter_3);
        qListEtape->setObjectName(QStringLiteral("qListEtape"));
        qListEtape->setDragDropMode(QAbstractItemView::InternalMove);
        splitter_3->addWidget(qListEtape);
        qInfosEtape = new QTableWidget(splitter_3);
        if (qInfosEtape->columnCount() < 2)
            qInfosEtape->setColumnCount(2);
        if (qInfosEtape->rowCount() < 1)
            qInfosEtape->setRowCount(1);
        qInfosEtape->setObjectName(QStringLiteral("qInfosEtape"));
        qInfosEtape->setShowGrid(true);
        qInfosEtape->setGridStyle(Qt::SolidLine);
        qInfosEtape->setWordWrap(true);
        qInfosEtape->setRowCount(1);
        qInfosEtape->setColumnCount(2);
        splitter_3->addWidget(qInfosEtape);
        qInfosEtape->horizontalHeader()->setVisible(false);
        qInfosEtape->horizontalHeader()->setHighlightSections(true);
        qInfosEtape->verticalHeader()->setVisible(false);
        qInfosEtape->verticalHeader()->setDefaultSectionSize(20);

        verticalLayout->addWidget(splitter_3);

        splitter_2->addWidget(frame_2);

        horizontalLayout->addWidget(splitter_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1183, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        BtroisD->setText(QApplication::translate("MainWindow", "3D", 0));
        qPosLabel->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        AddGroupe->setText(QApplication::translate("MainWindow", "Ajouter groupe", 0));
        AddPoint->setText(QApplication::translate("MainWindow", "Ajouter point", 0));
        Supprimer->setText(QApplication::translate("MainWindow", "Supprimer", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
