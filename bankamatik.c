#include <stdio.h>
#include <math.h>

int main()
{
	int para;
	printf("Lütfen ne kadar para istediğinizi giriniz.");
	scanf("%d",&para);
	
	int ikiYuz,yuz,elli,yirmi,on,bes;
	int bolum;

	bolum = para % 200;
	ikiYuz = para / 200;
	para = bolum;
	
	bolum = para % 100;
	yuz = para / 100;
	para = bolum;

	bolum = para % 50;
	elli = para / 50;
	para = bolum;

	bolum = para % 20;
	yirmi = para / 20;
	para = bolum;

	bolum = para % 10;
	on = para / 10;
	para = bolum;

	bolum = para % 5;
	bes = para / 5;
	para = bolum;

	printf("200'lük banknotlar : % d\n", ikiYuz);
	printf("100'lük banknotlar : % d\n", yuz);
	printf("50'lik banknotlar : % d\n", elli);
	printf("20'lik banknotlar : % d\n", yirmi);
	printf("10'luk banknotlar : % d\n", on);
	printf("5'lik banknotlar : % d\n", bes);
}
