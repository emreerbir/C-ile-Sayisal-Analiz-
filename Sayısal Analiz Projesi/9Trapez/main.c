#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 50

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

float f(float x,  float katsayi[N], int derece);
float cozum(float a, float b, float n, float katsayi[N], int derece);


int main() {
	float katsayi[N] = {0}, a, b, n;
    int derece, i;
	
	printf("Integrali alinacak denklemin derecesi : ");
    scanf("%d", &derece);
    for ( i = 0; i <= derece; i++)
    {
        printf("x uzeri %d nin carpanini giriniz : ", i);
        scanf("%f",  &katsayi[i]);
    }
    printf("\n----------------------\n\n");
    
    printf("Integral alinacak araligin baslangic degeri (a): ");
    scanf("%f", &a);
    printf("Integral alinacak araligin bitis degeri (b) : ");
    scanf("%f", &b);
    printf("n degerini giriniz (a-b arasinda kac parabol olacak) (n) : ");
    scanf("%f", &n);
    
    printf("Denklemin %.2f  -  %.2f araligindaki integralinin alani : %f\n", a, b, cozum(a, b, n, katsayi, derece));
	
	return 0;
}


float f(float x,  float katsayi[N], int derece){
	int i=0;
	float sonuc=0;
	
	for(i=0;i<=derece;i++){
		sonuc += katsayi[i]*pow(x, i);
	}
	return sonuc;
}


float cozum(float a, float b, float n, float katsayi[N], int derece){
    float h = (b - a) / n;
    float sonuc = h;
    float toplam = (f(a, katsayi, derece) + f(b, katsayi, derece)) / 2.0;
    while (a != b){
        a += h;
        toplam += f(a, katsayi, derece);
    }

    // alan pozitif olmali
    if (toplam < 0)
        toplam *= -1;

    return sonuc*toplam;
}


