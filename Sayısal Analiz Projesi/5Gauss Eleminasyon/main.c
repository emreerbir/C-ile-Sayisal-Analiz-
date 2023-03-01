#include <stdio.h>
#include <stdlib.h>
#define N 25

void matris_yazdir(float A[N][N], int boyut);
void cozum(float A[N][N], int boyut);

int main() {
	float A[N][N];
    int boyut=0, i=0, j=0;
    
    do{
    	printf("\nA Matrisinin boyutunu giriniz : ");
        scanf("%d", &boyut);
	}while(boyut<1);
	
	for(i = 0; i < boyut; i++){
		printf("\n %d. Denklem\n\n", i+1);
		for(j = 0; j < boyut; j++){
			printf("x%d'nin katsayisi: ", j+1);
			scanf("%f", &A[i][j]);
		}
		printf("Denklemin Sonucu: ");
		scanf("%f", &A[i][boyut]);
	}
    
    matris_yazdir(A, boyut);
    cozum(A, boyut);
    
	return 0;
}

void matris_yazdir(float A[N][N], int boyut){
    int i, j;
    printf("\n[A:B] matrisi\n------------------\n");
    for ( i = 0; i < boyut; i++){
        for ( j = 0; j <= boyut; j++){
            printf("%f ", A[i][j]);
        }
        printf("\n");
    }
}

void cozum(float A[N][N], int boyut){
    float x[N];
    int i, j, k;
    float c, sum=0.0;

    for(i=0; i<boyut; i++){
        for(j=0; j<boyut; j++){
            if(j>i){
                c = A[j][i] / A[i][i];
                for(k=0; k<=boyut; k++){
                    A[j][k] -= c * A[i][k];
                }
            }
        }
    }

    x[boyut-1] = A[boyut-1][boyut] / A[boyut-1][boyut-1];
    for(i=boyut-2; i>=0; i--){
        sum=0;
        for(j=i+1; j<boyut; j++){
            sum += A[i][j] * x[j];
		}
        x[i] = (A[i][boyut]-sum) / A[i][i];
    }
    printf("\nCOZUM : \n");
    for(i=0; i<boyut; i++)
        printf("\nx%d = %f\t", i+1, x[i]);
}
