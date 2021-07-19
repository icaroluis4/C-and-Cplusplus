#include <stdio.h>
#include <stdlib.h>


int  ordenaVetor(int *p1, int *p2){
        if(*p1 == *p2){
           return 0;
        }
        else if(*p1 > *p2){
            return 1;
        }
        else if(*p1 < *p2){
            return -1;
        }
}

int *criaVetorOrdena(int tam){
    int *v,i;

    v = (int *)malloc(sizeof(int)*tam);
    if(v!=NULL){
        for(i=0;i<tam;i++){
            scanf("%d",&v[i]);

        }
        qsort(v,tam,sizeof(int),ordenaVetor);

        for(i=0 ; i<tam ; i++){
        printf("%d \n",v[i]);
        }
        return v;
    }
    return NULL;
}

void main(void){

    int tam,*v;
    scanf("%d",&tam);
    v =criaVetorOrdena(tam);
    printf("\n Qsort Vetor \n");
    free(v);
}
