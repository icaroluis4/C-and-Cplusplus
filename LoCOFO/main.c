#include <stdio.h>
#include <stdlib.h>
#include "Cofo.h"



void main(void){

    cofo *c;
    int elm;
    int stat=0;
    int i;

    c=cofoCreate(30);
    if(c!=NULL){
        for(i=0;i<5;i++){
            scanf("%d",&elm);
            cofoInsert(c,elm);
            printf("%d \n",elm);
        }
    }

    while(stat != -1){
            scanf("%d",&elm);
            stat=cofoQuery(c,elm);
            printf("%d \n",stat);
            if(stat != -1){
                stat = cofoRemove(c,elm);
                printf("%d \n",stat);
            }
            if(c->nemls == 0){
                stat = -1;
            }

    }
    cofDestroy(c);

}
