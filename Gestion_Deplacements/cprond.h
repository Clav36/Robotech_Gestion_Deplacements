#ifndef CPROND_H
#define CPROND_H

#include <cpoint.h>

class CPRond : public CPoint
{
    QGraphicsEllipseItem *pType;
    void Refresh();

public:
    CPRond(int X, int Y, QColor Color);
    virtual ~CPRond();

    virtual void Deplacement(int X, int Y);
    virtual void SetColor(QColor C);
    virtual QGraphicsItem* GetType() {return pType;}
};

#endif // CPROND_H
