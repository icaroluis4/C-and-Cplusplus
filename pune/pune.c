

# include <stdio.h>
# include <stdlib.h>
#include "pune.h"
#define TRUE 1
#define FALSE 0



Stack *stkCreate(int size){
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


// _PUNE_C_


