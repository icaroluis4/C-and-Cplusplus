
#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct _tnode_{
    void *data;
    struct _tnode_ *left;
    struct _tnode_ *right;
} tnode;

typedef struct _tree_{
    tnode *root;
} tree;

int cmp(void* elm, void* teste){
    //int a, b;
    //a=(int *)elm;
    //b=(int *)teste;
    if(elm<teste)
        return -1;
    else{
        if (elm==teste)
            return 0;
        else
            return 1;
    }
}

tree * abpCreate (){
    tree *t;
    t = (tree *)malloc(sizeof(tree));
    if (t!=NULL){
        t->root=NULL;
        //printf("FOII");
        return (t);
    }
    return NULL;
}

tnode * abpInsert (tnode *t, void *data, int (*cmp)(void *, void*)){
    tnode *novo;
    int stat;
    if (t!=NULL){
                stat=cmp(data, t->data);
                if (stat<0){
                    t->left=abpInsert(t->left, data, cmp);
                }
                else{
                    t->right=abpInsert(t->right, data, cmp);
                }
                return t;
        }
    else{
        novo = (tnode *)malloc(sizeof (tnode));
        if (novo!=NULL){
            novo->left=NULL;
            novo->right=NULL;
            novo->data=data;
        }
        return novo;
    }
}

void * abpQueryNode (tnode *t, int (*cmp)(void*, void*), void *key){
    int stat;
    if (t!=NULL){
        stat=cmp(key, t->data);
        if (stat==0){
            return t->data;
        }
        else{
            if (stat==-1){
                return (abpQueryNode(t->left, cmp, key));
            }
            else{
                return (abpQueryNode(t->right,cmp, key));
            }
        }
    }
    return NULL;
}

int getMenor(tnode *t){
    int min;
    int minL, minR;

    if(t!=NULL){
                min=(int)t->data;
                minL=getMenor(t->left);
                minR=getMenor(t->right);
                if(minL<min){
                             min=minL;
                             }
                if(minR<min){
                             min=minR;
                             }
                return min;
                }
                return 32.922;
}


int getMaior(tnode *t){
    int max;
    int maxL, maxR;

    if(t!=NULL){
        max=(int)t->data;
        maxL=getMaior(t->left);
        maxR=getMaior(t->right);
                if(maxL>max){
                             max=maxL;
                }
                if(maxR>max){
                             max=maxR;
                }
                return max;
    }
    return NULL;
}
tnode* abpRemoveD(tnode * t, void *key,  int(*cmp)(void*,void*),void **data){
            int stat; tnode * aux; void *data2;
            if(t!=NULL){
                stat = cmp(key,t->data);
                if(stat == -1){
                    t->left = abpRemoveD(t->left,key,cmp,&data2);
                    return t;

                }else if(stat==1){
                    t->right = abpRemoveD(t->right,key,cmp,&data2);
                    return t;
                }else{
                    *data = t->data;
                    if(t->left == NULL && t->right ==NULL){
                        free(t);
                        return NULL;
                    }
                    else if(t->left !=NULL && t->right ==NULL){
                        aux = t->left;
                        free(t);
                        return aux;
                    }
                    else{
                        t->data = getMaior(t->left);
                        abpRemoveD(t->left,t->data,cmp,&data2);
                        return t;
                    }
                }
            }
            return NULL;
}

void visit (void *elm){
   // int *a;
    //a=(int *)elm;
    printf ("- %d - ",elm);
}

void abppreOrdem (tnode *t, void (*visit)(void*)){
    if (t!=NULL){
        visit (t->data);
        abppreOrdem(t->left, visit);
        abppreOrdem(t->right, visit);
    }
}

void abpposOrdem (tnode *t, void (*visit)(void*)){
    if (t!=NULL){
        abpposOrdem(t->left, visit);
        abpposOrdem(t->right, visit);
        visit (t->data);
    }
}

void abpSimetrico (tnode *t, void (*visit)(void*)){
    if (t!=NULL){
        abpSimetrico(t->left, visit);
        visit (t->data);
        abpSimetrico(t->right, visit);
    }
}

void main(void){
        tree *t;
        void* dado;
        t=abpCreate();
        t->root=abpInsert(t->root,100,cmp); //Inserção
        t->root=abpInsert(t->root,55,cmp);
        t->root=abpInsert(t->root,28,cmp);
        t->root=abpInsert(t->root,44,cmp);
        t->root=abpInsert(t->root,200,cmp);
        t->root=abpInsert(t->root,150,cmp);
        abppreOrdem(t->root,visit); //Visitas
        printf("\n");
        abpposOrdem(t->root,visit);
        printf("\n");
        abpSimetrico(t->root,visit);
        printf("\n");
        if(abpQueryNode(t->root,cmp,28)!=NULL) //Pesquisa
            printf("ACHADO \n");
        else
            printf("Não achado \n");
        dado = abpRemoveD(t->root,44,cmp,dado); //Remover
        abpSimetrico(t->root,visit);




}
