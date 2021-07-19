#include <stdio.h>
#include <stdlib.h>


typedef struct _slnode_{

    void* data;
    struct _slnode_ * next;


}slnode;


typedef struct _sllist_{
    slnode* first;


}sllist;

sllist * sllCreate(){
    sllist *l;
    l=(sllist*)malloc(sizeof(sllist));
    if(l!=NULL){
        l->first = NULL;
        return l;
    }

    return NULL;
}


int sllInsertFirst(sllist * l,void *data){
    slnode *newnode;
    if(l !=NULL){
        newnode = (slnode*)malloc(sizeof(slnode));
        if(newnode!= NULL){
            newnode->data = data;
            newnode->next = l->first;
            l->first = newnode;
            return 1;
        }


    }
    return 0;


}

int sllnumelms(sllist *l){
    int cont=0;
    slnode* aux;

    if(l!=NULL && l->first !=NULL){
        aux = l->first;

        while(aux != NULL){
            aux = aux->next;
            cont++;
        }
        return cont;

    }
    return 0;
}

void sllShow(sllist *l){
    slnode *aux;

    if(l!=NULL && l->first !=NULL){
        aux = l->first;

        while(aux != NULL){
            printf(" %d",aux->data);
            aux = aux->next;
        }

    }
}

int cmp ( void * a , void * b){

        if( a  == b){
            return 1;
        }
        if( a != b){
            return 0;
        }
}


void* sllRemoveAfterSpec(sllist *l, void * key, int(*cmp)(void*,void*)){

    slnode *spec,*after=NULL;
    int stat;
    void* data;

            if(l != NULL){
                spec = l->first;
                stat = cmp(spec->data,key);
                while( spec !=NULL && stat!=1){
                    spec = spec->next;
                    after = spec->next;
                    stat=cmp(spec->data,key);

                }
                if(stat==1){
                    spec->next = after->next;
                    data = after->data;
                    after->next = NULL;
                    free(after);
                    return data;

                }
            }
            return NULL;

}

void* sllRemoveNensimo(sllist *l, int n){
        slnode *aux,*prev=NULL;
        void* data;
        int cont=1;

    if(l!=NULL){
        if(l->first !=NULL){
            aux = l->first;
            while(aux !=NULL && cont != n){
                prev=aux;
                aux = aux->next;
                cont++;
            }
            if(cont == n){
                   data = aux->data;
                   prev->next = aux->next;
                   aux->next = NULL;
                   free(aux);
                   return data;

            }
        }
        return NULL;

    }

}

int sllRemoveSpecENext(sllist *l, void * key, (*cmp)(void*,void*)){
        slnode *after,*prev = NULL,*spec;
        void* data; int stat;

        if(l!=NULL){
            if(l->first != NULL){
                  spec = l->first;
                  after =spec ->next;
                  stat = cmp(spec->data,key)

                  while(spec !=NULL && stat!=1){
                        prev = spec;
                        spec = spec->next;
                        after = spec->next;
                        stat = cmp(spec->data,key);
                  }
                  if(stat == 1){


                  }
            }

        }

}


void main(void){


 sllist *l;

 l = sllCreate();



sllInsertFirst(l , 2);
sllInsertFirst(l,3);
sllInsertFirst(l,34);
sllInsertFirst(l,55);
sllInsertFirst(l,102);
sllShow(l);
printf(" \n");
sllRemoveNensimo(l,3);
sllShow(l);
sllRemoveAfterSpec(l,34,cmp(l->first,34));
//sllShow(l);
printf( " \n O numero de NOdes em l é : %d",sllnumelms(l));






}
