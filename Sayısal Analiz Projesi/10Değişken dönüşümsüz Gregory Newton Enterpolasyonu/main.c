#include<stdio.h>
#include<math.h>

int fact(int);
float f(float,int);

main(){
	float x[10],y[10],d[10][10],a,u,h,tsum,sum=0;
	int i,j,n;

	printf("Kac tane x var?\t");
	scanf("%d",&n);
	printf("Baslangic degerini giriniz: \t\t");
	scanf("%f",&x[0]);
	printf("x'ler arasi farki giriniz: \t");
	scanf("%f",&h);


	for(i=0;i<n;i++){
		x[i+1]=x[i]+h;
	}

	for(i=0;i<n;i++){
		printf("\nf(%f) : ", (x[0] + (h * i)));
		scanf("%f",&y[i]);
	}

	for(i=0;i<n;i++){
		d[0][i]=y[i];
	}

	printf("Fark tablosu: \n");

	for(i=1;i<n;i++){
		for(j=0;j<n-i;j++){
    		d[i][j]=d[i-1][j+1]-d[i-1][j];
			printf("d[%d][%d]  %f \t",i,j,d[i][j]);
		}
		printf("\n");
	}

	printf("Görmek istediginiz x degerini giriniz: \t");
	scanf("%f",&a);
	u=(a-x[0])/h;

	printf("%f",y[0]);

	for(i=1;i<n;i++){
		printf(" + %f",(f(u,i)*d[i][0])/fact(i));
    	sum=sum+(f(u,i)*d[i][0])/fact(i);
	}

	tsum=sum+y[0];
	printf("\nBulunun sonuc f(%f)=%f",a,tsum);

	return 0;
}

float f(float x,int i){
    int l;
    float sonuc=x;
    for(l=1;l<i;l++)
        sonuc=sonuc*(x-l);
    return (sonuc);
}

int fact(int k){
    int sonuc=1,i;
    
    for(i=1;i<=k;i++){
    	sonuc=sonuc*i;
	}
        
    return (sonuc);
}
