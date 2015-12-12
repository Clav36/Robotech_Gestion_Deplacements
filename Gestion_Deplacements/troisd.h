#ifndef TROISD_H
#define TROISD_H

#include <QMainWindow>

namespace Ui {
class SecWindow;
}


class troisD : public QMainWindow
{
    Q_OBJECT
public:
    explicit troisD(QWidget *parent = 0);

    void SetInformationsEtape();
signals:

public slots:

private:
    Ui::SecWindow *ui;


};

#endif // TROISD_H
