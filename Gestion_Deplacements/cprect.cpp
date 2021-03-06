#include "cprect.h"
#include <QPen>

CPRect::CPRect(int X, int Y, QColor Color)
    :CPoint(X,Y,Color)
{
    pType = new QGraphicsRectItem;
    Refresh();
}

void CPRect::Deplacement(int X, int Y)
{
    nX = X;
    nY = Y;

    Refresh();
}

void CPRect::Refresh()
{
    QBrush Brush;
    QPen Pen(Qt::black, 2);
    Brush.setColor(*pCouleur);
    Brush.setStyle(Qt::SolidPattern);

    pType->setRect(nX-(nTaille/2), nY-(nTaille/2), nTaille, nTaille);
    pType->setBrush(Brush);
    pType->setPen(Pen);
}

void CPRect::SetColor(QColor C)
{
    pCouleur = &C;
    Refresh();
}

CPRect::~CPRect()
{
    delete pType;
}
