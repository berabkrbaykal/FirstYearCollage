#include <stdio.h>
#include <math.h>

int main()
{
	float k1,k2,k3;
	printf("Lütfen sizden istenilen kenar değerlerini giriniz\n");
	scanf("%f\n%f\n%f",&k1,&k2,&k3);

	if ((k1-k2 <= k3) && (k1+k2 >= k3) && (k1-k3 <= k2) && (k1+k3 >= k2) && (k2-k3 <= k1) && (k2+k3 >= k1))
	{
		if ((k1 == k2) && (k1 == k2) && (k2 == k3))
			printf("Üçgenimiz eşkenar üçgendir.");
		else if ((k1 == k2) || (k1 == k2) || (k2 == k3))
			printf("üçgenimiz ikizkenar üçgendir.");
		else
			printf("Üçgenimiz çeşitkenar üçgendir.");

		float alan,cevre;
		float u = (k1+k2+k3) / 2; // u burada işlem kolaylığı için oluşturduğum bir tanım
		alan = sqrt(u*(u-k1)*(u-k2)*(u-k3));
		cevre = (k1+k2+k3);

		printf("\nÜçgenin alanı: %.2f\n",alan);
		printf("Üçgenin çevresi: %.2f",cevre);
	}
	else
		printf("Girdiğiniz kenarlar üçgen olma koşulunu sağlamamaktadır.");
}
