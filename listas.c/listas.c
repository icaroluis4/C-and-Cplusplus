#ifndef _LISTAS_C_
#define _LISTAS_C_
#include "listas.h"

#include <stdio.h>
#include <stdlib.h>







    //CRIAR LISTA DLL VAZIA
dllist *dllCreate () {
    dllist *l;
   // printf("TO AQUI");
    l = (dllist*) malloc(sizeof(dllist));
    if (l != NULL) {
           // printf("FOI2");
        l->first = NULL;
        return l;

    }
   // printf("FOI N");
    return NULL;


}


    // INSERIR COMO PRIMEIRO
int dllInsertFirst (dllist *l, void *data) {
    dlnode *newnode;
    dlnode *aux;

    if (l!=NULL) {
        newnode = (dlnode*) malloc(sizeof(dlnode));
        if(l->first == NULL && newnode != NULL){
            newnode->data = data;
            l->first = newnode;
            l->first->prev = NULL;
            l->first->next = NULL;

            return TRUE;
        }
        else
        if (newnode != NULL){
            newnode->data = data;
            aux = l->first;
            l->first = newnode;
            l->first->next = aux;
            l->first->prev = NULL;
            aux->prev = l->first;

            return TRUE;
        }
    }
    return FALSE;
}

    //FUNÇÃO CMP

    int cmp(void* a, void *b){
    if( a == b )
        return 1;
    else
        return 0;

}


    //INSERIR APÓS O SPEC
int dllInsertAfterSpec(dllist *l, void *data, int (*cmp)(void*, void*), void *key){
    dlnode *spec, *next;
    dlnode *newnode;
    int stat;

    if (l!=NULL) {
        if (l->first!=NULL){
            spec = l->first;
            stat = cmp(spec->data, key);
            while (stat!=TRUE && spec->next!=NULL){
                spec=spec->next;
                stat=cmp(spec->data, key);
                next = spec->next;
            }
            if (stat==TRUE){
                newnode=(dlnode*)malloc(sizeof(dlnode));
                if(newnode!=NULL){
                    newnode->data=data;
                    newnode->next=next;
                    newnode->prev=spec;
                    if(next!=NULL){
                        next->prev=newnode;
                    }
                    spec->next=newnode;
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}


        //INSERIR ANTES DO SPEC
int dllInsertBeforeSpec(dllist *l, void*data, int (*cmp)(void*, void*), void *key){

    dlnode *spec, *next, *prev;
    dlnode *newnode;
    int stat;

    if(l!=NULL){
        if(l->first!=NULL){
            spec = l->first;
            stat=cmp(spec->data, key);
            //printf("HELOLOL");
            while(stat!=TRUE && spec->next!=NULL){
                    prev = spec;
                spec=spec->next;
                stat=cmp(spec->data, key);
                next = spec ->next;
             }
             if(stat==TRUE){
                newnode=(dlnode*)malloc(sizeof(dlnode));
                if(newnode!=NULL){
                    newnode->data=data;
                    prev->next=newnode;
                    newnode->next=spec;
                    newnode->prev=prev;
                    spec->prev=newnode;
                    if(prev!=NULL){
                        prev->next=newnode;
                    }else{
                        l->first=newnode;
                    }
                    return TRUE;
                }
             }
        }
    }
    return FALSE;
}




    //REMOVER O PRIMEIRO
void *dllRemoveFirst (dllist *l) {
    dlnode *aux;
    void *data;

    if (l != NULL) {
        if (l->first != NULL){
            aux = l->first;
            data = aux->data;
            l->first = aux->next;
            l->first->prev=NULL;
            free (aux);
            return data;
        }
    }
    return NULL;
}



    //REMOVER O SPEC
void *dllRemoveSpec (dllist *l,int(*cmp)(void*, void*), void *key){

    dlnode *spec;
    dlnode *prev, *next;
    int stat; void * data;

    if (l!=NULL){
        if (l->first!=NULL){
            spec = l->first;
            stat=cmp(spec->data, key);
            while(stat!=TRUE && spec->next!=NULL) {
                prev =spec;
                spec=spec->next;
                stat=cmp(spec->data, key);
                next = spec->next;
            }
            if (stat==TRUE){
                data=spec->data;
                if(next!=NULL){
                    next->prev=prev;
                }
                if (prev!=NULL){
                    prev->next=next;
                }else{
                    l->first=next;
                }
                free (spec);
                return data;
            }
        }
    }
    return NULL;
}



    //BUSCAR O ELEMENTO

int dllQuery(dllist *l,void * key){
        dlnode *aux;
        int stat;
        if(l!= NULL){
            if(l->first !=NULL){
                aux = l->first;
                stat = cmp(aux->data,key);

                while(aux !=NULL && stat !=TRUE){
                    aux = aux->next;
                    stat = cmp(aux->data,key);
                }
                if(stat ==TRUE){
                    return TRUE;
                }
            }
        }
    return -1;


}
    //DESTRUIR LISTA DLL VAZIA
 int dllDestroy (dllist *l) {
    if (l!=NULL) {
        if (l->first!= NULL){
            free(l);
            return TRUE;
        }
    }
    return FALSE;
}



    //EXIBIR A LISTA
void dllShow(dllist *l){

    dlnode *aux;
    if(l!=NULL){
        if(l->first){
            aux=l->first;
            while(aux!=NULL){
                printf(" - %d -", aux->data);
                aux=aux->next;
            }
        }else{
            printf ("A LISTA ESTA VAZIA");
          }
    }

  }





#endif
