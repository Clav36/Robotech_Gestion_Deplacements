#include "cpoint.h"
#include <math.h>

CPoint::CPoint(int X, int Y, QColor Color)
    :nX(X), nY(Y), nTaille(50)
{
    pCouleur = new QColor(Color);

}

CPoint::~CPoint()
{
    delete pCouleur;
}

void CPoint::SetCoordPolaire(CPoint* PointAv)
{

    int X = PointAv->GetX() - nX;
    int Y = PointAv->GetY() - nY;

    if(bMArriere  == 0) {
    nDistance = sqrt(X*X+Y*Y);
    nAngle = -((2*atan(Y/(X+nDistance)))*180)/M_PI - nAngle_init;

    }
    else
    {
        nDistance = -sqrt(X*X+Y*Y);
        nAngle = -((2*atan(Y/(X+nDistance)))*180)/M_PI - nAngle_init;
    }

    if(nAngle > 180)
        nAngle -= 360;
    else if(nAngle < -180)
        nAngle += 360;
}
