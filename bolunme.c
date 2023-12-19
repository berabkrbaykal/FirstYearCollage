#include <stdio.h>

int main(){
    int sayi = 100;
    int sayac = 0;
    int birler,onlar,yuzler;

    while(sayi < 1000)
    {
        birler = sayi % 10;
        onlar = (sayi / 10) % 10;
        yuzler = sayi / 100;

        if ((sayi % 5 == 0)&&(birler != onlar)&&(onlar != yuzler)&&(yuzler != birler))
        {
            printf("%d\n",sayi);
            sayac++;
        }
        sayi++;
    }
    printf("3 basamaklı rakamları farklı 5'e tam bölünen sayıların adedi : %d",sayac);
}