#include "cpoint.h"
#include <math.h>

CPoint::CPoint(int X, int Y, int Angle_init, QColor Color)
    :nX(X), nY(Y), nTaille(60), nDistance(-1), nAngle(-1),
    nDelai(0), CaptAr(0), CaptAv(1), ServoClap(0), ServoPince(0), nAngle_init(Angle_init), bMArriere(0)
{
    pCouleur = new QColor(Color);
    pCouleur->setAlpha(80);
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
