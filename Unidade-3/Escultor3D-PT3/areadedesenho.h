#ifndef AREADEDESENHO_H
#define AREADEDESENHO_H


#include "qdebug.h"
#include "sculptor3d.h"
#include "novoarquivo.h"
#include <vector>
#include <QMouseEvent>
#include <QWidget>
#include <QPainter>
#include <QBrush>
#include <QPen>


class Areadedesenho : public QWidget
{
    Q_OBJECT

public:

    explicit Areadedesenho(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void loadMatriz(vector<vector<Voxel>> n);

signals:

    void coord(int,int);

public slots:


private:
    vector <vector<Voxel>> matriz;

    int x = 0 , y = 0;
    int r=0, g=0 , b=0;


    int bordaV, bordaH;
    int larguraCel, alturaCel;
    int larguraTela,alturaTela;

    int numlinhas, numcolunas;

};

#endif // AREADEDESENHO_H
