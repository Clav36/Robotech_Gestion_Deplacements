/********************************************************************************
** Form generated from reading UI file '3D.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_3D_H
#define UI_3D_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SecWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_1;
    QVBoxLayout *verticalLayout;
    QFrame *frame_3;
    QFrame *frame_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SecWindow)
    {
        if (SecWindow->objectName().isEmpty())
            SecWindow->setObjectName(QStringLiteral("SecWindow"));
        SecWindow->resize(1155, 761);
        centralwidget = new QWidget(SecWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frame_1 = new QFrame(centralwidget);
        frame_1->setObjectName(QStringLiteral("frame_1"));
        frame_1->setFrameShape(QFrame::StyledPanel);
        frame_1->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frame_1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frame_3);

        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frame_4);


        horizontalLayout->addLayout(verticalLayout);

        SecWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SecWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1155, 25));
        SecWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SecWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SecWindow->setStatusBar(statusbar);

        retranslateUi(SecWindow);

        QMetaObject::connectSlotsByName(SecWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SecWindow)
    {
        SecWindow->setWindowTitle(QApplication::translate("SecWindow", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class SecWindow: public Ui_SecWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_3D_H
