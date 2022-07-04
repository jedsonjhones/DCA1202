#ifndef _FIGURAGEOMETRICA_H
#define _FIGURAGEOMETRICA_H
#include "sculptor.h"

class FiguraGeometrica{
protected:
    float r, g, b, a;
public:
    virtual ~FiguraGeometrica(){}
    virtual void draw(Sculptor &t) = 0;
};
#endif // _FIGURAGEOMETRICA_H
