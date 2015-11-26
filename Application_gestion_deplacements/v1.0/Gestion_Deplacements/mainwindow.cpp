#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QComboBox>
#include <QDebug>
#include <qviewtable.h>
#include <troisd.h>
#include <heightmapwidget.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pImage = new QPixmap("Ressources/Table.png");

    pScene = new QGraphicsScene(ui->QTable);

    ui->QTable->setScene(pScene);

    ui->QTable->setRenderHints(QPainter::Antialiasing);
    pScene->setSceneRect(0,0, pImage->width(), pImage->height());

    pScene->addPixmap(*pImage);

    ui->QTable->scale(0.3,0.3);

    ui->QTable->setMouseTracking(true);

    LObjets.push_back(new CEtape(500, 500, Qt::red));
        pScene->addItem(LObjets.last()->GetType());


    QObject::connect(ui->QTable, SIGNAL(Souris(int,int)), this, SLOT(SetPosSourisLabel(int,int)));
    QObject::connect(ui->QTable, SIGNAL(Clic(int,int)), this, SLOT(AddObjet(int,int)));
    SetInformationsEtape();
    SetListeEtapes();

    connect(ui->BtroisD, SIGNAL(clicked()),this,SLOT(affFenetre()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddObjet(int X, int Y)
{
    CPoint* A = LObjets.last()->GetPoint();
    LObjets.push_back(new CEtape(X, Y, Qt::yellow));

    LLignes.push_back(new CLine(A,LObjets.last()->GetPoint()));
    pScene->addItem(LLignes.last()->GetLigne());
    pScene->addItem(LObjets.last()->GetType());
    SetListeEtapes();


}

void MainWindow::SetPosSourisLabel(int X, int Y)
{
    QString A;
    A = "X:" + QString::number(X) + " Y:" + QString::number(Y);
    ui->qPosLabel->setText(A);
}

void MainWindow::SetInformationsEtape()
{
    int nb_row= 17;
    int nb_column = 2;
    int i=0;

    QString Labels[nb_row];

    Labels[i] = "-Etape";    i++;
    Labels[i] = "Type";    i++;
    Labels[i] = "N°";     i++;

    Labels[i] = "-Position";i++;
    Labels[i] = "X";    i++;

    Labels[i] = "Y";    i++;
    Labels[i] = "Angle";    i++;

    Labels[i] = "-Robot";    i++;
    Labels[i] = "Pince 1";    i++;
    Labels[i] = "Pince 2";    i++;
    Labels[i] = "Actions";    i++;
    Labels[i] = "Etape";    i++;

    Labels[i] = "-Robot";    i++;
    Labels[i] = "Slot 1";    i++;
    Labels[i] = "Slot 2";    i++;
    Labels[i] = "Slot 3";    i++;
    Labels[i] = "Slot 4";    i++;


    ui->qInfosEtape->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //ui->qInfosEtape->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->qInfosEtape->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->qInfosEtape->setColumnCount(nb_column);
    ui->qInfosEtape->setRowCount(nb_row);

    int teinte = 10;

    for(int row=0; row<nb_row; row++)
    {
        for(int column = 0; column<nb_column; column++)
        {

                QTableWidgetItem * newItem = new QTableWidgetItem( tr("%1").arg( (row + 1) * (column + 1) ) );

                QColor background;


                if(Labels[row][0] == QChar('-'))
                {
                    Labels[row] = Labels[row].mid(1);

                    newItem->setTextColor(QColor(255,255,255));
                    background = QColor(202,201,200);

                    QFont font;
                    font.setBold(true);

                    newItem->setFont(font);
                    ui->qInfosEtape->setSpan(row, 0, 1, nb_column);
                    teinte += 20;
                }
                else
                {
                    if(row%2 == 0)
                       background.setHsv(teinte,64,255);
                    else
                       background.setHsv(teinte,33,255);
                }

                if(column == 0) { //Labels

                    newItem->setFlags(newItem->flags() & ~ Qt::ItemIsEditable);
                    newItem->setText(Labels[row]);
                    newItem->setTextAlignment(Qt::AlignLeft);
                }
                else
                {
                    newItem->setText("");
                }


            newItem->setBackgroundColor(background);
            ui->qInfosEtape->setItem( row, column, newItem );

        }
    }

}

void MainWindow::SetListeEtapes()
{
    QStringList pListe;

    for(int i=0; i<LObjets.count(); i++) {
    pListe << "Etape " + QString::number(i);
    }

    ui->qListEtape->clear();
    ui->qListEtape->addItems(pListe);
}

void MainWindow::affFenetre()
{
    troisD* M = new troisD(this);

    //HeightmapWidget* hmw = new HeightmapWidget(M);

    M->show();
}
