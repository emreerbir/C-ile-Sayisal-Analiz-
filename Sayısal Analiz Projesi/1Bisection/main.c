#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 20

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
float mutlak(float x);
float fonksiyondegeri(float x, float katsayi[N], int derece);
void iterasyon(float x0, float x1, int tekrar, float katsayi[N], int derece);
void gercek_koklu(float gercek_kok, float x0, float x1, float katsayi[N], int derece, float hata);
void gercek_koksuz(float x0, float x1, float katsayi[N], int derece, float hata);

int main() {
	float katsayi[N];
	int derece;
	int i=0;
	int j=0;
	
	printf("Islem yapilacak denklemin derecesini giriniz:");
	scanf("%d", &derece);
	
	for(i=0; i<=derece; i++){
		printf("x uzeri %d nin katsayisini giriniz:", i);
		scanf("%f", &katsayi[i]);
	}
	
	
	float x0, x1;
	printf("Islem yapilacak araligi giriniz:");
	scanf("%f %f", &x0, &x1);
	
	
	if((fonksiyondegeri(x0, katsayi, derece)*fonksiyondegeri(x1, katsayi, derece))>0){
		printf("Bu aralikta kok yok.");
	}
	
	else{
		float b;
		printf("Hata payi veya iterasyon sayisini giriniz(Iterasyon sayisi 2den buyuk olmali.):");
		scanf("%f", &b);
		
		if(b<3){
			float gercek_kok;
			printf("Gercek koku giriniz(Bilinmiyorsa 999 giriniz.):");
			scanf("%f", &gercek_kok);
			if(gercek_kok==999){
				gercek_koksuz(x0, x1, katsayi, derece, b);
			}
			else{
				gercek_koklu(gercek_kok, x0, x1, katsayi, derece, b);
			}
		}	
		else{
			iterasyon(x0, x1, b, katsayi, derece);	
		}		
	}
		
	return 0;
}

float mutlak(float x){
	if (x < 0){
        x *= -1;
	}
    return x;
}

float fonksiyondegeri(float x, float katsayi[N], int derece){
	int i;
	float sonuc=0;
	
	for(i=0;i<derece;i++){
		sonuc += katsayi[i]*pow(x,i);
	}
	return sonuc;
}

void iterasyon(float x0, float x1, int tekrar, float katsayi[N], int derece){
	int i=0, j=0, sonuc;
	float c, alt, ust, orta;
	
	for(i=0;i<tekrar;i++){
		c=(x0+x1)/2;
		alt=fonksiyondegeri(x0, katsayi, derece);
		orta=fonksiyondegeri(c, katsayi, derece);
		ust=fonksiyondegeri(x1, katsayi, derece);
		
		if(alt*orta<0){
			x1=c;
		}
		else{
			x0=c;
		}
	}
	
	printf("%d. iterasyon sonucu bulunan deger: %f", tekrar, orta);
}


void gercek_koklu(float gercek_kok, float x0, float x1, float katsayi[N], int derece, float hata){
	int i=0, alt, orta, ust, c;
	do{
		i++;
		c=(x0+x1)/2;
		alt=fonksiyondegeri(x0, katsayi, derece);
		orta=fonksiyondegeri(c, katsayi, derece);
		ust=fonksiyondegeri(x1, katsayi, derece);
		
		if(alt*orta<0){
			x1=c;
		}
		else{
			x0=c;
		}
	}while(mutlak(gercek_kok-c)<hata);
	printf("%f Hata ile bulunan kok: %f", mutlak(gercek_kok-c), c);
}


void gercek_koksuz(float x0, float x1, float katsayi[N], int derece, float hata){
	int i=0, alt, orta, ust, c;
	do{
		i++;
		c=(x0+x1)/2;
		alt=fonksiyondegeri(x0, katsayi, derece);
		orta=fonksiyondegeri(c, katsayi, derece);
		ust=fonksiyondegeri(x1, katsayi, derece);
		
		if(alt*orta<0){
			x1=c;
		}
		else{
			x0=c;
		}
	}while(((x1-x0)/pow(2,i))<hata);
	printf("%d. Iterasyon sonucunda bulunan kok: %f", i, c);
}
