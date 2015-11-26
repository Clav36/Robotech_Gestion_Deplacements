#include "cetape.h"

#include <cprond.h>

CEtape::CEtape(int X, int Y, float Angle)
    :m_nX(X),m_nY(Y),m_fAngle(Angle)
{
    m_pPoint = new CPRond(X,Y,Qt::red);
}

CEtape::~CEtape()
{
    delete m_pPoint;
}

