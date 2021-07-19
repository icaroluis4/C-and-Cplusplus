#include<stdlib.h>
#include<stdio.h>



void main(void){
    int *mat,*mat2,*mat3;
    int i,j,k,n;
    int aux=0;

    scanf(" %d", &n);
    mat = (int*)malloc(sizeof(int)*(n));
    mat2 = (int*)malloc(sizeof(int)*(n));

    for(i=0 ; i<(n);i++){
        mat[i] = i;
    }

    for(i=0 ; i<(n);i++){
        mat2[i] = i*i+i;
    }

    printf("MAT1; \n");
    for(i=0 ; i<(n);i++){
        if(aux == n-1){
            printf(" %d \n ", mat[i]);
            aux = 0;
        }
        else{
            printf(" %d", mat[i]);
            aux ++;
        }
    }
    printf("MAT2: \n");
    for(i=0 ; i<n;i++){
        if(aux == n-1){
            printf(" %d \n ", mat2[i]);
            aux = 0;
        }
        else{
            printf(" %d", mat2[i]);
            aux ++;
        }
    }

    for(i=0 ; i<n;i++){
        for(j =0;j<n;j++){
            for(k =0;k<n;k++){

            }
        }

    }

    mat3 = multiplicamatriz(mat,mat2,n);

     printf("MAT3: \n");
    for(i=0 ; i<(n);i++){
        if(aux == n-1){
            printf(" %d \n ", mat3[i]);
            aux = 0;
        }
        else{
            printf(" %d", mat3[i]);
            aux ++;
        }
    }

    free(mat);
    free(mat2);
    free(mat3);
}

int multiplicamatriz(int *v1,int *v2,int n){

    int i,j,k,temp;
    int *v3;

	v3=(int*)malloc(n*sizeof(int));
	if(v3!=NULL){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				temp=0;
				for(k=0;k<n;k++){
					temp=temp+v1[i*n+k]*v2[k*n+j];
				}
				v3[i*n+j]=temp;
			}
		}
		return v3;
	}
return NULL;
}
