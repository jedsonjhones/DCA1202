#ifndef SCULPTOR3D_H
#define SCULPTOR3D_H

#include <QDebug>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cmath>

using namespace std;

struct Voxel{
    float r, g, b, a;
    bool isOn;
};

class Sculptor3D{

protected:

    int nx, ny, nz;
    float r,g,b,a;
    Voxel ***imagemVox;
    vector <Voxel> maux;
    vector <vector<Voxel>> m;

public:

    Sculptor3D(int _nx, int _ny, int _nz);
    ~Sculptor3D();
    int getX();
    int getY();
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    void setColor(float _r, float _g, float _b, float alpha);
    void writeOFF(char* filename);

    vector <vector<Voxel>> getPlano(int _z);
};

#endif // SCULPTOR3D_H
