#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "cofo.c"

using namespace std;

int main (){
    int tam =3;
    int db =2;
    cofonum *c;

 c =cofoCreate(tam);
 //cofoInsert(c,1);
 //cout<< c->elms[0];
 cofoInsert(c,2);
 cofoInsert(c,3);
 printf("\n %d  \n",c->nelms);
 cofoRemove(c,2);
 cofoRemove(c,3);
 cofoPesquisa(c,2);
 cofoPesquisa(c,3);
cofoDestroy(c);



return 1;
}
