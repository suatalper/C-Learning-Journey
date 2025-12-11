#include <stdio.h>
#include <stdlib.h> // Random ve dosya işlemleri için
#include <string.h> // String işlemleri için
#include <time.h>   // Rastgele sayı üretimi için saat bilgisini kullanacağız
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
    char BAS[100][3][50]; // Barkod , Ad , SKt
    //Max 100 ilaç her ilacın 3 özelliği var
    // 0: BArkod 1:AD 2:SKT
    int SSR[100][3]; // Stok,Soguk zincir, recetürü
    float fiyat[100];
};

struct ilac eczane ; // Ramde alan rezerve ediyor
int toplamİlacSayisi = 0;

void barkodÜret(char* hedefString){ 
    char temp[13] = ""; // BArkodu daha sağlıklı oluşturmak için 
    for (int i = 0; i < 12; i++)
    {
        int rakam = rand() %10; // 0-9 arasında sayı üretir %10 yaptığımızd birler basamığını alır sayının
        char rakamStr[2];
        // Rakamı sayıyaya çevirir içinde 2 olmasının sebebi nokta mantığı görmesi
        // örnek olarak rastgele üretien sayı 5 olsun bunu 5. şeklinde okur 2 burda 2.harfi temsil ediyor
        sprintf(rakamStr,"%d",rakam);
        //Dönüştürücü gibi c# daki parse to int mantığı sadece daha farklı (Nereye,nasıl,Neyi) mantığı ile çalışır
        strcat(temp,rakamStr);
    }
    strcpy(hedefString, temp);
}

void DosyayaKaydet(){
 FILE *fp = fopen("ilaclar.txt","w");    
 if (fp == NULL)
 {
    return;
 }
 for (int i = 0; i < toplamİlacSayisi; i++)
 {
    fprintf(
        eczane.BAS[i][1],
        eczane.BAS[i][0],
        eczane.SSR[i][0]
    );
 }
 

}

void DosyadanYule(){
    FILE *fp =fopen("ilaclar.txt","r");
    if (fp == NULL)
    {
        return;
    }
    toplamİlacSayisi = 0;
}
void tutorialFunc(){
    printf("\n--- NASIL KULLANILIR ---\n");
    printf("1. Ilac Girisi menusunden yeni ilac ekleyin.\n");
    printf("2. Sistem otomatik barkod atayacaktir.\n");
    printf("3. Eklediginiz ilaclar 'ilaclar.txt' dosyasina kaydedilir.\n");
    printf("4. Stok Listeleme kismindan durumu gorebilirsiniz.\n\n");
}
void StokListele(){
    
}
void secim1(){
    printf("İlaç Stokları Bölümüne HOŞGELDİNİZ ! \n"); 
    int tutorial = 0;
    printf("Merhaba daha önceden programı kullanmışmıydınız ? \n ");
    printf("Kullandıysanız 1 'e basınız kullanmadıysanız ve Yardıma ihtiyacınız varsa 2'ye basınız\n");
    scanf("%d",&tutorial);
    if (tutorial == 1)
    {
      StokListele();
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
            StokListele();
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
    {   printf("*******************************************************\n");
        printf("Merhaba İlaç Takip Sistemine HOŞ GELDİNİZİ ! \n İlaç stokları için 1'e basınız \n İlaç girişi için 2'ye basınız : \n Çıkış için 3'e basınız : \n");
        printf("*******************************************************\n");
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