#ifndef _CUTVOXEL_H_
#define _CUTVOXEL_H_
#include <iostream>
#include "FiguraGeometrica.h"

class cutVoxel : public FiguraGeometrica{
    int x, y, z;
public:
    cutVoxel(int x, int y, int z);
    ~cutVoxel(){}
    void draw(Sculptor &t);
};

#endif // _CUTVOXEL_H_
