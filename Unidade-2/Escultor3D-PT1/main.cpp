#include <iostream>
#include <fstream>
#include <string.h>
#include "escultor.h"

using namespace std;

int main()
{

    Sculptor espada(60,60,60);
    espada.setColor(0.1,0.1,0.1,1.0);
    espada.putBox(0,11,0,11,0,8);
    espada.cutBox(8,11,8,11,0,8);
    espada.cutBox(3,8,3,8,0,8);
    espada.putVoxel(4,4,4);
    espada.putVoxel(5,4,4);
    espada.putVoxel(6,4,4);
    espada.putVoxel(4,5,4);
    espada.putVoxel(5,5,4);
    espada.putVoxel(6,5,4);
    espada.putVoxel(4,6,4);
    espada.putVoxel(5,6,4);
    espada.putVoxel(6,6,4);
    espada.cutVoxel(5,5,4);
    espada.putVoxel(7,3,4);
    espada.putVoxel(3,7,4);
    espada.setColor(0.4,0.2,0.1,1.0);
    espada.putBox(8,15,8,15,0,8);
    espada.cutBox(13,15,13,15,0,8);
    espada.putBox(13,20,13,20,0,8);
    espada.setColor(0,0,0.9,1.0);
    espada.putBox(20,27,17,24,0,8);
    espada.putBox(27,34,10,17,0,8);
    espada.putBox(34,41,10,17,0,8);
    espada.putBox(27,34,17,24,0,8);
    espada.putBox(34,41,3,10,0,8);
    espada.putBox(17,24,20,27,0,8);
    espada.putBox(17,24,27,34,0,8);
    espada.putBox(10,17,27,34,0,8);
    espada.putBox(10,17,34,41,0,8);
    espada.putBox(3,10,34,41,0,8);
    espada.putBox(24,34,20,34,0,8);
    espada.cutBox(20,30,20,30,0,8);
    espada.putBox(30,39,30,39,0,8);
    espada.putBox(35,44,35,44,0,8);
    espada.putBox(40,49,40,49,0,8);
    espada.putBox(45,54,45,54,0,8);
    espada.writeOFF("espada.off");

    return 0;
}
