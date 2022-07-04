#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){

    ui->setupUi(this);
    dimx = dimy = dimz = 10;
    mat = new Sculptor3D(dimx,dimy,dimz);
    r = g = b =0;
    ui->horizontalSliderR->setMaximum(255);
    ui->horizontalSliderG->setMaximum(255);
    ui->horizontalSliderB->setMaximum(255);
    ui->horizontalSliderRaioEsfera->setMaximum(dimx-1);
    ui->SliderXbox->setMaximum(dimx-1);
    ui->SliderYbox->setMaximum(dimy-1);
    ui->SliderZbox->setMaximum(dimz-1);
    ui->horizontalSliderPlanoZ->setMaximum(dimz-1);

    ui->widget->loadMatriz(mat->getPlano(ui->horizontalSliderPlanoZ->value()));

    connect(ui->actionNovo_Arquivo,SIGNAL(triggered(bool)),this,SLOT(criaNovoArquivo()));

    connect(ui->widget,SIGNAL(coord(int,int)),this,SLOT(atualizaCoord(int,int)));

    connect(ui->horizontalSliderPlanoZ,SIGNAL(valueChanged(int)),this,SLOT(atualizaPlano(int)));

    connect(ui->horizontalSliderR,SIGNAL(valueChanged(int)),this,SLOT(setR(int)));
    connect(ui->horizontalSliderG,SIGNAL(valueChanged(int)),this,SLOT(setG(int)));
    connect(ui->horizontalSliderB,SIGNAL(valueChanged(int)),this,SLOT(setB(int)));

    connect(ui->actionSalvar_2,SIGNAL(triggered()),this,SLOT(salvarFile()));
    connect(ui->actionFechar,SIGNAL(triggered()),this,SLOT(killPrograma()));

    connect(ui->actionPutvoxel,SIGNAL(triggered()),this,SLOT(putVoxel()));
    connect(ui->actionPutsphere,SIGNAL(triggered()),this,SLOT(putSphere()));
    connect(ui->actionPutbox,SIGNAL(triggered()),this,SLOT(putBox()));

    connect(ui->actionCutvoxel,SIGNAL(triggered()),this,SLOT(cutVoxel()));
    connect(ui->actionCutsphere,SIGNAL(triggered()),this,SLOT(cutSphere()));
    connect(ui->actionCutbox,SIGNAL(triggered()),this,SLOT(cutBox()));

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::criaNovoArquivo(){

    Novoarquivo n;

    bool resul = n.exec();
    if(resul == QDialog::Accepted){
        delete mat;
        dimx = n.pegadimx();
        dimy = n.pegadimy();
        dimz = n.pegadimz();
        mat = new Sculptor3D(dimx,dimy,dimz);
        ui->horizontalSliderPlanoZ->setMaximum(dimz-1);
        ui->horizontalSliderRaioEsfera->setMaximum(dimx-1);
        ui->SliderXbox->setMaximum(dimx-1);
        ui->SliderYbox->setMaximum(dimy-1);
        ui->SliderZbox->setMaximum(dimz-1);
        ui->widget->loadMatriz(mat->getPlano(ui->horizontalSliderPlanoZ->value()));
    }
}

void MainWindow::atualizaPlano(int _n){
    ui->widget->loadMatriz(mat->getPlano(_n));

}
void MainWindow::atualizaCoord(int _x, int _y){

    if((_x >=0 && _x < dimx) && (_y >= 0 && _y < dimy)){
        switch(token){
        case 1:
            mat->setColor(r/255.0,g/255.0,b/255.0,1.0);
            mat->putVoxel(_y,_x,ui->horizontalSliderPlanoZ->value());
            ui->widget->loadMatriz(mat->getPlano(ui->horizontalSliderPlanoZ->value()));
        break;
        case 2:
            mat->setColor(r/255.0,g/255.0,b/255.0,1.0);
            mat->cutVoxel(_y,_x,ui->horizontalSliderPlanoZ->value());
            ui->widget->loadMatriz(mat->getPlano(ui->horizontalSliderPlanoZ->value()));
            break;
        case 3:
            mat->setColor(r/255.0,g/255.0,b/255.0,1.0);
            mat->putSphere(_y,_x,ui->horizontalSliderPlanoZ->value(),ui->horizontalSliderRaioEsfera->value());
            ui->widget->loadMatriz(mat->getPlano(ui->horizontalSliderPlanoZ->value()));
            break;
        case 4:
            mat->setColor(r/255.0,g/255.0,b/255.0,1.0);
            mat->cutSphere(_y,_x,ui->horizontalSliderPlanoZ->value(),ui->horizontalSliderRaioEsfera->value());
            ui->widget->loadMatriz(mat->getPlano(ui->horizontalSliderPlanoZ->value()));
            break;
        case 5:
            mat->setColor(r/255.0,g/255.0,b/255.0,1.0);

            mat->putBox(_y - ui->SliderYbox->value()/2,
                        _y + ui->SliderYbox->value()/2,
                        _x - ui->SliderXbox->value()/2,
                        _x + ui->SliderXbox->value()/2,
                        ui->horizontalSliderPlanoZ->value() - ui->SliderZbox->value()/2,
                        ui->horizontalSliderPlanoZ->value() + ui->SliderZbox->value()/2);
            ui->widget->loadMatriz(mat->getPlano(ui->horizontalSliderPlanoZ->value()));
            break;
        case 6:
            mat->setColor(r/255.0,g/255.0,b/255.0,1.0);

            mat->cutBox(_y - ui->SliderYbox->value()/2,
                        _y + ui->SliderYbox->value()/2,
                        _x - ui->SliderXbox->value()/2,
                        _x + ui->SliderXbox->value()/2,
                        ui->horizontalSliderPlanoZ->value() - ui->SliderZbox->value()/2,
                        ui->horizontalSliderPlanoZ->value() + ui->SliderZbox->value()/2);
            ui->widget->loadMatriz(mat->getPlano(ui->horizontalSliderPlanoZ->value()));
            break;
       }
    }
}

void MainWindow::setR(int _r){
    r = _r;
    update();
}
void MainWindow::setG(int _g){
    g = _g;
    update();
}

void MainWindow::setB(int _b){
    b = _b;
    update();
}
void MainWindow::salvarFile(){
    qDebug() << "Onde vai";
    mat->writeOFF((char*)"Arquivo.off");
}

void MainWindow::putVoxel(){
    token = 1;
}
void MainWindow::cutVoxel(){
    token = 2;
}
void MainWindow::putSphere(){
    token = 3;
}
void MainWindow::cutSphere(){
    token = 4;
}
void MainWindow::putBox(){
    token = 5;
}
void MainWindow::cutBox(){
    token = 6;
}

void MainWindow::killPrograma(){
    exit(0);
}

