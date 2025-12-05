#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
//1.BAŞLA
//2.ilaç ismini gir
//3.İlaçtan kaç tane geldiğini gir
//4.İlaç reçeteli mi ?
//  1.EVETSE reçeteli fiyatonı gir
//  2.HAYIRSA normal fiyatını gir
//5.İlaç Satışı Oldu mu ?
//  1.EVETSE ilaç stoğundan satılan adet kadar azalt
//  2.İlaç stoğu baştaki stoğun %20 si kadarsa kullanıcıya uyarı ver
//  3.HAYIRSA GİT 6.adım
//6.BİTİR
void secim1(){
    printf("İlaç Stokları Bölümüne HOŞGELDİNİZ !"); 
}
void secim2 (){
    printf("İlaç girişi kısmına HOŞGELDİNİZ");
}
void menu (){

    int secim = 0 ;
    bool secimdogrulayci = false;

    while (secimdogrulayci == false)
    {
        printf("Merhaba İlaç Takip Sistemine HOŞ GELDİNİZİ ! \n İlaç stokları için 1'e basınız \n İlaç girişi için 2'ye basınız : \n Çıkış için 3'e basınız : ");
        scanf("%d",&secim);
        if (secim == 1)
        {
            secim1();
            break;
        }
        else if (secim == 2)
        {
            secim2();
            break;
        }
        else if (secim == 3)
        {
            exit(0);
        }
        
        else{
            printf("Menümüzde sadece 1 veya 2 opsiyonu bulunmaktadır lütfen bunlardan birini seç ! Şimdi ana menüye göderiliyorsun\n");
            continue;
        }
    }
}

struct ilac
{
    char barkod[20];
    char ad [50];
    int stok ;
    float fiyat;
    char skt [15];
    int sogukzincir;
    int recetetur;
};

int main() {
    SetConsoleOutputCP(65001);
    menu();
    return 0;
}