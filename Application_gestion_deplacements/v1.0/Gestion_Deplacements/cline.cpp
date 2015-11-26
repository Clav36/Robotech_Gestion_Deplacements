#include "cline.h"
#include <QPen>

CLine::CLine(int X1, int Y1, int X2,  int Y2, QColor Color)
    :nX1(X1), nX2(X2), nY1(Y1), nY2(Y2), nTaille(5)
{
    pCouleur = new QColor(Color);
    pLigne = new QGraphicsLineItem;

    Refresh();

}

CLine::CLine(CPoint* P1, CPoint* P2, QColor Color)
  :nX1(P1->GetX()), nX2(P2->GetX()), nY1(P1->GetY()), nY2(P2->GetY()), nTaille(5)
{
    pCouleur = new QColor(Color);
    pLigne = new QGraphicsLineItem();

    Refresh();
}

//void CLine::Modification(int X1, int Y1, int X2, int Y2)
//{
//    nX1 = X1;
//    nX2 = X2;
//    nY1 = Y1;
//    nY2 = Y2;
//    Refresh();
//}

void CLine::Modification(CPoint *A, CPoint *B)
{
    nX1 = A->GetX();
    nY1 = A->GetY();

    nX2 = B->GetX();
    nY2 = B->GetY();
    Refresh();
}

void CLine::Refresh()
{
    QPen Pen(QBrush(*pCouleur), nTaille);
  //  Pen.setStyle(Qt::DashLine);
    pLigne->setPen(Pen);
    pLigne->setLine(nX1,nY1,nX2,nY2);
}

CLine::~CLine()
{
    delete pCouleur;
}
