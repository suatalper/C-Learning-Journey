#include <stdio.h>
#include <windows.h>
/* 
Marketten istediği kadar ürün alan bir müşteri her ürüne %18 KDV ÖDEMEKTEDİR
merketten çıktıktan sonra evde almış olduğu ürünlerin kdvlerini düşerek toplam odedği 
fiyatı hesaplamaktadır


BUNU WHİLE DÖGÜSÜ İLE HOCANIN YAPTIĞI GİBİ YAP 

snippetine windows kutuphanesine ve set concsol out cp ayarla


*/
int main() {
    SetConsoleOutputCP(65001);

    
    float toplamFiyat = 0,kdvsizFiyat = 0,kdvsizToplamFiyat = 0;
    int sayac = 0,kontrolEdici;
    float urunFiyat [] = {0};
    

    while (1)
    {   
        printf("%d. Urunun fiyatini giriniz : ",sayac+1);
        scanf("%f",&urunFiyat[sayac]);
        printf("Daha fazla ürün girişi yapmak için 1'e basınız istemiyorsanız 2'ye basınız ");
        scanf("%d",&kontrolEdici);

        kdvsizFiyat =  urunFiyat[sayac] / 1.18;
        kdvsizToplamFiyat = kdvsizToplamFiyat + kdvsizFiyat;
        toplamFiyat = urunFiyat[sayac] + toplamFiyat ;

        sayac++;

        if (kontrolEdici == 1)
        {
            continue;
        }
        else if (kontrolEdici==2)
        {
           break;
        }else
        {
            kontrolEdici = 0;
            printf("Lütfen geçerli bir değer giriniz (1 VEYA 2 GİRİNİZ): ");
            scanf("%d",kontrolEdici);
            if (kontrolEdici == 1)
            {
                continue;
            }
            else if (kontrolEdici==2)
            {
                 break;
            }

        }
    }
       
       printf("%d tane urun icin \n kdvsiz odediginiz tutar : %f \n kdvli tutar : %f \n",sayac,kdvsizToplamFiyat,toplamFiyat);
       float betterprice = toplamFiyat - kdvsizToplamFiyat;
       printf(" eger dunyamizda kdv olmasaydi %f tl daha az harcamis olucakti",betterprice );
    
    return 0;
}