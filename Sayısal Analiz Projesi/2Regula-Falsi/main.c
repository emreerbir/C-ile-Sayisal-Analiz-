#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 25


float f(float x, int derece, float katsayi[N]);
float mutlak(float x);
void gercek_koklu(float x0, float x1, int derece, float katsayi[N], float gercek_kok, float hata);
void gercek_koksuz(float x0, float x1, int derece, float katsayi[N], float hata);
void iterasyon(float x0, float x1, int derece, float katsayi[N], int tekrar);



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
	float x0, x1;
	printf("Iterasyonlu cozum icin 1e	Gercek koklu cozum icin 2ye		Gercek koksuz cozum icin 3e  basin.");
	scanf("%d", &secim);
	printf("\nBakilacak x degerleri aralagi (alt sinir ve ust siniri aralarinda bosluk olacak sekilde giriniz.) : ");
    scanf("%f %f", &x0, &x1);
	
	
	if(secim==1){
		int tekrar;
		
		printf("Tekrar sayisini giriniz:");
		scanf("%d", &tekrar);
		
		iterasyon(x0, x1, derece, katsayi, tekrar);
		
	}
	
	else if(secim==2){
		float hata, gercek_kok;
		
		printf("Gercek koku giriniz:");
		scanf("%f", &gercek_kok);
		printf("Hata payini giriniz:");
		scanf("%f", &hata);

		
		gercek_koklu(x0, x1, derece, katsayi, gercek_kok, hata);
		
	}
	
	else if(secim==3){
		float hata;
		
		printf("Hata payini giriniz:");
		scanf("%f", &hata);

		
		gercek_koksuz(x0, x1, derece, katsayi, hata);
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


void iterasyon(float x0, float x1, int derece, float katsayi[N], int tekrar){
	int i;
    float alt, orta, ust, c;
    for ( i = 0; i < tekrar; i++)
    {
        alt = f(x0, derece, katsayi);
        ust = f(x1, derece, katsayi);

        c = ( x1*alt - x0*ust ) / ( alt-ust );
        orta = f(c, derece, katsayi);
        if (alt*orta < 0)
            x1 = c;
        else
            x0 = c;

        printf("%d. iterasyon sonucunda bulunan kok: %f", i, x0);
    }
}


void gercek_koksuz(float x0, float x1, int derece, float katsayi[N], float hata){
	float alt, orta, ust, c, hata_miktari;
    int i=0;
    
    do{
		i++;
		alt=f(x0, derece, katsayi);
		ust=f(x1, derece, katsayi);
		c = ( x1*alt - x0*ust ) / ( alt-ust );
		orta=f(c, derece, katsayi);
		
		if(alt*orta<0){
			x1=c;
			hata_miktari = mutlak( c - x1 );
		}
		else{
			x0=c;
			hata_miktari = mutlak( c - x1 );
		}
	}while(hata_miktari > hata);
	printf("%d. Iterasyon sonucunda bulunan kok: %f", i, c);
}



void gercek_koklu(float x0, float x1, int derece, float katsayi[N], float gercek_kok, float hata){
	float alt, orta, ust, c, hata_miktari;
	int i=0;
    
    do{
		i++;
		alt=f(x0, derece, katsayi);
		ust=f(x1, derece, katsayi);
		c = ( x1*alt - x0*ust ) / ( alt-ust );
		orta = f(c, derece, katsayi);
		
		
		if(alt*orta<0){
			x1=c;
		}
		else{
			x0=c;
		}
		hata_miktari = mutlak(c - gercek_kok);
	}while(hata_miktari > hata);
	printf("%f Hata ile bulunan kok: %f", mutlak(gercek_kok-c), c);
}









