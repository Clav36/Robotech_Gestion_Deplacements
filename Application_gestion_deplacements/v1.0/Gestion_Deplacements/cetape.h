#ifndef CETAPE_H
#define CETAPE_H

#include <cpoint.h>
#include <QGraphicsItem>

class CEtape
{
    CPoint* m_pPoint;

    int m_nX;
    int m_nY;
    float m_fAngle;


public:
    CEtape(int X, int Y, float Angle);
    ~CEtape();

    int GetX() {return m_nX;}
    int GetY() {return m_nY;}
    float GetAngle() {return m_fAngle;}

    CPoint* GetPoint() {return m_pPoint;}
    QGraphicsItem* GetType() {return m_pPoint->GetType();}
};

#endif // CETAPE_H
