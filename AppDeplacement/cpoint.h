#ifndef CPOINT_H
#define CPOINT_H

#include <QGraphicsItem>
#include <QColor>
#include <QBrush>


class CPoint
{
protected:
    int nX;
    int nY;
    float nAngle;
    int nAngle_init;
    float nDistance;

    int nDelai;
    int ServoClap;
    bool ServoPince;
    bool CaptAv;
    bool CaptAr;
    bool bMArriere;

    float nTaille;
    QColor *pCouleur;

public:
    CPoint(int X, int Y, int Angle_init, QColor Color);
    virtual ~CPoint();

    int GetX() {return nX;}
    int GetY() {return nY;}
    int GetTaille() {return nTaille;}
    float GetAngle() {return nAngle;}
    float GetDistance() {return nDistance;}
    bool GetArriere() {return bMArriere;}

    int GetDelai() {return nDelai;}
    bool GetServoClap() {return ServoClap;}
    bool GetServoPince() {return ServoPince;}
    bool GetCaptAv() {return CaptAv;}
    bool GetCaptAr() {return CaptAr;}
    int GetAngleInit() {return nAngle_init;}


    void SetServoClap(int X) {ServoClap = X;}
    void SetServoPince(bool X) {ServoPince = X;}
    void SetCaptAv(bool X) {CaptAv = X;}
    void SetCaptAr(bool X) {CaptAr = X;}
    void SetDelai(int time) {nDelai = time;}
    void SetAngleInit(int Angle) {nAngle_init = Angle;}
    void SetMarcheArriere(bool X) {bMArriere = X; CaptAr = X; CaptAv = !X;}

    void SetCoordPolaire(CPoint* PointAv);

    virtual void SetColor(QColor C) = 0;
    virtual void Deplacement(int X, int Y) = 0;
    virtual QGraphicsItem* GetType() = 0;
};

#endif // CPOINT_H
