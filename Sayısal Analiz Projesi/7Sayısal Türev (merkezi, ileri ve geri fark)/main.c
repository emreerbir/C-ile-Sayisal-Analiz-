#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 25


float f(float x, int derece, float katsayi[N]);
float ileri_fark(float x, float h, float katsayi[N], int derece);
float geri_fark(float x, float h, float katsayi[N], int derece);
float merkezi_fark(float x, float h, float katsayi[N], int derece);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	float katsayi[N] = {0};
	float h, x;
    int derece, i;
    
    
    
    printf("Turevi alinacak denklemin derecesi : ");
    scanf("%d", &derece);
    for ( i = 0; i <= derece; i++){
        printf("x uzeri %d nin carpanini giriniz : ", i);
        scanf("%f",  &katsayi[i]);
    }
    
    
    
    printf("Fark (h) : ");
    scanf("%f", &h);
    printf("Turevine bakilacak nokta (x) : ");
    scanf("%f", &x);
    printf("\n----------------------\n\n");
    
    
    
    printf("Ileri farklar ile sayisal turev sonucu f'(%f) = %f\n", x, ileri_fark(x, h, katsayi, derece));
    printf("Geri farklar ile sayisal turev sonucu f'(%f) = %f\n", x, geri_fark(x, h, katsayi, derece));
    printf("Merkezi farklar ile sayisal turev sonucu f'(%f) = %f\n", x, merkezi_fark(x, h, katsayi, derece));
    
    
    
	return 0;
}

float f(float x, int derece, float katsayi[N]){
	int i=0;
	float sonuc=0;
	
	for(i=0;i<=derece;i++){
		sonuc += katsayi[i]*pow(x, i);
	}
	return sonuc;
}



float ileri_fark(float x, float h, float katsayi[15], int derece){
    float sonuc;
    sonuc = f(x+h, derece, katsayi) - f(x, derece, katsayi);
    sonuc /= h;
    return sonuc;
}

float geri_fark(float x, float h, float katsayi[15], int derece){
    float sonuc;
    sonuc = f(x, derece, katsayi) - f(x-h, derece, katsayi);
    sonuc /= h;
    return sonuc;
}

float merkezi_fark(float x, float h, float katsayi[15], int derece){
    float sonuc;
    sonuc = f(x+h, derece, katsayi) - f(x-h, derece, katsayi);
    sonuc /= 2*h;
    return sonuc;
}

















