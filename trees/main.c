#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
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

tree * abpCreate ();
void * abpQueryNode (tnode *t, int (*cmp)(void*, void*), void *key);
tnode * abpInsert (tnode *t, void *data, int (*cmp)(void *, void*));
void * abpRemove (tnode *t, void *key, int (*cmp)(void *, void *));
void * removeKey(tnode *t,void *key);
void * abpGetMenorData (tnode *t);
void abppreOrdem (tnode *t, void (*visit)(void*));
void abpposOrdem (tnode *t, void (*visit)(void*));
void abpSimetrico (tnode *t, void (*visit)(void*));
void abpnFolhaSimetrico (tnode *t, void (*visit)(void*));
void dadosArvore (tnode *t, int *vet);
int abpTeste (tnode *t, int (*cmp)(void*, void*));
int abpAlturaNo (tnode *t, void *key, int (*cmp)(void*, void*));
void * abpRemoveMaiorData (tnode *t);
tnode * abpFusao (tnode *t3, tnode *t1, tnode*t2, int (*cmp)(void *, void*));
tnode * abpCopy (tnode *t3, tnode *t,int (*cmp)(void *, void*), void *first);
int maior(int a, int b);
int altura(tnode *root);
int alturaT(tnode *t);
int contarNos(tnode *root);
int contarFolhas(tnode *root);
int isABP(tnode *t);
int getMenor(tnode *t);
int getMaior(tnode *t);
int testaABB(tnode *t,int (*cmp)(void *, void *));
int nNosAlth(tnode *t, int h, int hno);
int grau1(tnode *t);
int nosMaiorKey(tnode *t, int key);
int isHeap(tnode* t);
int numNos(tnode *root);

int cmp(void* elm, void * teste){
    int *a, *b;
    a=(int *)elm;
    b=(int *)teste;
    if(*a<*b)
        return -1;
    else{
        if (*a==*b) return 0;
        else        return 1;
    }
}

void visit (void *elm){
    int *a;
    a=(int *)elm;
    printf ("%d ",*a);
}

tree * abpCreate (){
    tree *t;
    t = (tree *)malloc(sizeof(tree));
    if (t!=NULL){
        t->root=NULL;
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

/*tnode * abpRemove (tnode *t, void *key, int (*cmp)(void *, void *),void**dado){
    tnode *filho;
    if (t!=NULL){
        if (cmp(t->data, key)==0){
            if ((t->left==NULL)&&(t->right==NULL)){
                free (t->data);
                free (t);
                return NULL;
            }
            else{
                if ((t->left==NULL)&&(t->right!=NULL)){
                    filho=t->right;
                    dado = t->data;
                    free (t->data);
                    free (t);
                    return filho;
                }
                else{
                    if ((t->left!=NULL)&&(t->right==NULL)){
                        filho=t->left;
                        dado = t->data;
                        free (t->data);
                        free (t);
                        return filho;
                    }
                    else{
                        t->data=abpGetMenorData(t->right);
                        t->right=abpRemove(t->right,t->data,cmp);
                        return t;
                    }
                }
            }
        }
        else{
            if (cmp(key, t->data)<0){
                t->left=abpRemove(t->left, key, cmp);
            }
            else{
                t->right=abpRemove(t->right, key, cmp);
            }
        }
    }
    return NULL;
}
*/
void *  abpGetMenorData (tnode *t){
    if (t!=NULL){
        if (t->left!=NULL){
            return abpGetMenorData(t->left);
        }
        else{
            return t->data;
        }
    }
    return NULL;
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

void abpnFolhaSimetrico (tnode *t, void (*visit)(void*)){
    if (t!=NULL){
        abpnFolhaSimetrico(t->left, visit);
        if ((t->left!=NULL)||(t->right!=NULL)) visit (t->data);
        abpnFolhaSimetrico(t->right, visit);
    }
}

void dadosArvore(tnode *t, int *vet){
    //Em cada posição do vetor, serão guardados os seguintes valores:
    //0 - Numero de Nós, 1 - Numero de Folhas, 2 - Nós não Folhas
    //3 - Nós com 2 fil, 4 - Nós com 1 filho,  5 - Nós com filho esquerdo
    //6 - Nós com filho direito
    if (t!=NULL){
        dadosArvore(t->left, vet);
        //Incrementa numero de nós
        vet[0]++;
        //Se for folha, increments
        if ((t->left==NULL)&&(t->right==NULL)) {
            vet[1]++;
        }
        else{
            //Já não é folha, então...
            vet[2]++;
            //Vamos ver se tem 2 filhos...
            if ((t->left!=NULL)&&(t->right!=NULL)){
                vet[3]++;
            }
            else{
                //Se chegou aqui, é óbvio que tem um, então...
                vet[4]++;
            }
            if (t->left!=NULL)  vet[5]++;
            if (t->right!=NULL) vet[6]++;
        }
        dadosArvore(t->right, vet);
    }
}

int abpTeste (tnode *t, int (*cmp)(void*, void*)){
    if (t!=NULL){
        if (abpTeste(t->left,cmp) && abpTeste(t->right,cmp)){
            if ((t->left==NULL)&&(t->right==NULL)){
                return 1;
            }
            else{
                if ((t->left==NULL)&&(t->right!=NULL)){
                    if (cmp(t->right->data, t->data)>=0) {
                     return 1;
                    }else{
                        return 0;
                    }
                }
                else if ((t->left!=NULL)&&(t->right==NULL)){
                        if (cmp(t->left->data, t->data)==-1){
                                return 1;
                        }else{
                            return 0;
                        }
                }else if ((cmp(t->left->data, t->data)==-1)&&(cmp(t->right->data, t->data)>=0)){
                            return 1;

                        }else{
                            return 0;
                        }

            }
        }
        return 0;
    }
    return 1;
}


int abpAlturaNo (tnode *t, void *key, int (*cmp)(void*, void*)){
    int i = 0;
    if (t!=NULL){
        i+=abpAlturaNo(t->left, key, cmp);
        i+=abpAlturaNo(t->right, key, cmp);
        if (i>0)                    return i+1;
        if (cmp(t->data,key)==0)    return 1;
    }
    return 0;
}

void * abpRemoveMaiorData (tnode *t){
    if (t->right!=NULL)
        t->right=abpRemoveMaiorData(t->right);
    else{
        free (t->data);
        free (t);
        return NULL;
    }
}

tnode * abpCopy (tnode *t3, tnode *t,int (*cmp)(void *, void*), void* first ){
    tnode *firstcopied;
    if (t!=NULL){
        t3=abpInsert(t3, t->data, cmp);
        abpCopy(t3, t->left, cmp, first);
        abpCopy(t3, t->right, cmp, first);
        if (cmp(first,t->data)==0)   return t3;
    }
}

tnode * abpFusao (tnode *t3, tnode *t1, tnode *t2, int (*cmp)(void *, void*)){
        if (t1!=NULL){
            t3=abpCopy(t3, t1, cmp, t1->data);
        }
        if (t2!=NULL){
            t3=abpCopy(t3, t2, cmp, t2->data);
        }
        return t3;
}

int maior(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

int altura(tnode *root){
   if((root == NULL) || (root->left == NULL && root->right == NULL))
       return 0;
   else
       return 1 + maior(altura(root->left), altura(root->right));
}

int alturaT(tnode *t){
    int altD=0, altE=0;

    if(t==NULL) return -1;
    else
        altE=alturaT(t->left);
        altD=alturaT(t->right);

        if(altE<altD) return altD+1;
        else return altE+1;
    }



int contarNos(tnode *root){
   if(root == NULL)
        return 0;
   else
        return 1 + contarNos(root->left) + contarNos(root->right);
}

int contarFolhas(tnode *root){
   if(root == NULL)
        return 0;
   else
        if(root->left==NULL && root->right==NULL)
                            return 1;
        else
                return 0 + contarFolhas(root->left) + contarFolhas(root->right);
}

int isABP(tnode *t){
    int a,b;
    int menor,maior;

    if(t!=NULL){
         a=isABP(t->left);
         b=isABP(t->right);
         menor=getMenor(t->right);
         maior=getMaior(t->left);
         if((menor>(int)(t->data)) && (maior <=(int)(t->data)) && (a==1) && (b==1)){    // problema na comparação entre menor e t->data / maior e t->data
                          return 1;
                          }else{
                                return 0;
                                }
                                } return 1; }

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
                return 0;
                }

void *removeKey(tnode *t,void *key){
     tnode *aux;
     static int data;
     int localdata;

     if(t!=NULL){
          if(key!=t->data){
               if(key<t->data){
                       t->left=(void*)removeKey(t->left,key);
                       return t;
               }else{
                    t->right=(void*)removeKey(t->right,key);
                    return t;
                    }
         }else{
           data=(int)t->data;
           if(t->left==NULL){
                 if(t->right!=NULL){
                          aux=t->right;
                          free(t);
                          return aux;
                 }else{
                       free(t);
                       return NULL;
                       }
           }else{
                 if(t->right!=NULL){
                       localdata=(int)t->data;
                       t->data=(void*)getMenor(t->right);
                       t->right=(void*)removeKey(t->right,t->data);
                       data=localdata;
                       return t;
                 }else{
                       aux=t->left;
                       free(t);
                       return aux;
                       }
                 }
           }
     }
      return NULL;
}

int testaABB(tnode *t, int (*cmp)(void *, void *)){
    int arvE=1, arvD=1;
    int flag;
    flag=cmp(t->data,t->left->data);
    if(t==NULL){
                return 1;
                }
    if((t->left==NULL) && (t->right==NULL)){
                    return 1;
                    }
    if(t->left!=NULL){
             if(flag==-1){
                        return 0;
                        }else{
                              arvE=testaABB(t->left,cmp);
                              }
             }
    flag=cmp(t->data,t->right->data);
    if(t->right!=NULL){
             if(flag==1){
                       return 0;
                       }else{
                             arvD=testaABB(t->right,cmp);
                             }
                       }
    if((arvE==0) || (arvD==0))
                 return 0;
    else
        return 1;
}

int nNosAlth(tnode *t, int h, int hno)
{
    int nnos=0;

    if(t==NULL){
        nnos=0;
    }else{
        hno=hno+1;
        if(hno==h){
            nnos=1;
        }
        nnos+=nNosAlth(t->left,h,hno);
        nnos+=nNosAlth(t->right,h,hno);
    }
    return nnos;
}

int grau1(tnode *t){
    int nnos=0;

    if(t!=NULL){
        if(t->left!=NULL && t->right==NULL || t->left==NULL && t->right!=NULL){
            nnos=1;
        }
        nnos= nnos+grau1(t->left);
        nnos= nnos+grau1(t->right);
        return nnos;
    }else{
          return 0;
    }

 }

int nosMaiorKey(tnode *t, int key){

    int nnos=0;

     if(t!=NULL){
               if((int)(t->data)>= key) nnos=1;

               nnos = nnos+nosMaiorKey(t->left,key);
               nnos = nnos+nosMaiorKey(t->right,key);
               return nnos;
               }
               return 0;
}


/*
int isHeap(tnode* t){

    if(t!=NULL){
         if(isHeap(t->left) && isHeap(t->right)){
                            if(t->left!=NULL && t->right!=NULL){
                                             if((t->left->data < t->data) && (t->left->data < t->data)){
                                                          return 1;
                                             }else{
                                                   return 0;
                                    }               }
                            if ((t->left==NULL && t->right!=NULL) || (t->left!=NULL && t->right==NULL)){
                                         if((t->left->data < t->data) || (t->left->data < t->data)) {
                                                       return 1;
                                         }else{
                                               return 0;
                                     }         }
                            else return 1;
         }else{
               return 0;
               }
    }
}      */

int isHeap(tnode* t){

    if(t!=NULL){
         if(isHeap(t->left)){
              if(isHeap(t->right)){
                            if(t->left!=NULL && t->right==NULL){
                                          if(cmp(t->left->data,t->data)<0){
                                                          return 1;       }
                                                               }

                            if(t->left==NULL && t->right!=NULL){
                                         if(cmp(t->right->data,t->data)<0){
                                                       return 1;          }
                                                               }
                            if(t->left!=NULL && t->right!=NULL){
                                             if(cmp(t->left->data,t->data)<0){
                                                   if(cmp(t->right->data,t->data)<0){
                                                           return 1;
                                                                                    }
                                                                             }
                                                               }
                            if(t->left==NULL && t->right==NULL) {
                                                 return 1;
                                                                }
                                  }
                             }
                    return 0;
              }
         return 1;
    }
/*
int IsMaxHeap(Tnode *root){

    int maiorL;
    int maiorR;
    int *data;
    int d;
    if(root != NULL){
            data = (int *)root->data;
            d = *data;
            maiorL = PegaMaiordeArvBin(root->l);
            maiorR = PegaMaiordeArvBin(root->r);
            if(d > maiorL && d > maiorR){
                    return (IsMaxHeap(root->l)&& IsMaxHeap(root->r));
            }
            else{
                    return FALSE;
                 }
         }
     return TRUE;
}

int IsMaxHeap(Tnode *root){

    int maiorL;
    int maiorR;
    int *data;
    int d;
    if(root != NULL){
            data = (int *)root->data;
            d = *data;
            maiorL = PegaMaiordeArvBin(root->l);
            maiorR = PegaMaiordeArvBin(root->r);
            if(d > maiorL && d > maiorR){
                    return (IsMaxHeap(root->l)&& IsMaxHeap(root->r));
            }
            else{
                    return FALSE;
                 }
         }
     return TRUE;
}

int PegaMenordeArvBin(Tnode *t)
{
    int min;
    int minL;
    int minR;
    int *data;

    if(t != NULL)
    {
         data=(int *)t->data;
         min = *data;
         minL = PegaMenordeArvBin(t->l);
         minR = PegaMenordeArvBin(t->r);
         if(minL < min)
         {
                 min = minL;
         }
         if(minR < min)
         {
             min = minR;
         }
         return min;
    }
    return 65535;
}

int PegaMaiordeArvBin(Tnode *t)
{
    int max,maxR,maxL;
    int *data;

    if(t != NULL)
    {
         data=(int *)t->data;
         max = *data;
         maxL = PegaMaiordeArvBin(t->l);
         maxR = PegaMaiordeArvBin(t->r);
         if(maxL > max)
         {
                 max = maxL;
         }
         if(maxR > max)
         {
                 max = maxR;
         }
         return max;
     }
    return 0;
}
    */


int numNos(tnode *root){
    static int no=0;

    if(root!=NULL){
        no++;
        numNos(root->left);
        numNos(root->right);

    }
    return no;
}

/*int CompMaior(tnode *t1, tnode *t2){
    int l,r;
    if(t1!=NULL && t2!=NULL){
        if((int)t1->data > (int)t2->data){
            l = CompMaior(t1->left,t2->left);
            r =  CompMaior(t1->right,t2->right);
            return l && r;
        }else{
            return FALSE
        }
    }else if(t1==NULL && t2==NULL){
         return TRUE;
    }else{
         return FALSE;
    }
}
*/

int main(){
    int i=1, key1=0, key, folhas=0;
    int alt=0, nos=0, h, nNos=0,hno,g1=0;
    int *point, *vet;
    tree *t, *t2, *t3;
    char op;
    vet=NULL;
    t=abpCreate();
    (t!=NULL)? printf ("Deu certo Arvore 1!\n"):printf ("Ferrou Arvore 1\n");
    t2=abpCreate();
    (t2!=NULL)? printf ("Deu certo Arvore 2!\n"):printf ("Ferrou Arvore 2\n");
    while (op!='0'){
        printf("\nMENU\n");
        printf("a) Inserir na Arvore\n");
        printf("b) Remover da Arvore\n");
        printf("c) Consultar Arvore\n");
        printf("d) Visitar Arvore\n");
        printf("e) Visitar Nao-Folhas Simetricamente\n");
        printf("f) Dados da Arvore\n");
        printf("g) Testar se e' Arvore de pesquisa\n");
        printf("h) Altura do No\n");
        printf("i) Remove Maiores Dados\n");
        printf("j) Fundir Arvores 1 e 2\n");
        printf("l) Altura da Arvore\n");
        printf("m) Numeros de nos\n");
        printf("n) Numeros de nos de Altura h\n");
        printf("o) Numeros de nos de Grau 1\n");
        printf("p) Numeros de nos > que a Key\n");
        printf("q) isHeap ?\n");
        printf("r) Numeros de folhas\n");
        printf("0) Sair\n\n");
        printf ("Opcao: ");
        op=getche();
        i=1;
        printf ("\n");

        switch (op){
            case 'a':
                while (i){
                    printf ("Digite o numero que deseja inserir na arvore. Digite 0 para sair da funcao. ");
                    scanf ("%d", &i);
                    if (i==0)   break;
                    point = (int *)malloc(sizeof(int));
                    *point = i;
                    printf ("Inserir em qual arvore? 1 ou 2?\ndetalhe: se voce digitar 5, vai adicionar na 2 xD\n");
                    if (getche()=='1')
                        t->root=abpInsert(t->root, (void*)point, cmp);
                   else
                        t2->root=abpInsert(t2->root, (void*)point, cmp);
                    printf("\n");
                }
                break;
            case 'b':
                while (i){
                    printf ("Digite o numero que deseja remover da arvore. Digite 0 para sair da funcao. ");
                    scanf ("%d", &i);
                    if (i==0)   break;
                    point = (int *)malloc(sizeof(int));
                    *point = i;
                    void* dado =abpRemove(t->root, (void*)point, cmp);
                    //t->root=removeKey(t->root,(void*)point);
                }
                break;
            case 'c':
                while (i){
                    printf ("Digite o numero que deseja consultar da arvore. Digite 0 para sair da funcao. ");
                    scanf ("%d", &i);
                    if (i==0)   break;
                    point = (int *)malloc(sizeof(int));
                    *point = i;
                    if (abpQueryNode(t->root,cmp, (void*)point)!=NULL)
                        printf ("Encontrado %d!!\n", *point);
                }
                break;
            case 'd':
                while (i){
                    printf ("Escolha o modo de visita: \n")/
                    printf ("(1) preOrdem, (2) posOrdem, (3) Simetrica, (0) Sair\n");
                    scanf ("%d", &i);
                    if (i==1){
                        abppreOrdem(t->root, visit);
                        printf("\n");
                    }
                    else{
                        if (i==2){
                            abpposOrdem(t->root, visit);
                            printf("\n");
                        }
                        if (i==3){
                            abpSimetrico(t->root, visit);
                            printf("\n");
                        }
                    }
                }
                break;
            case 'e':
                abpnFolhaSimetrico(t->root, visit);
                break;
            case 'f':
                vet=(int *)malloc(sizeof(int)*7);
                for (i=0; i<7; i++) vet[i]=0;

                dadosArvore(t->root, vet);
                printf("\n\nDados da Arvore\n");
                printf("Numero de Nos: %d\n", vet[0]);
                printf("Numero de Folhas: %d\n", vet[1]);
                printf("Numero de Nao Folhas: %d\n", vet[2]);
                printf("Numero de Nos com 2 filhos: %d\n", vet[3]);
                printf("Numero de Nos com 1 filho: %d\n", vet[4]);
                printf("Numero de Nos com filho esq: %d\n", vet[5]);
                printf("Numero de Nos com filho dir: %d\n\n", vet[6]);
                i=1;
                break;
            case 'g':
               if (abpTeste(t->root,cmp)==1)
                //if (testaABB(t->root,cmp)==1)
                //if(isABP(t->root)==1)
                    printf("E' arvore de pesquisa!\n");
                else
                    printf("Nao e' arvore de pesquisa\n");
                break;
            case 'h':
                    printf ("Digite o numero que deseja procurar na arvore. Digite 0 para sair da funcao. ");
                    scanf ("%d", &i);
                    if (i==0)   break;
                    point = (int *)malloc(sizeof(int));
                    *point = i;
                    printf ("A altura do no e' %d\n", abpAlturaNo(t->root,(void*) point, cmp)-1);
                    break;
            case 'i':
                    abpRemoveMaiorData(t->root);
                    break;
            case 'j':

                    break;
            case'l':
                    printf("Imprimindo altura da arvore!\n");
                    alt = altura(t->root);
                    printf("%d", alt);
                    break;
            case'm':
                    printf("Imprimindo quantidade de nos presente na Arvore!\n");
                    nos=numNos(t->root);
                    printf("%d", nos);
                    break;
            case'n':
                    printf("Entre com a altura: ");
                    scanf("%d", &h);
                    nNos=nNosAlth(t->root,h,-1);
                    printf("%d", nNos);
                    break;
            case'o':
                    printf("Numero de nos de grau 1:\n");
                    g1= grau1(t->root);
                    printf("%d", g1);
                    break;
            case'p':
                    printf("Entre com a key:\n");
                    scanf("%d", &key);
                    key1=nosMaiorKey(t->root,key);
                    printf("Numero de nos maior que a key: %d", key1);
                    break;
            case'q':
                     (isHeap(t->root)) ? printf("E uma Heap"): printf("Nao e uma Heap");
                     break;
            case'r':
                    printf("Numero de Folhas:\n");
                    folhas= contarFolhas(t->root);
                    printf("%d", folhas);
                    break;

        }

    }
}
