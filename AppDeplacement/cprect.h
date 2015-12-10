#ifndef CPRECT_H
#define CPRECT_H

#include <cpoint.h>

class CPRect : public CPoint
{
    QGraphicsRectItem *pType;
    void Refresh();

public:
    CPRect(int X, int Y, int Angle, QColor Color);
    virtual ~CPRect();

    virtual void Deplacement(int X, int Y);
    virtual void SetColor(QColor C);
    virtual QGraphicsItem* GetType() {return pType;}
};

#endif // CPRECT_H
