#include "qviewtable.h"
#include <QMouseEvent>

QViewTable::QViewTable(QWidget *parent) :
    QGraphicsView(parent)
{
    setMouseTracking(true);

}

QViewTable::~QViewTable()
{

}

void QViewTable::mouseMoveEvent(QMouseEvent * evt)
{
    emit Souris((evt->x()-this->width()/2)/0.3+1533, (evt->y()-this->height()/2)/0.3+1133);
    // rien mis pour l'instant
}

void QViewTable::mousePressEvent(QMouseEvent * evt)
{
    emit Clic((evt->x()-this->width()/2)/0.3+1533, (evt->y()-this->height()/2)/0.3+1133);
}
