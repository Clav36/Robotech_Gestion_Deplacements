#ifndef QVIEWTABLE_H
#define QVIEWTABLE_H

#include <QGraphicsView>

class QViewTable : public QGraphicsView
{
    Q_OBJECT
   public:
       QViewTable(QWidget *parent = 0);

       ~QViewTable();

   signals:
       void Souris(int, int);
       void Clic(int, int);

   protected:
       void mouseMoveEvent(QMouseEvent * event);
       void mousePressEvent(QMouseEvent * event);

};

#endif // QVIEWTABLE_H
