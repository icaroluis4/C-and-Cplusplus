
#include<stdio.h>
#include<stdlib.h>



int *multiplicamatriz(int *v1,int *v2,int n){

    int i,j,k,temp=0,stat;
    int *v3;

    v3=(int*)malloc(n*sizeof(int));
    if(v3!=NULL){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                temp=0;
                for(k=0;k<n;k++){
                    temp =temp + v1[i*n+k]*v2[k*n+j];
                    printf("[%d]X[%d] ",i*n+j,k*n+j);
                }
                v3[i*n+j]=temp;
                stat = i*n+j;
                 printf(" %d ", temp);
            }
        }
        return v3;
    }
    return NULL;
}

int *multiplicaPorTransposta(int *v1, int *v2, int n){


    int i,j,k,temp=0;
    int *v3;

    v3=(int*)malloc(n*sizeof(int));
    if(v3!=NULL){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                temp=0;
                for(k=0;k<n;k++){
                    temp =temp + v1[k*n+i]*v2[j*n+k];
                    printf("[%d]X[%d] ",k*n+i+n,j*n+k);
                }
                v3[i*n+j]=temp;
                 printf(" %d ", temp);
            }
        }
        return v3;
    }
    return NULL;

}
int *multiplicaPorDiagonal(int *v1, int *v2, int n){


    int i,j,k,temp=0;
    int *v3;

    v3=(int*)malloc(n*sizeof(int));
    if(v3!=NULL){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                temp=0;
                for(k=0;k<n;k++){
                    temp =temp + v1[k*n+i]*v2[j*n+k];
                    printf("[%d]X[%d] ",k*n+i+n,j*n+k);
                }
                v3[i*n+j]=temp;
                 printf(" %d ", temp);
            }
        }
        return v3;
    }
    return NULL;

}

int *somMatriz(int *v1,int *v2,int n){
        int *v3,i=0,temp;

        v3 =(int*)malloc(n*sizeof(n));
        if(v3 != NULL){
            for(i=0;i<n;i++){
                temp = v1[i]+v2[i];
                v3[i]=temp;
            }
            return v3;
        }


}

int *diagonalM(int *v,int n,int m){
        int i= 0,*d; int tam = n*m,c=0,l=0;int k=0;
            d=(int*)malloc(m*sizeof(int));
        for(i=0;i<tam;i++){
            if(c == l){
                d[k] = v[i];
                c++; k++;
            }
            if(l == m){
                l =0;
            }
            else
                l++;
        }
        return d;

}

int main(){
    int *v[4]={0,1,2,3,},*v2[4]={9,10,11,12};
    int *v3,*v4,i=0;

  //  v3 = (int*)malloc(9*sizeof(int));

    v3=multiplicaPorTransposta(v,v2,2);

    for(i =0 ; i<4;i++){
            printf("\n");
        printf(" %d ",v3[i]);

    }
    /*v4=multiplicaPorTransposta(v,v2,3);

    for(i =0 ; i<9;i++){
            printf("\n");
        printf(" %d ",v4[i]);

    }*/
   /* printf("DIAGONAL");
    v4=diagonalM(v,3,3);

    for(i =0 ; i<9;i++){
            printf("\n");
        printf(" %d ",v4[i]);
    }
    */
    return 0;

}
