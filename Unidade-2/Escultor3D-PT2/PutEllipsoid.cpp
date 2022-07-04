#include "PutEllipsoid.h"
#include <iostream>

PutEllipsoid::PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a){
    this->xcenter = xcenter; this->ycenter = ycenter; this->zcenter = zcenter; this->rx=rx; this->ry=ry; this->rz=rz;
    this->r = r; this->g = g; this->b = b; this->a = a;
}

void PutEllipsoid::draw(Sculptor &t){
    int x, y, z;
    t.setColor(r,g,b,a);

    for(x=xcenter-rx; x<xcenter+rx; x++){
        for(y=ycenter-ry; y<ycenter+ry; y++){
            for(z=zcenter-rz; z<zcenter+rz; z++){
                if((static_cast<double>(x-xcenter)*static_cast<double>(x-xcenter))/(static_cast<double>(rx)*static_cast<double>(rx))+
                   (static_cast<double>(y-ycenter)*static_cast<double>(y-ycenter))/(static_cast<double>(ry)*static_cast<double>(ry))+
                   (static_cast<double>(z-zcenter)*static_cast<double>(z-xcenter))/(static_cast<double>(rz)*static_cast<double>(rz)) < 1){
                    t.putVoxel(x,y,z);
                   }
            }
        }
    }

}



