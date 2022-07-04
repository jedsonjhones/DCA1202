#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "Interpretador.h"
#include "PutVoxel.h"
#include "CutVoxel.h"
#include "PutBox.h"
#include "CutBox.h"
#include "PutSphere.h"
#include "CutSphere.h"
#include "PutEllipsoid.h"
#include "CutEllipsoid.h"

using namespace std;

Interpretador::Interpretador(){}

int Interpretador::getDimx(){ return dimx; }

int Interpretador::getDimy(){ return dimy; }

int Interpretador::getDimz(){ return dimz; }


vector<FiguraGeometrica*> Interpretador::parse(string filename){
    vector<FiguraGeometrica*> figs;
    ifstream filein;
    stringstream ss;
    string s, token;

    filein.open(filename);
    if(!filein.is_open()){
        cout << "O arquivo " << filename <<" nao foi aberto\n";
        exit(0);
    }

    while(filein.good()){
        getline(filein, s);
        if(filein.good()){
            ss.clear();
            ss.str(s);
            ss >> token;
            if(ss.good()){
                if(token.compare("dim")==0){
                    ss >> dimx >> dimy >> dimz;
                }else if(token.compare("putvoxel")==0){
                    int x, y, z;
                    ss >> x >> y >> z >> r >> g >> b >> a;
                    figs.push_back(new putVoxel(x, y, z, r, g, b, a));
                }else if(token.compare("cutvoxel")==0){
                    int x, y, z;
                    ss >> x >> y >> z;
                    figs.push_back(new cutVoxel(x, y, z));
                }else if(token.compare("putbox")==0){
                    int x0, y0, z0, x1, y1, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                    figs.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
                }else if(token.compare("cutbox")==0){
                    int x0, y0, z0, x1, y1, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                    figs.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
                }else if(token.compare("putsphere")==0){
                    int x, y, z, raio;
                    ss >> x >> y >> z >> raio >> r >> g >> b >> a;
                    figs.push_back(new PutSphere(x, y, z, raio, r, g, b, a));
                }else if(token.compare("cutsphere")==0){
                    int x, y, z, raio;
                    ss >> x >> y >> z >> raio;
                    figs.push_back(new CutSphere(x, y, z, raio));
                }else if(token.compare("putellipsoid")==0){
                    int x, y, z, rx, ry, rz;
                    ss >> x >> y >> z >> rx >> ry >> rz >> r >> g >> b >> a;
                    figs.push_back(new PutEllipsoid(x, y, z, rx, ry, rz, r, g, b, a));
                }else if(token.compare("cutellipsoid")==0){
                    int x, y, z, rx, ry, rz;
                    ss >> x >> y >> z >> rx >> ry >> rz;
                    figs.push_back(new CutEllipsoid(x, y, z, rx, ry, rz));
                }
            }
        }
    }
    //figs.push_back(new putVoxel(0, 0, 0, 0.0, 0.0, 0.0, 0.0));
    return(figs);
}
