#include <stdlib.h>
#include "Cofo.h"

 cofo * cofoCreate(int n){
        cofo *c;
        c = (cofo*)malloc(sizeof(cofo));
        if(c!=NULL){
            c->elms = (void*)malloc(sizeof(void*)*n);
            if(c->elms != NULL){
                c->nemls = 0;
                c->tam = n;
                return c;
            }
            else
                free(c);

        }
        return NULL;


 }

int cofDestroy(cofo * c){

    if(c!=NULL){
        if(c->nemls == 0){
            free(c->elms);
            free(c);
            return 1;
        }

    }
    return 0;

}

int cofoInsert(cofo *c, void* elm){

        if(c!=NULL){
            if(c->nemls < c->tam-1){
                c->elms[c->nemls] = elm;
                c->nemls ++;
                return 1;
            }

        }
        return 0;
}

int cofoRemove(cofo *c,void*key){
            void *aux;
            int i=0,j;
        if(c!=NULL){
            if(c->elms !=NULL && c->nemls >0){

                while(i < c->nemls && key!= c->elms[i]){
                    i++;

                }
                if(key == c->elms[i]){
                        aux = c->elms[i];
                    for(j = 0;j<c->nemls-1;j++){
                        c->elms[j] = c->elms[j+1];
                    }
                    c->nemls --;
                    return 1;
                }
            }
        }
        return 0;

}

int cofoQuery(cofo *c,void*key){
    int i=0;

        if(c!=NULL){
            if(c->elms !=NULL ){

                while(i < c->nemls && key!= c->elms[i]){
                    i++;

                }
                if(key == c->elms[i]){
                    return 1;
                }
            }
        }
        return 0;
}
