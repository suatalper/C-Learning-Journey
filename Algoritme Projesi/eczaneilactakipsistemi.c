#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
// BAS dizisi için indeksler (0, 1, 2)
#define BARKOD 0
#define ISIM   1
#define SKT  2  

// SSR dizisi için indeksler (0, 1, 2)
#define STOK   0
#define SOGUK  1
#define RECETE 2

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

struct ilac
{
   // char barkod[20];
   // char ad [50];
    //char skt [15];

    char BAS[100][3][50]; // Barkod , Ad , SKt
    //Max 100 ilaç her ilacın 3 özelliği var
    // 0: BArkod 1:AD 2:SKT
    int SSR[100][3]; // Stok,Soguk zincir, recetürü
    float fiyat[100];
};
tutorialFunc(){

    printf("Burda nasıl yapılcağını anlat");
}
secim1İlacgiris(){
    
}
void secim1(){
    printf("İlaç Stokları Bölümüne HOŞGELDİNİZ ! \n"); 
    int tutorial = 0;
    printf("Merhaba daha önceden programı kullanmışmıydınız ? \n ");
    printf("Kullandıysanız 1 'e basınız kullanmadıysanız ve Yardıma ihtiyacınız varsa 2'ye basınız\n");
    scanf("%d",&tutorial);
    if (tutorial == 1)
    {
      secim1İlacgiris();
    }
    else if (tutorial == 2)
    {
        tutorialFunc();
    }
    else
    {
        printf("lütfen geçerli bir değer giriniz");
        if (tutorial == 1)
        {
            secim1İlacgiris();
        }
        else if (tutorial == 2)
        {
            tutorialFunc();
        }
        else
        {
            printf("lütfen geçerli bir değer giriniz");
        }
        
    }
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
int main() {
    SetConsoleOutputCP(65001);
    menu();
    return 0;
}