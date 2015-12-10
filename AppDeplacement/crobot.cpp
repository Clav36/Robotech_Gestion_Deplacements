#include "crobot.h"
#include <QPen>

crobot::crobot(int X, int Y, int Angle)
{
    nX = X;
    nY = Y;
    nAngle = Angle;
    pType = new QGraphicsRectItem;
    Refresh();
}

crobot::~crobot()
{
    delete pType;
}

void crobot::SetRobot(int X, int Y, int Angle)
{
    nX = X;
    nY = Y;
    nAngle = Angle;
    Refresh();
}

void crobot::Refresh()
{
    QPen Pen(Qt::black, 5);
    pType->setRect(-(315/2),-(330/2),315,330);
    pType->setRotation(-nAngle);
    pType->setPos(nX,nY);

    pType->setPen(Pen);
}
