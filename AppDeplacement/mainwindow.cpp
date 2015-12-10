#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), nSelection(-1), bTable(1), bGrille(0), bObjets(0), bCoter(0)
{


    ui->setupUi(this);

    pImage = new QPixmap("Table3.png");


    pScene = new QGraphicsScene(ui->qView);


    ui->qView->setScene(pScene);
    //ui->checkBox_3->setChecked(1);
    ui->qView->setRenderHints(QPainter::Antialiasing);
    pScene->setSceneRect(0,0, pImage->width(), pImage->height());



    if(bTable == 1)
        pScene->addPixmap(*pImage);

    CPRect *Point = new CPRect(470,1000,0,Qt::red);
    LPoints.push_back(Point);
    pScene->addItem(LPoints.back()->GetType());

    AddObjets();

    Robot = new crobot(470,1000,0);
    pScene->addItem(Robot->GetType());


   ui->qView->scale(0.25,0.25);
    Informations();
}

void MainWindow::AddObjets()
{
    int tab[3][8][2];

    for(int k = 0; k<3; k++)
    {
        for(int i = 0; i<8; i++)
        {
            for(int j = 0; j<2; j++)
            {
                tab[k][i][j] = 0;
            }
        }
    }

    //Jaunes
    tab[0][0][0] = 90; tab[0][0][1] = 1850;
    tab[0][1][0] = 90; tab[0][1][1] = 1750;
    tab[0][2][0] = 90; tab[0][2][1] = 200;
    tab[0][3][0] = 870; tab[0][3][1] = 1355;
    tab[0][4][0] = 850; tab[0][4][1] = 100;
    tab[0][5][0] = 850; tab[0][5][1] = 200;
    tab[0][6][0] = 1100; tab[0][6][1] = 1770;
    tab[0][7][0] = 1300; tab[0][7][1] = 1400;

    //Vert
    tab[1][0][0] = 1700; tab[1][0][1] = 1400;
    tab[1][1][0] = 2130; tab[1][1][1] = 1355;
    tab[1][2][0] = 1900; tab[1][2][1] = 1770;
    tab[1][3][0] = 2150; tab[1][3][1] = 100;
    tab[1][4][0] = 2150; tab[1][4][1] = 200;
    tab[1][5][0] = 2910; tab[1][5][1] = 200;
    tab[1][6][0] = 2910; tab[1][6][1] = 1770;
    tab[1][7][0] = 2910; tab[1][7][1] = 1850;

    //Goblet
    tab[2][0][0] = 250; tab[2][0][1] = 1750;
    tab[2][1][0] = 910; tab[2][1][1] = 830;
    tab[2][2][0] = 2090; tab[2][2][1] = 830;
    tab[2][3][0] = 1500; tab[2][3][1] = 1650;
    tab[2][4][0] = 2750; tab[2][4][1] = 1770;

    for(int k = 0; k<3; k++)
    {
        for(int i = 0; i<8; i++)
        {
            if(k == 0)
                LObjets.push_back(new CPRond(tab[k][i][0], tab[k][i][1], 0, Qt::yellow));
            else if(k == 1)
                LObjets.push_back(new CPRond(tab[k][i][0], tab[k][i][1], 0, Qt::green));
            else if(k == 2) {
                if(i<5)
                {
                    LObjets.push_back(new CPRect(tab[k][i][0], tab[k][i][1], 0, Qt::white));
                }
            }



        }
    }

    for(int i = 0; i<21; i++) {
        pScene->addItem(LObjets.at(i)->GetType());
    }
}

void MainWindow::SupprObjet()
{

    for(int i = 0; i<21; i++) {
        pScene->removeItem(LObjets.at(i)->GetType());
    }
}


MainWindow::~MainWindow()
{
    delete pImage;
    delete pScene;
    delete ui;

    while(!LPoints.empty())
        delete LPoints.front();

}


void MainWindow::on_Add_clicked()
{
    if(nSelection == -1) {
       nSelection = (int)LPoints.size();
       CPRond *Point = new CPRond(1500,1000,LPoints.at(nSelection-1)->GetAngle()  + LPoints.at(nSelection-1)->GetAngleInit() , Qt::green);
       LPoints.push_back(Point);

       AddLine();

       pScene->addItem(LPoints.back()->GetType());
       CoordPolaire();
       Informations();
    }
}

void MainWindow::CoordPolaire()
{
    if(nSelection != -1) {
        if(nSelection > 0)
        {
            LPoints.at(nSelection)->SetAngleInit(LPoints.at(nSelection-1)->GetAngle() + LPoints.at(nSelection-1)->GetAngleInit() );
            LPoints.at(nSelection-1)->SetCoordPolaire(LPoints.at(nSelection));
        }

        if(nSelection+1 < LPoints.size())
        {
            LPoints.at(nSelection+1)->SetAngleInit(LPoints.at(nSelection)->GetAngle() + LPoints.at(nSelection)->GetAngleInit() );
            LPoints.at(nSelection)->SetCoordPolaire(LPoints.at(nSelection+1));
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent * ev)
{
    int posX = (ev->x()-51)/0.25+2;
    int posY = (ev->y()-32)/0.25;

    if(ev->button() == Qt::LeftButton)
    {
        if(nSelection == -1){
            for(int i=0; i<(int)LPoints.size();i++) {
                int X = LPoints.at(i)->GetX();
                int Y = LPoints.at(i)->GetY();
                int Taille = LPoints.at(i)->GetTaille()/2;

                if(posX > X-Taille && posX < X+Taille &&
                   posY > Y-Taille && posY < Y+Taille) {
                    nSelection = i;
                }

            }

            if(nSelection != -1){
                LPoints.at(nSelection)->SetColor(Qt::green);

            }
        }
        else {

            LPoints.at(nSelection)->Deplacement(posX,posY);

            if(nSelection > 0)
                LLignes.at(nSelection-1)->Modification(LPoints.at(nSelection-1),LPoints.at(nSelection));

            if(nSelection+1 <(int) LPoints.size())
                LLignes.at(nSelection)->Modification(LPoints.at(nSelection),LPoints.at(nSelection+1));

            LPoints.at(nSelection)->SetColor(Qt::green);
            CoordPolaire();
            if(nSelection > 0)
            {
                LPoints.at(nSelection)->SetAngleInit(LPoints.at(nSelection-1)->GetAngle() + LPoints.at(nSelection-1)->GetAngleInit() );
            }

        }
    }
    else if(ev->button() == Qt::RightButton)
    {
           if(nSelection != -1) {
               if(LPoints.at(nSelection)->GetArriere() == 0)
                     LPoints.at(nSelection)->SetColor(Qt::red);
               else
                   LPoints.at(nSelection)->SetColor(QColor(254,151,0));
               nSelection = -1;
           }
    }
    Informations();
}


void MainWindow::AddLine()
{
    if(nSelection > 0) {

        int X1 = LPoints.at(nSelection-1)->GetX();
        int Y1 = LPoints.at(nSelection-1)->GetY();

        int X2 = LPoints.at(nSelection)->GetX();
        int Y2 = LPoints.at(nSelection)->GetY();

        LLignes.push_back(new CLine(X1,Y1,X2,Y2));
        pScene->addItem(LLignes.back()->GetLigne());
    }
}


void MainWindow::on_Suppr_clicked()
{
    if(nSelection > 0) {

        if(nSelection+1 < (int)LPoints.size()){
            pScene->removeItem(LLignes.at(nSelection)->GetLigne());
            LLignes.erase(LLignes.begin()+nSelection);
        }



        pScene->removeItem(LPoints.at(nSelection)->GetType());
        LPoints.erase(LPoints.begin()+nSelection);


        if(nSelection < (int)LPoints.size())
           LLignes.at(nSelection-1)->Modification(LPoints.at(nSelection-1),LPoints.at(nSelection));
        else if(nSelection == (int)LPoints.size())
        {
           pScene->removeItem(LLignes.at(nSelection-1)->GetLigne());
           LLignes.erase(LLignes.begin()+nSelection-1);
        }

       // if(nSelection+1 < LPoints.size())
         //   LLignes.at(nSelection)->Modification(LPoints.at(nSelection),LPoints.at(nSelection+1));

        nSelection = -1;
        Informations();
    }
}

void MainWindow::Informations()
{
    if(nSelection == -1)
    {
        ui->Num->setText("Aucun");
        ui->PosX->setText("null");
        ui->PosY->setText("null");
        ui->AvAngle->setText("null");
        ui->AvDistance->setText("null");
        ui->ApAngle->setText("null");
        ui->ApDistance->setText("null");
        ui->delai->setText("null");
        ui->capteur_ar->setChecked(0);
        ui->capteur_av->setChecked(0);
        ui->fermer->setChecked(0);
        ui->droite->setChecked(0);

        ui->pince_close->setChecked(0);
        ui->pince_open->setChecked(0);
        ui->checkBox_4->setChecked(0);
    }
    else
    {
        Robot->SetRobot(LPoints.at(nSelection)->GetX(), LPoints.at(nSelection)->GetY(), LPoints.at(nSelection)->GetAngle()+LPoints.at(nSelection)->GetAngleInit());

        CPoint *Selection = LPoints.at(nSelection);
        ui->Num->setText(QString::number(nSelection));
        ui->PosX->setText(QString::number(Selection->GetX()));
        ui->PosY->setText(QString::number(Selection->GetY()));

        if(nSelection != 0) {
            ui->AvAngle->setText(QString::number(LPoints.at(nSelection-1)->GetAngle()));
            ui->AvDistance->setText(QString::number(LPoints.at(nSelection-1)->GetDistance()));
        }
        else {
            ui->AvAngle->setText("null");
            ui->AvDistance->setText("null");
        }

        if(nSelection != LPoints.size()) {
            ui->ApAngle->setText(QString::number(Selection->GetAngle()));
            ui->ApDistance->setText(QString::number(Selection->GetDistance()));
        }
        else
        {
            ui->ApAngle->setText("null");
            ui->ApDistance->setText("null");
        }

        ui->delai->setText(QString::number(Selection->GetDelai()));
        ui->capteur_ar->setChecked(Selection->GetCaptAr());
        ui->capteur_av->setChecked(Selection->GetCaptAv());


        ui->fermer->setChecked(0);
        ui->droite->setChecked(0);


        if(Selection->GetServoClap() == 0)
            ui->fermer->setChecked(1);
        else if(Selection->GetServoClap() == 1)
            ui->droite->setChecked(1);

        ui->pince_close->setChecked(0);
        ui->pince_open->setChecked(0);

        if(Selection->GetServoPince()==1)
            ui->pince_close->setChecked(1);
        else
            ui->pince_open->setChecked(1);

        ui->checkBox_4->setChecked(Selection->GetArriere());
        qDebug() << LPoints.at(nSelection)->GetAngleInit() << endl;
    }
}

void MainWindow::on_checkBox_clicked(bool checked)
{
    bTable = checked;
}


void MainWindow::on_Jaune_toggled(bool checked)
{
    if(checked == 1) {
        for(int i =0; i<(int)LPoints.size(); i++) {
            LPoints.at(i)->Deplacement(abs(LPoints.at(i)->GetX()-3000),LPoints.at(i)->GetY());

            LPoints.at(i)->SetColor(Qt::red);

            if(i > 0)
                LLignes.at(i-1)->Modification(LPoints.at(i),LPoints.at(i-1));
}

        }
        bCoter = 1;
        nSelection = -1;

}

void MainWindow::on_Vert_toggled(bool checked)
{
    if(checked == 1) {
        for(int i =0; i<(int)LPoints.size(); i++){
            LPoints.at(i)->Deplacement(3000-LPoints.at(i)->GetX(),LPoints.at(i)->GetY());
            LPoints.at(i)->SetColor(Qt::red);



            if(i > 0)
                LLignes.at(i-1)->Modification(LPoints.at(i),LPoints.at(i-1));

        }
        bCoter = 0;
        nSelection = -1;
    }
}




void MainWindow::on_Generer_clicked()
{

       FILE* fichier = NULL;
       QString Path = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "Fichier Texte(*.txt)");;

       fichier = fopen(Path.toStdString().c_str(), "w");

       if (fichier != NULL)
       {


           fprintf(fichier, "if(digitalRead(pin_terrain))\n{\ninit_servo = 63;\n");
           int j = 0;
           int max = 0;

           for(int i=0; i<(int)LPoints.size()-1; i++)
           {
               int Clap = 0;
               int Pince = 0;

               if(LPoints.at(i)->GetServoClap() == -1)//droite
                   Clap = 0;
               else if(LPoints.at(i)->GetServoClap() == 0)
                   Clap = 63;
               else
                   Clap = 30;



                   Pince = LPoints.at(i)->GetServoPince();

                if(LPoints.at(i)->GetAngle() != 0) {
                fprintf(fichier, "feed_parcours(%d,%d,%d,%d,%d,%d,%d,%d);\n", j, 0, (int)(LPoints.at(i)->GetAngle()*10), 0, Clap, Pince, LPoints.at(i)->GetCaptAv(), LPoints.at(i)->GetCaptAr());
                j++;
                }

                fprintf(fichier, "feed_parcours(%d,%d,%d,%d,%d,%d,%d,%d);\n", j, LPoints.at(i)->GetDelai(), 0, (int)LPoints.at(i)->GetDistance(), Clap, Pince, LPoints.at(i)->GetCaptAv(), LPoints.at(i)->GetCaptAr());
                j++;
                max = j;
            }
           fprintf(fichier, "feed_parcours(%d,%d,%d,%d,%d,%d,%d,%d);\n",max, 666, 0, 0, 80, 1, 0, 0, 0);
           fprintf(fichier, "}\nelse\n{\ninit_servo = 104;\n");

            max = 0;
            j = 0;

          for(int i=0; i<(int)LPoints.size()-1; i++)
          {
              int Clap = 0;
              int Pince = 0;

              if(LPoints.at(i)->GetServoClap() == -1)//droite
                  Clap = 0;
              else if(LPoints.at(i)->GetServoClap() == 0)
                  Clap = 104;
              else
                  Clap = 150;



                  Pince = LPoints.at(i)->GetServoPince() ;


              if(LPoints.at(i)->GetAngle() != 0) {
               fprintf(fichier, "feed_parcours(%d,%d,%d,%d,%d,%d,%d,%d);\n", j, 0, -(int)(LPoints.at(i)->GetAngle()*10), 0, Clap, Pince, LPoints.at(i)->GetCaptAv(), LPoints.at(i)->GetCaptAr());
               j++;
              }

               fprintf(fichier, "feed_parcours(%d,%d,%d,%d,%d,%d,%d,%d);\n", j, LPoints.at(i)->GetDelai(), 0, (int)LPoints.at(i)->GetDistance(), Clap, Pince, LPoints.at(i)->GetCaptAv(), LPoints.at(i)->GetCaptAr());
               j++;
               max = j;
          }
          fprintf(fichier, "feed_parcours(%d,%d,%d,%d,%d,%d,%d,%d);\n", max, 666, 0, 0, 80, 1, 0, 0);
          fprintf(fichier, "}");
           fclose(fichier);
       }
}

void MainWindow::Clear()
{
    while(LPoints.size() > 1){
        pScene->removeItem(LPoints.back()->GetType());
        pScene->removeItem(LLignes.at(LPoints.size()-2)->GetLigne());
        LPoints.erase(LPoints.begin()+LPoints.size()-1);
    }
    LLignes.clear();
    nSelection = -1;
}


void MainWindow::on_Clear_clicked()
{
    Clear();
}

void MainWindow::on_Ouvrir_clicked()
{
    FILE* fichier = NULL;
    QString Path = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Fichier Texte(*.txt)");;

   fichier = fopen(Path.toStdString().c_str(), "r");

    if (fichier != NULL)
    {
        Clear();

         //    fprintf(fichier, "%d %d\n", LPoints.at(i)->GetX(), LPoints.at(i)->GetY());

        fclose(fichier);
    }
}

void MainWindow::on_delai_textChanged(const QString &arg1)
{
    if(nSelection != -1) {
        LPoints.at(nSelection)->SetDelai(arg1.toInt());
    }
}

void MainWindow::on_pince_open_toggled(bool checked)
{
    if(nSelection != -1) {
            LPoints.at(nSelection)->SetServoPince(!checked);
    }
}

void MainWindow::on_pince_close_toggled(bool checked)
{
    if(nSelection != -1) {
            LPoints.at(nSelection)->SetServoPince(checked);
    }
}

void MainWindow::on_capteur_av_toggled(bool checked)
{
    if(nSelection != -1) {
            LPoints.at(nSelection)->SetCaptAv(checked);
    }
}

void MainWindow::on_capteur_ar_toggled(bool checked)
{
    if(nSelection != -1) {
            LPoints.at(nSelection)->SetCaptAr(checked);
    }
}

void MainWindow::on_gauche_toggled(bool checked)
{
    if(nSelection != -1) {
        if(checked == 1)
            LPoints.at(nSelection)->SetServoClap(1);
    }
}

void MainWindow::on_fermer_toggled(bool checked)
{
    if(nSelection != -1) {
        if(checked == 1)
            LPoints.at(nSelection)->SetServoClap(0);
    }
}

void MainWindow::on_droite_toggled(bool checked)
{
    if(nSelection != -1) {
        if(checked == 1)
            LPoints.at(nSelection)->SetServoClap(-1);
    }
}

void MainWindow::on_checkBox_3_toggled(bool checked)
{
    if(checked == 1)
    {
        AddObjets();
    }
    else
    {
        SupprObjet();
    }
}

void MainWindow::on_checkBox_4_toggled(bool checked)
{
    if(nSelection != -1)
    {
        LPoints.at(nSelection)->SetMarcheArriere(checked);
    }
}

void MainWindow::on_pushButton_clicked()
{
    FILE* fichier = NULL;
    fichier = fopen("Envoi.txt", "w");

    if (fichier != NULL)
    {
        for(int i=0; i<(int)LPoints.size()-1; i++)
        {
            int Clap = 0;
            int Pince = 0;

            if(LPoints.at(i)->GetServoClap() == -1)
                Clap = 0;
            else if(LPoints.at(i)->GetServoClap() == 0)
                Clap = 63;
            else
                Clap = 30;



                Pince = LPoints.at(i)->GetServoPince();

             if(LPoints.at(i)->GetAngle() != 0) {
             fprintf(fichier, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, (int)(LPoints.at(i)->GetAngle()*10), 0, Clap, Pince, LPoints.at(i)->GetCaptAv(), LPoints.at(i)->GetCaptAr());

             }

             fprintf(fichier, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n", LPoints.at(i)->GetDelai(), 0, (int)LPoints.at(i)->GetDistance(), Clap, Pince, LPoints.at(i)->GetCaptAv(), LPoints.at(i)->GetCaptAr());

         }
        fprintf(fichier, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 666, 0, 0, 80, 1, 0, 0, 0);


       for(int i=0; i<(int)LPoints.size()-1; i++)
       {
           int Clap = 0;
           int Pince = 0;

           if(LPoints.at(i)->GetServoClap() == -1)//droite
               Clap = 0;
           else if(LPoints.at(i)->GetServoClap() == 0)
               Clap = 104;
           else
               Clap = 150;



               Pince = LPoints.at(i)->GetServoPince() ;


           if(LPoints.at(i)->GetAngle() != 0) {
            fprintf(fichier, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, -(int)(LPoints.at(i)->GetAngle()*10), 0, Clap, Pince, LPoints.at(i)->GetCaptAv(), LPoints.at(i)->GetCaptAr());

           }

            fprintf(fichier, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n", LPoints.at(i)->GetDelai(), 0, (int)LPoints.at(i)->GetDistance(), Clap, Pince, LPoints.at(i)->GetCaptAv(), LPoints.at(i)->GetCaptAr());

       }
       fprintf(fichier, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 666, 0, 0, 80, 1, 0, 0);
       fclose(fichier);
}
}
