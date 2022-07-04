#include <stdio.h>

int main () {
    int i = 3, j = 5;
    int * p, * q;
    p = & i; // p recebe o endere�o da vari�vel i;
    q = & j; // q recebe o endere�o da vari�vel j;
    p == & i; // p � igual ao endere�o de i;
    * p - * q; // conteudo do endere�o armazenado em p - conteudo do endere�o armazenado em q => 3 - 5 = -2;
    ** & p; // aciona o conteudo do endere�o do ponteiro p (* & p), que � o endere�o da variavel i, e ent�o aciona seu conteudo (** & p), mostrando o valor armazendo em i que � 3;
    3 - * p / (* q) + 7; // 3 - 3/5 + 7 => 3 - 0 + 7 = 10;

    return 0;
}
