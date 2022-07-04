#include <fstream>
#include <string>
#include <iomanip>
#include "escultor.h"

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

 void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i=x0; i<x1; i++){
        for(int j=y0; j<y1; j++){
            for(int k=z0; k<z1; k++){
                v[i][j][k].a = a;
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].is0n = true;
            }
        }
    }
 }

 void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i=x0; i<x1; i++) for(int j=y0; j<y1; j++) for(int k=z0; k<z1; k++) v[i][j][k].is0n = false;
 }

 void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    int x=nx, y=ny, z=nz;
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            for(int k=0; k<z; k++){
                if(((i-xcenter)^2) + ((j-ycenter)^2) + ((k-zcenter)^2) <= (radius^2)){
                    v[i][j][k].a = a;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].is0n = true;
                }
            }
        }
    }
 }

 void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    int x=nx, y=ny, z=nz;
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            for(int k=0; k<z; k++){
                if(((i-xcenter)^2) + ((j-ycenter)^2) + ((k-zcenter)^2) <= (radius^2)){
                    v[i][j][k].is0n = false;
                }
            }
        }
    }
 }

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    int x=nx, y=ny, z=nz;
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            for(int k=0; k<z; k++){
                if((((i-xcenter)^2)/(rx^2)) + (((j-ycenter)^2)/(ry^2)) + (((k-zcenter)^2)/(rz^2)) <= 1){
                    v[i][j][k].a = a;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].is0n = true;
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    int x=nx, y=ny, z=nz;
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            for(int k=0; k<z; k++){
                if((((i-xcenter)^2)/(rx^2)) + (((j-ycenter)^2)/(ry^2)) + (((k-zcenter)^2)/(rz^2)) <= 1){
                    v[i][j][k].is0n = false;
                }
            }
        }
    }
}

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
                    arq << 4 << " " << 0+cont << " " << 3+cont << " " << 2+cont << " " << 1+cont << " "<<fixed<<std::setprecision(2) << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    arq << 4 << " " << 4+cont << " " << 5+cont << " " << 6+cont << " " << 7+cont << " "<<fixed<<std::setprecision(2) << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    arq << 4 << " " << 0+cont << " " << 1+cont << " " << 5+cont << " " << 4+cont << " "<<fixed<<std::setprecision(2) << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    arq << 4 << " " << 0+cont << " " << 4+cont << " " << 7+cont << " " << 3+cont << " "<<fixed<<std::setprecision(2) << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    arq << 4 << " " << 3+cont << " " << 7+cont << " " << 6+cont << " " << 2+cont << " "<<fixed<<std::setprecision(2) << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    arq << 4 << " " << 1+cont << " " << 2+cont << " " << 6+cont << " " << 5+cont << " "<<fixed<<std::setprecision(2) << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    cont+=8;
                }
            }
        }
    }
    arq.close();
}

