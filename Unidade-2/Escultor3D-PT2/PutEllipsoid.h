#ifndef _PUTELLIPSOID_H_
#define _PUTELLIPSOID_H_
#include <iostream>
#include "FiguraGeometrica.h"

class PutEllipsoid : public FiguraGeometrica{
    int xcenter, ycenter, zcenter, rx, ry, rz;
public:
    PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);
    ~PutEllipsoid(){}
    void draw(Sculptor &t);
};

#endif // _PUTELLIPSOID_H_
