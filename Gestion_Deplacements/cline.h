#ifndef CLINE_H
#define CLINE_H

#include <QColor>
#include <QGraphicsItem>
#include <cpoint.h>

class CLine
{
    int nX1;
    int nY1;

    int nX2;
    int nY2;
    int nTaille;

    QColor *pCouleur;
    QGraphicsLineItem *pLigne;

    void Refresh();

public:
    CLine(int X1, int Y1, int X2,  int Y2, QColor Color = Qt::black);
    CLine(CPoint* P1, CPoint* P2, QColor Color = Qt::black);
    ~CLine();


   // void Modification(int X1, int Y1, int X2,  int Y2);
    void Modification(CPoint* A, CPoint* B);
    QGraphicsLineItem* GetLigne() {return pLigne;}
};

#endif // CLINE_H
