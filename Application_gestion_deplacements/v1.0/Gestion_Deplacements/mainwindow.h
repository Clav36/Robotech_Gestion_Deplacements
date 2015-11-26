#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QStringList>
#include <QStandardItemModel>
#include <QVector>

#include <cprect.h>
#include <cprond.h>
#include <cline.h>
#include <cetape.h>

namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QPixmap *pImage;
    QGraphicsScene *pScene;
    QVector<CEtape*> LObjets;
    QVector<CLine*> LLignes;


public:
    explicit MainWindow(QWidget *parent = 0);
    void SetInformationsEtape();
    void SetListeEtapes();
    void setXY(int X, int Y);

    ~MainWindow();

public slots:
    void SetPosSourisLabel(int X, int Y);
        void AddObjet(int X, int Y);
    void affFenetre();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
