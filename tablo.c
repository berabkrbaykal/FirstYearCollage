#include <stdlib.h>
#include <stdio.h>
int main(){
	int x,y;
	char yon;
	printf("Lütfen x ve y değerlerini giriniz [1-5] ve yön bilgisi giriniz [L,R,U,D]");
	scanf("%d",&x);
	scanf("%d",&y);
	scanf("%s",&yon);

	if (yon == 'R')
	{
		if (y==5)
			y = 1;
		else
			y++;
	}
	else if (yon == 'L')
	{
		if (y==1)
			y = 5;
		else
			y--;
	}
	else if (yon == 'U')
	{
		if (x==1)
			x = 5;
		else
			x--;
	}
	else if (yon == 'D')
	{
		if (x==5)
			x = 1;
		else
			x++;
	}
	else 
		printf("Yanlış yön bilgisi girdiniz");

	printf("%d,%d",x,y);
	return 0;
}
