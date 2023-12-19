#include <stdio.h>
#define PI 3.14

int main()
{
    float ucgen_alan,daire_alan,kare_alan;
    float yukseklik,taban,kare_kenar,yaricap;
    printf("Lütfen yükseklik değerini giriniz:");
    scanf("%f",&yukseklik);
    printf("Lütfen taban değerini giriniz:");
    scanf("%f",&taban);
    printf("Lütfen karenin bir kenarını giriniz:");
    scanf("%f",&kare_kenar);
    printf("Lütfen yarıçap değerini giriniz:");
    scanf("%f",&yaricap);

    ucgen_alan = (taban * yukseklik) / 2;
    daire_alan = (PI * yaricap * yaricap);
    kare_alan = (kare_kenar * kare_kenar);
    printf("Üçgenin alanı: %.2f\nKarenin alanı: %.2f\nDairenin alanı: %.2f",ucgen_alan,kare_alan,daire_alan);
}