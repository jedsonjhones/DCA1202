#include "sculptor3d.h"

Sculptor3D::Sculptor3D(int _nx, int _ny, int _nz){
    cout << "alocou"<<endl;
    nx = _nx;
    ny = _ny;
    nz = _nz;
    imagemVox = new Voxel **[nx];
    for(int i=0; i<nx;i++){
        imagemVox[i] = new Voxel *[ny];
        for(int j=0; j<ny;j++){
            imagemVox[i][j] = new Voxel[nz];
        }
    }
    for(int i = 0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                imagemVox[i][j][k].isOn = false;
                imagemVox[i][j][k].r = 0;
                imagemVox[i][j][k].g = 0;
                imagemVox[i][j][k].b = 0;
                imagemVox[i][j][k].a = 0;
            }
        }
    }
}

Sculptor3D::~Sculptor3D(){
    for(int i=0;i<nx;i++) {
            for(int j=0;j<ny;j++){
                delete[] imagemVox[i][j];
            }
                delete[] imagemVox[i];
            }
        delete[] imagemVox;
    cout << "alocou"<<endl;
}

int Sculptor3D::getX(){
    return nx;
}
int Sculptor3D::getY(){
    return ny;
}
void Sculptor3D::setColor(float _r, float _g, float _b, float alpha){
   r = _r;
   g = _g;
   b = _b;
   a = alpha;
}
vector <vector<Voxel>> Sculptor3D::getPlano(int _z){
    m.clear();
    for(int i=0;i<nx;i++) {

        for(int j=0;j<ny;j++){
        maux.push_back(imagemVox[i][j][_z]);
        }
        m.push_back(maux);
        maux.clear();
    }
    return m;
}
void Sculptor3D::putVoxel(int x, int y, int z)
{
    imagemVox[x][y][z].isOn = true;
    imagemVox[x][y][z].r = r;
    imagemVox[x][y][z].g = g;
    imagemVox[x][y][z].b = b;
    imagemVox[x][y][z].a = a;
}
void Sculptor3D::cutVoxel(int x, int y, int z)
{
    imagemVox[x][y][z].isOn = false;
}
void Sculptor3D::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    for(int i = 0;i<nx;i++){
        for(int j=0;j<ny;j++){
           for(int k=0;k<nz;k++){
                    if((pow(i-xcenter,2)+pow(j-ycenter,2)+pow(k-zcenter,2)) <= pow(radius,2)){
                    imagemVox[i][j][k].isOn = true;
                    imagemVox[i][j][k].r = r;
                    imagemVox[i][j][k].g = g;
                    imagemVox[i][j][k].b = b;
                    imagemVox[i][j][k].a = a;
                }
            }
        }
    }
}
void Sculptor3D::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    for(int i = 0;i<nx;i++){
        for(int j=0;j<ny;j++){
           for(int k=0;k<nz;k++){
                    if((pow(i-xcenter,2)+pow(j-ycenter,2)+pow(k-zcenter,2)) <= pow(radius,2)){
                    imagemVox[i][j][k].isOn = false;
                }
            }
        }
    }
}
void Sculptor3D::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for(int i = x0;i<=x1;i++){
        for(int j=y0;j<=y1;j++){
            for(int k=z0;k<=z1;k++){
                if(i>=0 && j>=0 && k>=0 && i<nx && j<ny && k<nz){

                    imagemVox[i][j][k].isOn = true;
                    imagemVox[i][j][k].r = r;
                    imagemVox[i][j][k].g = g;
                    imagemVox[i][j][k].b = b;
                    imagemVox[i][j][k].a = a;
                }
            }
        }
    }
}
void Sculptor3D::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for(int i = x0;i<=x1;i++){
        for(int j=y0;j<=y1;j++){
            for(int k=z0;k<=z1;k++){
                if(i>=0 && j>=0 && k>=0 && i<nx && j<ny && k<nz){

                    imagemVox[i][j][k].isOn = false;

                }
            }
        }
    }
}
void Sculptor3D::writeOFF(char* filename){

    int v1=0 , v2=1, v3=2, v4=3, v5=4, v6=5, v7=6, v8=7;
    int cont = 0;
    ofstream arq;
    arq.open(filename);
    arq<<"OFF\n";

    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                if(imagemVox[i][j][k].isOn == true){
                     cont = cont +1;
                    //cout <<"i = " <<i<<" j = "<<j<<" k = "<<k<<"    -> "<< imagemVox[i][j][k].isOn<<endl;
                }
            }
        }
    }

    arq<<cont*8<<" "<<cont*6<<" "<<0<<"\n";
    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                if(imagemVox[i][j][k].isOn == true){
                     arq<<i + (-0.5)<<" "<<j + (0.5)<<" "<<k + (-0.5)<<"\n";
                     arq<<i + (-0.5)<<" "<<j + (-0.5)<<" "<<k + (-0.5)<<"\n";
                     arq<<i + (0.5)<<" "<<j + (-0.5)<<" "<<k + (-0.5)<<"\n";
                     arq<<i + (0.5)<<" "<<j + (0.5)<<" "<<k + (-0.5)<<"\n";
                     arq<<i + (-0.5)<<" "<<j + (0.5)<<" "<<k + (0.5)<<"\n";
                     arq<<i + (-0.5)<<" "<<j + (-0.5)<<" "<<k + (0.5)<<"\n";
                     arq<<i + (0.5)<<" "<<j + (-0.5)<<" "<<k + (0.5)<<"\n";
                     arq<<i + (0.5)<<" "<<j + (0.5)<<" "<<k + (0.5)<<"\n";
                }
            }
        }
    }
    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                if(imagemVox[i][j][k].isOn == true){
                    arq<<4<<" "<<v1<<" "<<v4<<" "<<v3<<" "<<v2<<" "<<imagemVox[i][j][k].r<<" "<<imagemVox[i][j][k].g<<" "<<imagemVox[i][j][k].b<<" "<<imagemVox[i][j][k].a<<"\n";
                    arq<<4<<" "<<v5<<" "<<v6<<" "<<v7<<" "<<v8<<" "<<imagemVox[i][j][k].r<<" "<<imagemVox[i][j][k].g<<" "<<imagemVox[i][j][k].b<<" "<<imagemVox[i][j][k].a<<"\n";
                    arq<<4<<" "<<v1<<" "<<v2<<" "<<v6<<" "<<v5<<" "<<imagemVox[i][j][k].r<<" "<<imagemVox[i][j][k].g<<" "<<imagemVox[i][j][k].b<<" "<<imagemVox[i][j][k].a<<"\n";
                    arq<<4<<" "<<v1<<" "<<v5<<" "<<v8<<" "<<v4<<" "<<imagemVox[i][j][k].r<<" "<<imagemVox[i][j][k].g<<" "<<imagemVox[i][j][k].b<<" "<<imagemVox[i][j][k].a<<"\n";
                    arq<<4<<" "<<v4<<" "<<v8<<" "<<v7<<" "<<v3<<" "<<imagemVox[i][j][k].r<<" "<<imagemVox[i][j][k].g<<" "<<imagemVox[i][j][k].b<<" "<<imagemVox[i][j][k].a<<"\n";
                    arq<<4<<" "<<v2<<" "<<v3<<" "<<v7<<" "<<v6<<" "<<imagemVox[i][j][k].r<<" "<<imagemVox[i][j][k].g<<" "<<imagemVox[i][j][k].b<<" "<<imagemVox[i][j][k].a<<"\n";
                    v1+=8;
                    v2+=8;
                    v3+=8;
                    v4+=8;
                    v5+=8;
                    v6+=8;
                    v7+=8;
                    v8+=8;
                }
            }
        }
    }
}
