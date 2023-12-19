#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Lütfen dizinizin eleman sayısını giriniz:");
    scanf("%d",&n);

    int dizi[n];
    for (int sayac = 1; sayac <= n; sayac++)
    {
        printf("%d. eleman:",sayac);
        scanf("%d",&dizi[sayac]);
    }
    
    int yakin_deger;
    printf("\nDizi içinde en yakın değerini bulunacak bir sayı giriniz:");
    scanf("%d",&yakin_deger);

    int kontrol = dizi[0];
    for(int i = 1; i <= n; i++)
    {
        if (abs(yakin_deger - dizi[i]) < abs(yakin_deger - kontrol))
            kontrol = dizi[i];
    }
    printf("İstenilen değere en yakın dizi elemanı: %d",kontrol);
}