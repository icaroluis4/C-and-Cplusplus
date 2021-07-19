
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pune.h"
#define TRUE 1
#define FALSE 0

int q2(Stack *q,char *s1,char *s2,int tam);

int main()
{
    void *tmp;

    Stack *p = stkCreate(7);
    stkPush(p,5);
    stkPush(p,2);
    stkPush(p,3);
    stkPush(p,1);
    //stkPush(p,5);
    //stkPush(p,6);
    //stkPush(p,7);
    tmp = p->elms[p->top];
    printf("\n topo:  %d ", tmp);

    showStk(p);
    stkPune(p,2);
    printf(" \n stkPune: \n");
    showStk(p);
    stkPromove(p,3);
    printf(" \n stkPromove: \n");
    showStk(p);

    return 1;


}

int palindromo(Stack *q, char *str){
    char c;
    int i = 0;

    if(q->maxElms < strlen(str)){
        return FALSE;
    }

    while(str[i] != '\0' && str[i] != '0'){
        stkPush(q,(int)str[i]);
        i++;
    }
    i++;
    c = (int)stkPop(q);
    while(c != NULL && str[i] != '\0')
    {
        if (c != str[i])
        {
            return FALSE;
            printf("segundo while");
        }
        i++;
        c = (int)stkPop(q);
    }

    if(c == NULL && str[i] == 0)
    {
        return TRUE;
    }
    return FALSE;
}



void imprime(Stack* tmp){
    int aux,i;
    printf("\n\n");

    if(tmp != NULL){
        //if (tmp->top > 0){
            for (i=tmp->top;i>=0;i--){
                aux = (int)tmp->elms[i];
                printf("%d\n",aux);
            }

        //}

    }
    printf("\n\n");

}

int stkQ3(Stack *q,void* key){

    int i;
    int top = q->top;
    if(q != NULL){
        for ( i = top; i >=0 ;i--){
            if (q->elms[i] < key){
                return TRUE;
            }else{
                q->top--;
            }

        }
    }
    return FALSE;
}

int q2(Stack *q,char *s1,char *s2,int tam){
    int i=0,k=0;
    int c;
    while(k<tam){
        if(s1[k] == '\0' || s1[k] == ' ' ){
            c = (char)stkPop(q);
            while (c!=NULL){
                if(c!=s2[i]){
                    return FALSE;
                }
                i++;
                c = (char)stkPop(q);
            }
            i++;
            k++;
        }
    stkPush(q,(void*)s1[k]);
    k++;
    }
    return TRUE;
}

int stkPenalizar(Stack *tmp,int N){
    int i;
    void *aux1;
    if(tmp != NULL){
        printf("\nQual a pena?\n");
        scanf("%d",&N);
        if(N <= tmp->top && N > 0){
            for (i=0; i<N; i++){
                aux1 = tmp->elms[tmp->top - i];
                tmp->elms[tmp->top - i] = tmp->elms[tmp->top - i - 1];
                tmp->elms[tmp->top - i - 1] =  aux1;
            }
            return TRUE;
        }
    }
    return FALSE;
}

void showStk(Stack *n){
    int i;

    for(i=0 ; i< n->top+1;i++){
        printf("\n %d", n->elms[i]);

    }
}

int stkPune( Stack * n , int key){
        int i;
        void* aux;
        void* tmp = n->top;
    if(n!=NULL && key <= n->top){
        for(i=0 ; i< key ; i++){
            aux = stkPop(n);
            n->elms[n->top+1]=n->elms[n->top];
            n->elms[n->top] = aux;

        }
        n->top = tmp ;
        return 1;
    }

        return 0;
}


int stkPromove( Stack * n , int key){
        int i;
        void* aux;
        int tmp = key;
    if(n!=NULL && key <= n->top){
        for(i=0 ; i< key ; i++){
            aux = n->elms[n->top - tmp];
            n->elms[n->top - tmp]=n->elms[n->top - tmp+1];
            n->elms[n->top - tmp+1] = aux;
            tmp -- ;

        }
        return 1;
    }

        return 0;
}

/*
if(n != NULL && n -> top >1){
        aux = n->elms[n->top];
        n ->elms[n->top+1] = n->elms[key];
        n ->elms[n->top - key] = aux;
        return 1;

        */
