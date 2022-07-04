#ifndef _INTERPRETADOR_H_
#define _INTERPRETADOR_H_
#include "FiguraGeometrica.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Interpretador{
    int dimx, dimy, dimz;
    float r, g, b, a;
public:
    Interpretador();
    vector<FiguraGeometrica*> parse(string filename);
    int getDimx();
    int getDimy();
    int getDimz();
};

#endif // _INTERPRETADOR_H_
