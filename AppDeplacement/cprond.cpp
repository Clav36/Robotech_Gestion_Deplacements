#include "cprond.h"
#include <QPen>

CPRond::CPRond(int X, int Y, int Angle, QColor Color)
    :CPoint(X,Y,Angle,Color)
{
    pType = new QGraphicsEllipseItem;
    Refresh();
}

void CPRond::Deplacement(int X, int Y)
{
    nX = X;
    nY = Y;

    Refresh();
}

void CPRond::Refresh()
{
    QBrush Brush;
    QPen Pen(Qt::black, 5);
    Brush.setColor(*pCouleur);
    Brush.setStyle(Qt::SolidPattern);

    pType->setRect(nX-(nTaille/2), nY-(nTaille/2), nTaille, nTaille);
    pType->setBrush(Brush);
    pType->setPen(Pen);
}

void CPRond::SetColor(QColor C)
{
    pCouleur = &C;
    Refresh();
}

CPRond::~CPRond()
{
    delete pType;
}
