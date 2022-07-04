#ifndef _CUTBOX_H_
#define _CUTBOX_H_
#include <iostream>
#include "FiguraGeometrica.h"

class CutBox : public FiguraGeometrica{
    int x0, y0, z0, x1, y1, z1;
public:
    CutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    ~CutBox(){}
    void draw(Sculptor &t);
};

#endif // _CUTBOX_H_
