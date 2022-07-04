#ifndef _SCULPTOR_H_
#define _SCULPTOR_H_
#include<iostream>

using namespace std;

struct Voxel{
    float r, g, b;
    float a;
    bool is0n;
};

class Sculptor{
protected:
    unsigned nx, ny, nz;
    float r, g, b, a;
    Voxel ***v;
public:
    Sculptor(unsigned _nx, unsigned _ny, unsigned _nz);
    ~Sculptor();
    void setColor(float _r, float _g, float _b, float alpha);
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    void writeOFF(const char* filename);
};

#endif
