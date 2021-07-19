#include "listas.h"
#include <stdlib.h>
#include <stdio.h>

void main(void){

    dllist * l;
    char menu;
    int elm;
    int key;
    int stat;
    l = NULL;

    while (menu != '0'){
        if ( l== NULL){
            printf("\n Lista NULL\n\n");
        }


        printf("  1 - Criar Lista\n ");
        printf(" 2 - Inserir elemento no first\n ");
        printf(" 3 - Inserir After Spec\n ");
        printf(" 4 - Inserir Before Spec\n ");
        printf(" 5 - Remover Spec\n ");
        printf(" 6 - Remover First\n ");
        printf(" 7 - Query Spec\n ");
        printf(" 8 - Destruir Lista\n ");
        printf(" 9 - Mostrar Lista\n ");
        printf(" 0 - Sair\n ");
        fflush(stdin);
        scanf("%c",&menu);

        switch(menu){
            case '1':
                if(l ==   NULL){
                    l = dllCreate();
                }else{
                    printf("\n\nJa existe uma Lista,destrua a atual para criar uma nova\n\n");
                }
                break;

            case '2':
                printf("Digite o elemento: ");
                scanf("%d",&elm);
                dllInsertFirst(l,elm);
                break;

            case '3':
                //system("cls");
                printf("Digite o elemento:\n ");
                scanf("%d",&elm);
                printf("Digite a Key:\n ");
                scanf("%d",&key);
                dllInsertAfterSpec(l,elm,cmp,key); //Mostra os elementos
                break;

            case '4':
                printf("Digite o elemento:\n ");
                scanf("%d",&elm);
                printf("Digite a Key:\n ");
                scanf("%d",&key);
                dllInsertBeforeSpec(l,elm,cmp,key);
                break;
            case '5':
                printf("Digite a Key:\n ");
                scanf("%d",&key);
                dllRemoveSpec(l,cmp,key);
                break;

            case '6':
                dllRemoveFirst(l);
                break;
            case '7':
                printf("Digite o elemento:\n ");
                scanf("%d",&elm);
                stat = dllQuery(l,elm);
                if(stat == 1)
                    printf("Encontrado na lista.\n");
                else
                    printf("Não encontrado na lista.\n");
                break;

            case '8':
                stat = dllDestroy(l);
                if (stat == TRUE ){
                    l = NULL;
                    printf("\n\nDestruido com sucesso!\n\n");
                    system("pause");
                }else{
                    printf("\n\nImpossivel destruir!\n\n");

                }
                break;

            case '9':
                    dllShow(l);

            case '0':
                    exit(0);
            default:
                    printf("\nOpcao invalida\n");
                    system("pause");
                    //system("cls");

                break;

        }
    }
}

















