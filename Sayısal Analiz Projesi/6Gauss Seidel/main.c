#include <stdio.h>
#include <math.h>

#define N 20

void matris_yazdir(float matris[N][N], int boyut);
void matris_al(float matris[N][N], int boyut);
void denklem(float matris[N][N], int boyut);
void cozum(float matris[N][N], int boyut, float hpayi);

int main(){
	float matris[N][N]; float B[N]; float hpayi;
	int boyut; int i; int j;
	
	do{
		printf("Matrisin Boyutunu Giriniz: ");
		scanf("%d", &boyut);
		
	} while(boyut < 1);	
		
	for(i = 0; i < boyut; i++){
		printf("\n %d. Denklem\n\n", i+1);
		for(j = 0; j < boyut; j++){
			printf("x%d'nin katsayisi: ", j+1);
			scanf("%f", &matris[i][j]);
		}
		printf("Denklemin Sonucu: ");
		scanf("%f", &matris[i][boyut]);
	}	
	
	denklem(matris, boyut);
	
	printf("\nIterasyon uygulanacak matrisin son hali: \n\n");
	matris_yazdir(matris, boyut);
	
	printf("\nHata payini giriniz: ");
	scanf("%f", &hpayi);
	
	cozum(matris, boyut, hpayi);
}

void matris_yazdir(float matris[N][N], int boyut){
	int i; int j;
	
	for(i = 0; i < boyut; i++){
		for(j = 0; j <= boyut; j++){
			
			if(j == boyut){
				printf(" || %.4f", matris[i][j]);
			}else{
				printf("%.4f ", matris[i][j]);
			}
		}
		printf("\n\n");
	}
}

void denklem(float matris[N][N], int boyut){
	int i, j, k, index=0;
	float temp, max;
	
	for(i = 0; i < boyut; i++){
		max = -9999;
		for(j = i; j < boyut; j++){
			if(matris[i][j] > max){
			    max = matris[i][j];
				index = j;				
			}
		}
		if(i != index){
			for(k = 0; k <= boyut; k++){
				temp = matris[i][k];
				matris[i][k] = matris[index][k];
				matris[index][k] = temp; 
			}
		}
	}
}

void cozum(float matris[N][N], int boyut, float hpayi){
	float sum; float K[N]; float temp[N] = {0};
	int i; int j; float hata; int iterasyon = 0;
	
	for(i = 0; i < boyut; i++){
		printf("\n%d. bilinmezin baslangic degerini giriniz : ", i+1);
		scanf("%f", &K[i]);
	}
	
	do{
		iterasyon++; hata = 0;
	    for(i = 0; i < boyut; i++){
		    sum = 0; 
		    for(j = 0; j < boyut; j++){
	    		if(i != j){
	    			sum += matris[i][j] * K[j];
	    		}
    		}
    		K[i] = (matris[i][boyut] - sum) / matris[i][i];
    		
    		if(hata<fabs(K[i] - temp[i])){
    			hata=fabs(K[i] - temp[i]);
			}
			
    		temp[i] = K[i];
    		printf("\n%d. iterasyondaki %d. kok degeri = %f", iterasyon, i+1, K[i]);
    	}
		printf("\n");	
    }while(hpayi < hata);
}
