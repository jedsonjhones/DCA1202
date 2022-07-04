#include "CutEllipsoid.h"
#include <iostream>

CutEllipsoid::CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    this->xcenter = xcenter; this->ycenter = ycenter; this->zcenter = zcenter;
    this->rx=rx; this->ry=ry; this->rz=rz;
}

void CutEllipsoid::draw(Sculptor &t){
    int x, y, z;
    for(x=xcenter-rx; x<xcenter+rx; x++){
        for(y=ycenter-ry; y<ycenter+ry; y++){
            for(z=zcenter-rz; z<zcenter+rz; z++){
                if((static_cast<double>(x-xcenter)*static_cast<double>(x-xcenter))/(static_cast<double>(rx)*static_cast<double>(rx))+
                   (static_cast<double>(y-ycenter)*static_cast<double>(y-ycenter))/(static_cast<double>(ry)*static_cast<double>(ry))+
                   (static_cast<double>(z-zcenter)*static_cast<double>(z-xcenter))/(static_cast<double>(rz)*static_cast<double>(rz)) < 1){
                    t.cutVoxel(x,y,z);
                   }
            }
        }
    }

}
