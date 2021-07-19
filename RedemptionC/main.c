#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _SLnode_{
    void* data;
    _SLnode_ *next;
    _SLnode_ *prev;
}Slnode;

typedef struct SLlist{
    SLnode *first;
}

SLlist* sllCreate(){ //Cria lista
    SLlist *l;
    l=(SLlist*) malloc(sizeof(SLlist));
    if(l!=NULL)
    {
        l->first=NULL;
        return l;
    }
}

void* sllGetFirst(SLlist *tmp){ //pega a primeira posição da lista
    if(tmp != NULL){
        if(tmp->first != NULL){
            tmp->cur = tmp->first;
            return tmp->cur->data;
        }
    }
    return NULL;
}

void* sllGetNext(SLlist *tmp){//pega o proximo nó, caso exitas
    if(tmp != NULL){
        if(tmp->cur != NULL){
            tmp->cur = tmp->cur->prox;
            if(tmp->cur != NULL){
                return tmp->cur->data;
            }
        }
    }
    return NULL;
}

void *sllQuery(SLlist *tmp, void* key,int (*cmp)(void*,void*)){ //busca um elemento caso tenha dentro da lista com auxilio de outra funcao

    SLnode *cur;
    if(tmp!=NULL){
        if(tmp->first != NULL){
            cur = tmp->first;
            while(cmp(key,cur->data) != TRUE && cur->prox != NULL){ // para se achar ou se chegar ao final
                cur = cur->prox;
            }
            if (cmp(key,cur->data) == TRUE){
                return cur->data;
            }
        }
    }
    return NULL;
}


int sllDestroy(SLlist *l){ //destroy a lista

    if(l != NULL){
        if(l->first != NULL){
            SLnode* aux = l->first;
            SLnode* next = aux->prox;
            while(next != NULL){
                free(aux);
                next = next->prox;  //guarda o proximo pra não perder a lista
                aux->prox = next;
            }
            free(next);
            return TRUE;
        }
    }
    return FALSE;

}
int sllInsertLast(SLlist *l,void *elm){  //insere no começo da lista
    SLnode *novo,*p;
    if(l!=NULL){
        if(l->first ==NULL){
            novo = (SLnode*) malloc(sizeof(SLnode));
            if(novo!=NULL)
            {novo->data = elm;
                novo->prox = NULL;
                l->first=novo;
                return TRUE;
            }else{
                return FALSE;
            }
        }
        else{
            novo = (SLnode*) malloc(sizeof(SLnode));
            if(novo!=NULL){
                novo->data=elm;
                novo->prox=NULL;
                p = l->first;
                while(p->prox!=NULL){
                    p=p->prox;
                }
                p->prox=novo;
                return TRUE;
            }else{
                return FALSE;
            }

        }
    }
}

void *sllRemoveFirst(SLlist *l) // remove o primeiro elemento da lista
{
    SLnode *temp;
    void *data;
    if(l!=NULL)
    {
        temp=l->first;
        data= temp->data;
        l->first = temp->prox;
        free(temp);
        return data;
    }
    return FALSE;
}

void main(void){





 }
