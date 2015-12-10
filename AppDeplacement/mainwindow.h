#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <cprect.h>
#include <cprond.h>
#include <cline.h>
#include <QDebug>
#include <QMouseEvent>
#include <vector>


#include <crobot.h>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QPixmap *pImage;
    QGraphicsScene *pScene;
    vector<CPoint*> LPoints;
    vector<CLine*> LLignes;
    vector<CPoint*> LObjets;
    crobot *Robot;

    int nSelection;
    bool bTable;
    bool bGrille;
    bool bObjets;
    bool bCoter;

    void AddLine();
    void SupprLine();
    void Informations();
    void CoordPolaire();
    void Clear();




    void AddObjets();
    void SupprObjet();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_Add_clicked();

    void on_Suppr_clicked();

    void on_checkBox_clicked(bool checked);

    void on_Jaune_toggled(bool checked);

    void on_Vert_toggled(bool checked);

    void on_Generer_clicked();

    void on_Clear_clicked();

    void on_Ouvrir_clicked();

    void on_delai_textChanged(const QString &arg1);

    void on_pince_open_toggled(bool checked);

    void on_pince_close_toggled(bool checked);

    void on_capteur_av_toggled(bool checked);

    void on_capteur_ar_toggled(bool checked);

    void on_gauche_toggled(bool checked);

    void on_fermer_toggled(bool checked);

    void on_droite_toggled(bool checked);

    void on_checkBox_3_toggled(bool checked);

    void on_checkBox_4_toggled(bool checked);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void mousePressEvent(QMouseEvent * ev);

};

#endif // MAINWINDOW_H
