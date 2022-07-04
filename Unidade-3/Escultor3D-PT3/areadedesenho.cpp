#include "areadedesenho.h"

Areadedesenho::Areadedesenho(QWidget *parent) : QWidget(parent){

}

void Areadedesenho::paintEvent(QPaintEvent *event){

    QPainter painter(this);
    QBrush brush;
    QPen pen;
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(QColor(255,255,255));

    larguraTela = rect().width();
    alturaTela = rect().height();
    larguraCel = larguraTela/numcolunas;
    alturaCel = alturaTela/numlinhas;

    bordaH =(larguraTela - numcolunas*larguraCel)/2;
    bordaV =(alturaTela - numlinhas*alturaCel)/2;

    for(size_t i = 0; i < matriz.size(); i++){
        for(size_t j = 0; j < matriz[i].size(); j++){
            if(matriz[i][j].isOn == true){
                painter.setBrush(QColor(matriz[i][j].r*255,matriz[i][j].g*255,matriz[i][j].b*255));
                painter.drawEllipse(j*larguraCel+bordaH,i*alturaCel+bordaV,larguraCel,alturaCel);
            }else{
                painter.setBrush(QColor(255,255,255));
                painter.drawRect(j*larguraCel+bordaH,i*alturaCel+bordaV,larguraCel,alturaCel);
            }
        }
    }

}


// quando pressionado o mouse retorna a posição da tela
void Areadedesenho::mousePressEvent(QMouseEvent *event){

    int posh , posv;
    QRect ret;
    ret = rect();
    ret.adjust(bordaH,bordaV,-bordaH,-bordaV);
    posh = (event->x())*numcolunas/ret.width();
    posv = (event->y())*numlinhas/ret.height();
    emit coord(posh,posv);

}
//rastreia o mouse pressionado na tela
void Areadedesenho::mouseMoveEvent(QMouseEvent *event){
    int posh , posv;
    QRect ret;
    ret = rect();
    ret.adjust(bordaH,bordaV,-bordaH,-bordaV);
    posh = (event->x())*numcolunas/ret.width();
    posv = (event->y())*numlinhas/ret.height();
    emit coord(posh,posv);
}
void Areadedesenho::loadMatriz(vector<vector<Voxel>> n){
    numlinhas = n.size();
    numcolunas = n[0].size();
    matriz = n;
    repaint();
}
