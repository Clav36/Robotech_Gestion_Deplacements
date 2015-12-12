#include "troisd.h"
#include "ui_3D.h"
#include "heightmapwidget.h"

troisD::troisD(QWidget *parent) :
    QMainWindow(parent),ui(new Ui::SecWindow)
{
    ui->setupUi(this);

    HeightmapWidget *hmw1 = new HeightmapWidget(ui->frame_1);
    HeightmapWidget *hmw2 = new HeightmapWidget(ui->frame_3);
    HeightmapWidget *hmw3 = new HeightmapWidget(ui->frame_4);
    SetInformationsEtape();

}

void troisD::SetInformationsEtape()
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
