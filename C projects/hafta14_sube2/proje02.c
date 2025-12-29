#include <stdio.h>
#include <windows.h>

int fiyathesapla(){
    int sayac = 0,kontroledici = 0,sayac1 = 1;
    int urunFiyat [] = {0};
    int urunAdet [] = {0};
    int urunToplamFiyat [] = {0};
    float kdvliFiyat = 0;


    while (1)
    {
        printf("%d.ürünün fiyatını giriniz : ",sayac +1);
        scanf("%d",&urunFiyat[sayac]);
        printf("Kaç adet aldınız : ");
        scanf("%d",&urunAdet[sayac]);
        kdvliFiyat = urunFiyat[sayac] + urunFiyat[sayac]*0.18;
        urunToplamFiyat[sayac] = kdvliFiyat * urunAdet[sayac] + urunToplamFiyat[sayac1 -1];
        printf("Daha fazla ürün girişi yapmak için 1'e basınız istemiyorsanız 2'ye basınız ");
        scanf("%d",&kontroledici);


        if (kontroledici == 1)
        {
            sayac++;
            continue;
        }
        else if (kontroledici==2)
        {
            return urunToplamFiyat[sayac];
        }
    }
    
}

int main() {
    SetConsoleOutputCP(65001);

    int toplamFiyat = fiyathesapla();
    printf("Toplam Fiyat: %d", toplamFiyat);
    return 0;
}