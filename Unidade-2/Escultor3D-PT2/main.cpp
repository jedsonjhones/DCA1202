#include "FiguraGeometrica.h"
#include "interpretador.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    Sculptor *s1;
    Interpretador parser;
    vector<FiguraGeometrica*> figs;

    figs = parser.parse("Escultura_texto.txt");
    s1 = new Sculptor(parser.getDimx(), parser.getDimy(), parser.getDimz());

    for(size_t i=0; i<figs.size(); i++){
        cout << "draw\n";
        figs[i]->draw(*s1);
    }
    s1->writeOFF("Escultura_desenho.off");

    for(size_t i=0; i<figs.size();i++){
        delete figs[i];
    }
    delete s1;
    return 0;
}
