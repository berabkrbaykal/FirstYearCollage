#include <stdio.h>

int main(){
    int nufus = 85279553;
    float artis_orani = 12.5 / 1000;
    int yil = 2022;
    while (nufus < 100000000)
    {
        nufus = nufus + (nufus * artis_orani);
        yil++;
    }
    printf("Nüfus sayısı: %d\n",nufus);
    printf("100 milyonu geçtiğindeki yıl: %d",yil);
}