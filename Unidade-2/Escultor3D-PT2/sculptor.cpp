#include <fstream>
#include <string>
#include <iomanip>
#include "sculptor.h"

using namespace std;

Sculptor::Sculptor(unsigned _nx, unsigned _ny, unsigned _nz): nx(_nx), ny(_ny), nz(_nz), v(nullptr){
    v = new Voxel**[nx];
    for(unsigned i=0; i<nx; i++){
        v[i] = new Voxel*[ny];
        for(unsigned j=0; j<ny; j++) v[i][j] = new Voxel[nz];
    }
    for(unsigned i=0; i<nx; i++){
        for(unsigned j=0; j<ny; j++){
            for(unsigned k=0; k<nz; k++){
                v[i][j][k].a = 0.0;
                v[i][j][k].r = 0.0;
                v[i][j][k].g = 0.0;
                v[i][j][k].b = 0.0;
                v[i][j][k].is0n = false;
            }
        }
    }
}

Sculptor::~Sculptor(){
    if(v!=nullptr){
        for(unsigned i=0; i<nx; i++){
            for(unsigned j=0; j<ny; j++) if(v[i][j]!=nullptr) delete[] v[i][j];
            if(v[i]!=nullptr) delete[] v[i];
        }
        delete[] v;
    }
}

void Sculptor::setColor(float _r, float _g, float _b, float alpha){
    r=_r;
    g=_g;
    b=_b;
    a=alpha;
}

void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].a = a;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].is0n = true;

}

void Sculptor::cutVoxel(int x, int y, int z){v[x][y][z].is0n = false;}

void Sculptor::writeOFF(const char* filename){
    ofstream arq(filename);
    unsigned Nvoxels = 0;
    unsigned cont = 0;
    unsigned vert, face;
    arq << "OFF\n";
    for(unsigned i=0; i<nx; i++) for(unsigned j=0; j<ny; j++) for(unsigned k=0; k<nz; k++) if(v[i][j][k].is0n == true) Nvoxels++;
    vert = Nvoxels*8;
    face = Nvoxels*6;
    arq << (vert) << " " << (face) << " " << 0 << endl;
    for(unsigned i=0; i<nx; i++){
        for(unsigned j=0; j<ny; j++){
            for(unsigned k=0; k<nz; k++){
                if(v[i][j][k].is0n == true){
                    arq << i+(-0.5) << " " << j+(0.5) << " " << k+(-0.5) << endl;
                    arq << i+(-0.5) << " " << j+(-0.5) << " " << k+(-0.5) << endl;
                    arq << i+(0.5) << " " << j+(-0.5) << " " << k+(-0.5) << endl;
                    arq << i+(0.5) << " " << j+(0.5) << " " << k+(-0.5) << endl;
                    arq << i+(-0.5) << " " << j+(0.5) << " " << k+(0.5) << endl;
                    arq << i+(-0.5) << " " << j+(-0.5) << " " << k+(0.5) << endl;
                    arq << i+(0.5) << " " << j+(-0.5) << " " << k+(0.5) << endl;
                    arq << i+(0.5) << " " << j+(0.5) << " " << k+(0.5) << endl;
                }

            }
        }
    }
    for(unsigned i=0; i<nx; i++){
        for(unsigned j=0; j<ny; j++){
            for(unsigned k=0; k<nz; k++){
                if(v[i][j][k].is0n == true){
                    arq << 4 << " " << 0+cont << " " << 3+cont << " " << 2+cont << " " << 1+cont << " " << fixed << std::setprecision(2) << v[i][j][k].r << " " << fixed << std::setprecision(2) << v[i][j][k].g << " " << fixed << std::setprecision(2) << v[i][j][k].b << " " << fixed << std::setprecision(2) << v[i][j][k].a << endl;
                    arq << 4 << " " << 4+cont << " " << 5+cont << " " << 6+cont << " " << 7+cont << " " << fixed << std::setprecision(2) << v[i][j][k].r << " " << fixed << std::setprecision(2) << v[i][j][k].g << " " << fixed << std::setprecision(2) << v[i][j][k].b << " " << fixed << std::setprecision(2) << v[i][j][k].a << endl;
                    arq << 4 << " " << 0+cont << " " << 1+cont << " " << 5+cont << " " << 4+cont << " " << fixed << std::setprecision(2) << v[i][j][k].r << " " << fixed << std::setprecision(2) << v[i][j][k].g << " " << fixed << std::setprecision(2) << v[i][j][k].b << " " << fixed << std::setprecision(2) << v[i][j][k].a << endl;
                    arq << 4 << " " << 0+cont << " " << 4+cont << " " << 7+cont << " " << 3+cont << " " << fixed << std::setprecision(2) << v[i][j][k].r << " " << fixed << std::setprecision(2) << v[i][j][k].g << " " << fixed << std::setprecision(2) << v[i][j][k].b << " " << fixed << std::setprecision(2) << v[i][j][k].a << endl;
                    arq << 4 << " " << 3+cont << " " << 7+cont << " " << 6+cont << " " << 2+cont << " " << fixed << std::setprecision(2) << v[i][j][k].r << " " << fixed << std::setprecision(2) << v[i][j][k].g << " " << fixed << std::setprecision(2) << v[i][j][k].b << " " << fixed << std::setprecision(2) << v[i][j][k].a << endl;
                    arq << 4 << " " << 1+cont << " " << 2+cont << " " << 6+cont << " " << 5+cont << " " << fixed << std::setprecision(2) << v[i][j][k].r << " " << fixed << std::setprecision(2) << v[i][j][k].g << " " << fixed << std::setprecision(2) << v[i][j][k].b << " " << fixed << std::setprecision(2) << v[i][j][k].a << endl;
                    cont+=8;
                }
            }
        }
    }
    arq.close();
}

