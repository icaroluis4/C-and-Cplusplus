
#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE 1
                        /**FILA**/
typedef struct _queue_{
    int beg;
    int end;
    int numItens;
    int maxItens;
    int *item;
}Queue;

typedef struct _stack_{
        int top;//topo da pilha
        int max;//tamanho max da pilha
        void **elm;//vetor
        }Stack;

Queue *CriarFila(int max);
int DestroiLista(Queue *q);
int Enfila(Queue *q, int data);
int Desenfila(Queue *q);

int RemoveImpares(Queue *q);

void main(void){
    Queue *q;
    q= CriarFila(7);
    Enfila(q,3);
    Enfila(q,4);
    Enfila(q,5);
    Enfila(q,6);
    Enfila(q,7);
    Enfila(q,8);
    Enfila(q,9);
    mostraFila(q);
    //Desenfila(q);
    PuneN(q,4);
    mostraFila(q);
    printf("/n q->end %d,",q->item[q->end]);
    promoveN(q,2);
    printf("/n q->end %d,",q->item[q->end]);
    mostraFila(q);


}

//CRIA FILA
Queue *CriarFila(int max){
    Queue *q;

    if(max>0){
        q=(Queue *)malloc(sizeof(Queue));
        if(q!=NULL){
            q->item = (int *)malloc(sizeof(int)*max);
            if(q->item != NULL){
                q->beg=0;
                q->end=-1;
                q->maxItens=max;
                return q;
            }
        }
    }
    return NULL;
}

void  mostraFila(Queue *q){
        int i=q->beg;

        for(i ; i<=q->end;i++){
            printf("  %d",q->item[i]);
        }
        printf("-");
}
//DESTROI LISTA
int DestroiLista(Queue *q){

    if(q!=NULL){
        if(q->item != NULL){
            free(q->item);
        }
        free(q);
        return TRUE;
    }
    return FALSE;
}

//ADICIONA ITEM NA LISTA
int Enfila(Queue *q, int data){

    if(q!=NULL){
        if(q->end < (q->maxItens - 1)){
            q->end++;
            q->item[q->end] = data;
            return TRUE;
        }
    }
    return FALSE;
}

//RETIRA ITEM DA FILA
int Desenfila(Queue *q){
    int aux,i;

    if(q->beg <= q->end){
        aux = q->item[q->beg];
        for(i = q->beg;i < q->end;i++){
            q->item[i] = q->item[i+1];
        }
        q->end--;
        return aux;
    }
    return FALSE;
}

int PuneN(Queue *q,int n){
    int aux,i;

    if(q!=NULL){
        if(n < q->numItens){
            aux = q->item[q->beg];
            for(i = q->beg;i<=n;i++){
                q->item[i] = q->item[i+1];
                if(i== n){
                    q->item[i] = aux;
                }
            }
            return TRUE;

        }
    }
    return FALSE;
}

int promoveN(Queue *q,int n){

    int aux,i;

    if(q!=NULL){
        if(n < q->numItens){
            aux = q->item[q->end];
            for(i = q->end;i>=(q->end - n);i--){
                q->item[i] = q->item[i-1];
                if(i== (q->end -n)){
                    q->item[i] = aux;
                }
            }
            return TRUE;

        }
    }
    return FALSE;

}

int PuneNFila(Queue *q,int n){
    int aux,i;
    stack *p;
    p = stkCreate()

    if(q!=NULL){
        if(n < q->numItens){
            aux = q->item[q->beg];
            for(i = q->beg;i<=n;i++){
                q->item[i] = q->item[i+1];
                if(i== n){
                    q->item[i] = aux;
                }
            }
            return TRUE;

        }
    }
    return FALSE;
}

//REMOVE IMPARES
int RemoveImpares(Queue *q){
    int i,j;

    if(q!=NULL){
        for(i=0;i < q->end;i+=2){
            if(i <= q->end){
                for(j=i;j < q->end;j++){
                    q->item[j] = q->item[j+1];
                }
            }
            q->end--;
        }
        return TRUE;
    }
    return FALSE;
}

Stack *stkCreate(int size)
{
    if(size > 0){
        Stack *tmp;
        tmp = (Stack*)malloc(sizeof(Stack));

        if (tmp != NULL){
            tmp->elms = (void**)malloc(sizeof(void*));
            if(tmp->elms != NULL){
                tmp->maxElms = size;
                tmp->top = -1;
                return tmp;
            }
        }
    }
    return NULL;
}

int stkDestroy(Stack *tmp)
{
    if (tmp != NULL){
        free(tmp->elms);
        free(tmp);
        tmp = NULL;
        return TRUE;
    }
    return FALSE;
}

int stkPush(Stack *tmp,void* elm)
{
    if (tmp != NULL){
        if (tmp->top < tmp->maxElms - 1){
            tmp->top++;
            tmp->elms[tmp->top] = elm;
            return TRUE;
        }
    }
    return FALSE;
}

void* stkPop(Stack *tmp)
{
    void *aux;
    if(tmp != NULL){
        if(tmp->top >=0){
            aux = tmp->elms[tmp->top];
            tmp->top--;
            return aux;
        }

    }
    return NULL;
}






