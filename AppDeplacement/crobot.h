#ifndef CROBOT_H
#define CROBOT_H

#include <QGraphicsItem>

class crobot
{
     QGraphicsRectItem *pType;
     int nX;
     int nY;
     int nAngle;



     void Refresh();

public:
    crobot(int X, int Y, int Angle);
    ~crobot();
    QGraphicsItem* GetType() {return pType;}
void SetRobot(int X, int Y, int Angle);
};

#endif // CROBOT_H
