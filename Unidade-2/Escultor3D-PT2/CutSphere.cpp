#include "CutSphere.h"
#include <iostream>

CutSphere::CutSphere(int xcenter, int ycenter, int zcenter, int radius){
    this->xcenter=xcenter; this->ycenter=ycenter; this->zcenter=zcenter; this->radius=radius;
}

void CutSphere::draw(Sculptor &t){
    double calc;
    int x, y, z;
    calc = radius*radius;
    for(x=xcenter-radius; x<xcenter+radius; x++){
        for(y=ycenter-radius; y<ycenter+radius; y++){
            for(z=zcenter-radius; z<zcenter+radius; z++){
                if(static_cast<double>(x-xcenter)*static_cast<double>(x-xcenter)+
                   static_cast<double>(y-ycenter)*static_cast<double>(y-ycenter)+
                   static_cast<double>(z-zcenter)*static_cast<double>(z-zcenter) < calc){
                    t.cutVoxel(x,y,z);
                   }
            }
        }
    }
 }

