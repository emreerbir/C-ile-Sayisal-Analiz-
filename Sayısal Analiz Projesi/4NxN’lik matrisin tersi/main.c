#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 20

void matris_yaz(float matris[N][N], int boyut);
void ters(float matris[N][N], float ters_matris[N][N], int boyut);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	float matris[N][N], ters_matris[N][N];
    int boyut=0;
	int i=0, j=0;
    
    printf("Matrisin boyutunu giriniz : ");
    scanf("%d", &boyut);

    for ( i = 0; i < boyut; i++){
        for ( j = 0; j < boyut; j++){
            printf("\n%d. sutun %d. satirdaki elemani giriniz : ", (i+1), (j+1));
            scanf("%f", &matris[i][j]);
        }
    }
		
	printf("\nMatris\n------------------\n");
    matris_yaz(matris, boyut);
    ters(matris, ters_matris, boyut);
    printf("\nMatrisin tersi\n------------------\n");
    matris_yaz(ters_matris, boyut);
    printf("\n");	
	
	return 0;
}





void matris_yaz(float matris[N][N], int boyut){
	int i, j;
    for ( i = 0; i < boyut; i++)
    {
        for ( j = 0; j < boyut; j++)
        {
            printf("%.2f ", matris[i][j]);
        }
        printf("\n");   
    }
}



void ters(float matris[N][N], float ters_matris[N][N], int boyut){
	int i, j, k;
    float x, y;

    for (i=0; i < boyut; i++)
    {
        for ( j = 0; j < boyut; j++)
        {
            if (i == j)
                ters_matris[i][j] = 1;
            else
                ters_matris[i][j] = 0;
        }
    }
    for ( i = 0; i < boyut; i++)
    {
        x = matris[i][i];
        for ( j = 0; j < boyut; j++)
        {
            matris[i][j] /= x;
            ters_matris[i][j] /= x;
        }
        for ( k = 0; k < boyut; k++)
        {
            if (k != i)
            {
                y = matris[k][i];
                for ( j = 0; j < boyut; j++)
                {
                    matris[k][j] -= matris[i][j]*y;
                    ters_matris[k][j] -= ters_matris[i][j]*y;
                }   
            }
        }
    }
}



