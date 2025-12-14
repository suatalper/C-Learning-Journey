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
    //Dosyayı yoksa oluşturuyor vara açıyor 
    // ilacDefteri burda dosya bilgilerini tutar yani git ilaclar.txt dosyasını akldında tut demek gibi bişey %d ie aynı mantık
 FILE *ilacDefteri = fopen("ilaclar.txt","a");   
 //açılıp açılmadığını kontrol ediyoruz 
 if (ilacDefteri == NULL)
 {
    return;
 }
 //diziler 0 dan başladığı için -1 dememiz lazım çünkü ilaç kaydını 1 den başlattık
 int sonEklenenIndex = toplamİlacSayisi - 1;

    fprintf(ilacDefteri, "%s %s %s %d %d %d %.2f\n",
    eczane.BAS[sonEklenenIndex][BARKOD],
    eczane.BAS[sonEklenenIndex][ISIM],
    eczane.BAS[sonEklenenIndex][SKT],
    eczane.SSR[sonEklenenIndex][STOK],
    eczane.SSR[sonEklenenIndex][SOGUK],
    eczane.SSR[sonEklenenIndex][RECETE],
    eczane.fiyat[sonEklenenIndex]
    );
   fclose(ilacDefteri);
   printf("Yeni ilaçlar Eklendi");
}
void DosyadanYuke(){

    //Mantığına bakmadım
    FILE *ilacDefteri =fopen("ilaclar.txt","r");
    if (ilacDefteri == NULL)
    {
        return;
    }
    toplamİlacSayisi = 0;
    while (!feof(ilacDefteri)) //Dosya bitmediği sürece okumaya devam et demektir ! kullanılması sebebi while döngüsü koşul yanlış olduğu sürece çalışmasıdır burda feof fonksiyonu dosya sonuna gelmediği sürece bize 1 verecek bu yüzden 1 alıp 0
    {
        int sonuc = fscanf(
            ilacDefteri,"%s %s %s %d %d %d %f \n",
            eczane.BAS[toplamİlacSayisi][BARKOD], // char türünde & ihtiyaç yok çünkü dizinin ismi o dizinin başlangıç adresisidr
            eczane.BAS[toplamİlacSayisi][ISIM],
            eczane.BAS[toplamİlacSayisi][SKT],
            &eczane.SSR[toplamİlacSayisi][STOK], //& gerekli çünkü dosyadaki verileri rame yazıyoruz yani bir nevi rame kaydediyoruz
            &eczane.SSR[toplamİlacSayisi][SOGUK], 
            &eczane.SSR[toplamİlacSayisi][RECETE],
            &eczane.fiyat[toplamİlacSayisi]       
        );
        if (sonuc == 7) // 7 tane değer girildiğine emin oluyoruz
        {
            toplamİlacSayisi++;
        }
        
    }
    fclose(ilacDefteri);
    printf("%d adet ilac kaydı yüklendi\n",toplamİlacSayisi);
    
}
void secim2Tutorial (){

    //MAntığına bakmadım
   printf("\n--- YENI ILAC GIRISI ---\n"); 
   if (toplamİlacSayisi >= 100)
   {
     printf("Hata : Stok Kapasitesi dolu ! (max 100) \n");
     return;
   }

    barkodÜret(eczane.BAS[toplamİlacSayisi][BARKOD]);
    printf("Barkod atandı : %s \n",eczane.BAS[toplamİlacSayisi][BARKOD]);

    printf("Ilac Ismi (Bosluksuz giriniz): ");
    scanf("%s", eczane.BAS[toplamİlacSayisi][ISIM]);

    printf("Son Kullanma Tarihi (GG.AA.YYYY): ");
    scanf("%s", eczane.BAS[toplamİlacSayisi][SKT]);
   
    printf("Stok Adedi: ");
    scanf("%d", &eczane.SSR[toplamİlacSayisi][STOK]);
   
    printf("Soguk Zincir mi? (1: Evet, 0: Hayir): ");
    scanf("%d", &eczane.SSR[toplamİlacSayisi][SOGUK]);

    printf("Receteli mi? (1: Evet, 0: Hayir): ");
    scanf("%d", &eczane.SSR[toplamİlacSayisi][RECETE]);

    printf("Birim Fiyati: ");
    scanf("%f", &eczane.fiyat[toplamİlacSayisi]);

    toplamİlacSayisi++; // Sayacı 1 artır
    
    DosyayaKaydet(); // Her eklemeden sonra dosyayı güncelle
    printf("Ilac basariyla eklendi!\n");

   
}
void tutorialFunc(){
    printf("\n--- NASIL KULLANILIR ---\n");
    printf("1. Ilac Girisi menusunden yeni ilac ekleyin.\n");
    printf("2. Sistem otomatik barkod atayacaktir.\n");
    printf("3. Eklediginiz ilaclar 'ilaclar.txt' dosyasina kaydedilir.\n");
    printf("4. Stok Listeleme kismindan durumu gorebilirsiniz.\n\n");
    secim2Tutorial();
}
void StokListele(){
    printf("\n%-15s %-15s %-12s %-6s %-8s %-8s %-8s\n", 
           "BARKOD", "ISIM", "SKT", "STOK", "SOGUK", "RECETE", "FIYAT");
    printf("------------------------------------------------------------------------------\n");

    for(int i = 0; i < toplamİlacSayisi; i++) {
        printf("%-15s %-15s %-12s %-6d %-8s %-8s %-8.2f\n",
            eczane.BAS[i][BARKOD],
            eczane.BAS[i][ISIM],
            eczane.BAS[i][SKT],
            eczane.SSR[i][STOK],
            eczane.SSR[i][SOGUK] == 1 ? "EVET" : "HAYIR", // Ternary If (Kısa if yapısı) mantığına bak
            eczane.SSR[i][RECETE] == 1 ? "EVET" : "HAYIR",
            eczane.fiyat[i]
        );
    }
    printf("\n");
}
void secim1(){
    printf("İlaç Stokları Bölümüne HOŞGELDİNİZ ! \n"); 
    StokListele();
}
void ilacgiris(){
    printf("\n--- YENI ILAC GIRISI ---\n"); 
   if (toplamİlacSayisi >= 100)
   {
     printf("Hata : Stok Kapasitesi dolu ! (max 100) \n");
     return;
   }

    barkodÜret(eczane.BAS[toplamİlacSayisi][BARKOD]);
    printf("Barkod atandı : %s \n",eczane.BAS[toplamİlacSayisi][BARKOD]);

    printf("Ilac Ismi (Bosluksuz giriniz): ");
    scanf("%s", eczane.BAS[toplamİlacSayisi][ISIM]);

    printf("Son Kullanma Tarihi (GG.AA.YYYY): ");
    scanf("%s", eczane.BAS[toplamİlacSayisi][SKT]);
   
    printf("Stok Adedi: ");
    scanf("%d", &eczane.SSR[toplamİlacSayisi][STOK]);
   
    printf("Soguk Zincir mi? (1: Evet, 0: Hayir): ");
    scanf("%d", &eczane.SSR[toplamİlacSayisi][SOGUK]);

    printf("Receteli mi? (1: Evet, 0: Hayir): ");
    scanf("%d", &eczane.SSR[toplamİlacSayisi][RECETE]);

    printf("Birim Fiyati: ");
    scanf("%f", &eczane.fiyat[toplamİlacSayisi]);

    toplamİlacSayisi++; // Sayacı 1 artır
    
    DosyayaKaydet(); // Her eklemeden sonra dosyayı güncelle
    printf("Ilac basariyla eklendi!\n");

}
void secim2 (){    
int tutorial = 0;
    printf("Merhaba daha önceden programı kullanmışmıydınız ? \n ");
    printf("Kullandıysanız 1 'e basınız kullanmadıysanız ve Yardıma ihtiyacınız varsa 2'ye basınız\n");
    scanf("%d",&tutorial);
    if (tutorial == 1)
    {
        ilacgiris();
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
           ilacgiris();
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

   printf("\n--- YENI ILAC GIRISI ---\n"); 
   if (toplamİlacSayisi >= 100)
   {
     printf("Hata : Stok Kapasitesi dolu ! (max 100) \n");
     return;
   }

    barkodÜret(eczane.BAS[toplamİlacSayisi][BARKOD]);
    printf("Barkod atandı : %s \n",eczane.BAS[toplamİlacSayisi][BARKOD]);

    printf("Ilac Ismi (Bosluksuz giriniz): ");
    scanf("%s", eczane.BAS[toplamİlacSayisi][ISIM]);

    printf("Son Kullanma Tarihi (GG.AA.YYYY): ");
    scanf("%s", eczane.BAS[toplamİlacSayisi][SKT]);
   
    printf("Stok Adedi: ");
    scanf("%d", &eczane.SSR[toplamİlacSayisi][STOK]);
   
    printf("Soguk Zincir mi? (1: Evet, 0: Hayir): ");
    scanf("%d", &eczane.SSR[toplamİlacSayisi][SOGUK]);

    printf("Receteli mi? (1: Evet, 0: Hayir): ");
    scanf("%d", &eczane.SSR[toplamİlacSayisi][RECETE]);

    printf("Birim Fiyati: ");
    scanf("%f", &eczane.fiyat[toplamİlacSayisi]);

    toplamİlacSayisi++; // Sayacı 1 artır
    
    DosyayaKaydet(); // Her eklemeden sonra dosyayı güncelle
    printf("Ilac basariyla eklendi!\n");

   
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
    DosyadanYuke();
    menu();
    return 0;
}