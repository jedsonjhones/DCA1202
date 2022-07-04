#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <QMainWindow>
#include "novoarquivo.h"
#include "areadedesenho.h"
#include "sculptor3d.h"
#include "QDebug"
#include <iostream>
using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    Sculptor3D *mat;
    float r, g, b;
    int dimx, dimy, dimz;

    int token;

public slots:

    void criaNovoArquivo(void);

    void atualizaPlano(int n);
    void atualizaCoord(int _x, int _y);

    void setR(int _r);
    void setG(int _g);
    void setB(int _b);

    void putVoxel();
    void cutVoxel();
    void putSphere();
    void cutSphere();
    void putBox();
    void cutBox();

    void salvarFile();
    void killPrograma();

signals:


};
#endif // MAINWINDOW_H
