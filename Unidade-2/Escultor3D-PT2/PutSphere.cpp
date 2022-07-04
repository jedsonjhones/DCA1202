#include "PutSphere.h"
#include <iostream>

PutSphere::PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a){
    this->xcenter=xcenter; this->ycenter=ycenter; this->zcenter=zcenter; this->radius=radius;
    this->r=r; this->g=g; this->b=b; this->a=a;
}

void PutSphere::draw(Sculptor &t){
    double calc;
    int x, y, z;
    calc = radius*radius;
    t.setColor(r,g,b,a);
    for(x=xcenter-radius; x<xcenter+radius; x++){
        for(y=ycenter-radius; y<ycenter+radius; y++){
            for(z=zcenter-radius; z<zcenter+radius; z++){
                if(static_cast<double>(x-xcenter)*static_cast<double>(x-xcenter)+
                   static_cast<double>(y-ycenter)*static_cast<double>(y-ycenter)+
                   static_cast<double>(z-zcenter)*static_cast<double>(z-zcenter) < calc){
                    t.putVoxel(x,y,z);
                   }
            }
        }
    }
 }

