
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct _node_{
    void *data;
    struct _node_ *prox;
} SLnode;

typedef struct _Prim_{
    SLnode *first;
    SLnode *cur;
} SLlist;

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
int sllInsertFirst(SLlist *l,void *elm){  //insere no começo da lista
    SLnode *novo;
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
                novo->prox=l->first;
                l->first=novo;
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
    if(l!=NULL){
        if(l->first!=NULL){

            temp=l->first;
            data= temp->data;
            l->first = temp->prox;
            free(temp);
            return data;
        }
        else
            printf(" \n Lista vazia ");
    }
    return 0;
}

void imprime(SLlist* l){
        SLnode *temp;
        void* data;

        if(l!=NULL){
            temp=l->first;

            while(temp !=NULL){
                data=temp->data;
                printf("- %d -",data);
                temp=temp->prox;
            }
            printf("\n");
        }

}

int imprimeQtd(SLlist* l){
        SLnode *temp;
        void* data;
        int cont=0;
        if(l!=NULL){
            temp=l->first;

            while(temp !=NULL){
                temp=temp->prox;
                cont=cont+1;
            }
        }
        return cont;
}


int main(){
    SLlist *l;
    int opc=0;
    int num;
    l=sllCreate();

    printf("1-Inserir numero no comeco da lista: \n");
    printf("2-Excluir numero da lista do comeco da lista: \n");
    printf("3-Imprimir lista: \n");
    printf("4-Quantidade de elementos da lista: \n");
    printf("5-Sair do programa: \n");

    while(1){
        scanf("%d",&opc);

        if(opc==1){
            printf("Digite o numero: \n");
            scanf("%d",&num);
            sllInsertFirst(l,num);
        }
        if(opc==2)
            sllRemoveFirst(l);

        if(opc==3)
            imprime(l);
        if(opc==4){
            num=imprimeQtd(l);
            printf("A quantidade de elementos e: %d \n",num);
        }
        if(opc==5)
            break;

        opc=0;
        num=0;

    }

    return 1;

}
