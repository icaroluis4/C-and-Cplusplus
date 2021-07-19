
#ifndef _cofo_c
#define _cofo_c
    #include <stdlib.h>
    #include <stdio.h>
    #include "cofo.h"

        cofonum *cofoCreate(int tam){
            cofonum *c;
            if(tam > 0){
                c=(cofonum *)malloc(sizeof(cofonum));
                if(c!=NULL){
                    c->elms = (int *)malloc(sizeof(int)*tam);
                    if(c->elms!=NULL){
                        c-> nelms = 0;
                        c-> nmax = tam;
                    }
                    else{
                        printf("Nokayt");
                        free(c);
                        return NULL;

                    }
                    printf("OKay \n");
                    return c;
                }
                return NULL;
            }
        }

         int cofoInsert(cofonum *c, int elm){
             if(c!=NULL){
                if(c->nelms<c->nmax){
                    c->elms[c->nelms] = elm;
                    c->nelms++;
                    printf("inserido %d  \n",c->nelms);
                    return 1;
                }

             }
             return 0;
         }

         int cofoRemove(cofonum *c , int key){
            int i = 0,j=0;
            int elm=0;
            //printf("d% /n",c->nelms);
            //printf("OI");
            //printf("%d",c->nelms);
            while ( i < c->nelms && key!= c->elms[i]){
                i++;
            }
            //printf("OI2");
            if(key == c->elms[i]){
              //      printf("OI3");
                    elm = c->elms[i];
                for(j=i;j<c->nelms-1;j++){
                    c->elms[j] = c->elms[j+1];
                }
                c->nelms--;
                printf("removido %d \n",elm);
                return elm;
            }
                return 0;
         }

         int cofoPesquisa(cofonum *c,int key){
                int i=0;

                while (i < c->nelms && key!= c->elms[i]){
                    i++;
                }
                if(key == c->elms[i]){
                    printf("\n Achado %d \n", key);
                    return 1;
                }
                printf(" \n Nao achado");
                return 0;
         }

           int cofoDestroy(cofonum * c){
                if(c!=NULL){
                    if(c->nelms==0){
                        if(c->elms!=NULL){
                            free(c);
                            printf("LIBERADO");
                            return 1;
                        }
                    }

                }
                return 0;
         }

#endif // _cofo_c
