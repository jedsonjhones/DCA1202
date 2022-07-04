#ifndef _CUTSPHERE_H_
#define _CUTSPHERE_H_
#include <iostream>
#include "FiguraGeometrica.h"

class CutSphere : public FiguraGeometrica{
    int xcenter, ycenter, zcenter, radius;
public:
    CutSphere(int xcenter, int ycenter, int zcenter, int radius);
    ~CutSphere(){}
    void draw(Sculptor &t);
};

#endif // _CUTSPHERE_H_
