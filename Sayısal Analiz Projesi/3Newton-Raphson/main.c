#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 5

float turev(float x, int derece, float katsayi[N]);
float f(float x, int derece, float katsayi[N]);
float mutlak(float x);
void gercek_koklu(float x0, int derece, float katsayi[N], float gercek_kok, float hata);
void gercek_koksuz(float x0, int derece, float katsayi[N], float hata);
void iterasyon(float x0, int derece, float katsayi[N], int tekrar);

int main() {	
	int i, derece;
	float katsayi[N];
	
	printf("Fonksiyonun derecesini giriniz:");
	scanf("%d", &derece);
	for(i=0;i<=derece;i++){
		printf("x uzeri %d nin katsayisini giriniz:", i);
		scanf("%f", &katsayi[i]);
	}
	

	int secim;
	printf("Iterasyonlu cozum icin 1e	Gercek koklu cozum icin 2ye		Gercek koksuz cozum icin 3e  basin.");
	scanf("%d", &secim);
		
	if(secim==1){
		int tekrar;
		float x0;
		
		printf("Tekrar sayisini giriniz:");
		scanf("%d", &tekrar);
		printf("Baslangic degeri giriniz:");
		scanf("%f", &x0);
		
		iterasyon(x0, derece, katsayi, tekrar);
		
	}
	
	else if(secim==2){
		float hata, gercek_kok, x0;
		
		printf("Gercek koku giriniz:");
		scanf("%f", &gercek_kok);
		printf("Hata payini giriniz:");
		scanf("%f", &hata);
		printf("Baslangic degerini giriniz:");
		scanf("%f", &x0);
		
		gercek_koklu(x0, derece, katsayi, gercek_kok, hata);
		
	}
	
	else if(secim==3){
		float hata, x0;
		
		printf("Hata payini giriniz:");
		scanf("%f", &hata);
		printf("Baslangic degerini giriniz:");
		scanf("%f", &x0);
		
		gercek_koksuz(x0, derece, katsayi, hata);
	}
	
	return 0;
}


float mutlak(float x){
	if(x<0){
		x *= -1;
	}
	return x;
}


float f(float x, int derece, float katsayi[N]){
	int i=0;
	float sonuc=0;
	
	for(i=0;i<=derece;i++){
		sonuc += katsayi[i]*pow(x, i);
	}
	return sonuc;
}


float turev(float x, int derece, float katsayi[N]){
	int i=0;
	float sonuc=0;
	
	for(i=0;i<=derece;i++){
		sonuc += katsayi[i]*i*pow(x, (i-1));
	}
	return sonuc;
}


void gercek_koklu(float x0, int derece, float katsayi[N], float gercek_kok, float hata){
	int i=0;
	do{
		x0=x0-(f(x0, derece, katsayi) / turev(x0, derece, katsayi));
		i++;
	}while(mutlak(gercek_kok-x0)>hata);
	printf("%d. iterasyon sonucunda %f hata ile bulunan kok: %f", i, mutlak(gercek_kok-x0), x0);
}


void gercek_koksuz(float x0, int derece, float katsayi[N], float hata){
	int i=0;
	float x1;
	do{
		i++;
		x1=x0;
		x0=x0-(f(x0, derece, katsayi) / turev(x0, derece, katsayi));
	}while(mutlak(x1-x0)>hata);
	printf("%d. iterasyon sonucunda %f hata ile bulunan kok: %f", i, mutlak(x1-x0), x0);
}


void iterasyon(float x0, int derece, float katsayi[N], int tekrar){
	int i=0;
	do{
		i++;
		x0=x0-(f(x0, derece, katsayi) / turev(x0, derece, katsayi));
	}while(i<tekrar);
	printf("%d. iterasyon sonucunda bulunan kok: %f", i, x0);
}
