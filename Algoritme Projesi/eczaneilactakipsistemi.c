#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>

#define MAX_ILAC 100
#define DOSYA_ADI "ilaclar.txt"

// Ileriye dönük genişletilebilir, tek bir ilaç yapısı
typedef struct {
    char barkod[20];
    char isim[50];
    char skt[15]; // Son Kullanma Tarihi
    int stok;
    int sogukZincir; // 1: Evet, 0: Hayır
    int receteli;    // 1: Evet, 0: Hayır
    float fiyat;
} Ilac;

Ilac ilaclar[MAX_ILAC];
int toplamIlacSayisi = 0;

// Fonksiyon Prototipleri
void barkodUret(char* hedefString);
void DosyayaKaydet();
void DosyadanYukle();
void IlacEkle();
void StokListele();
void Menu();

// Yardımcı fonksiyon: Tampon belleği temizler (scanf sorunlarını önlemek için)
void tamponTemizle() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void barkodUret(char* hedefString) { 
    char temp[13] = ""; 
    for (int i = 0; i < 12; i++) {
        int rakam = rand() % 10; 
        char rakamStr[2];
        sprintf(rakamStr, "%d", rakam);
        strcat(temp, rakamStr);
    }
    strcpy(hedefString, temp);
}

void DosyayaKaydet() {
    FILE *ilacDefteri = fopen(DOSYA_ADI, "w"); // "w" modu ile dosyayı sıfırdan yazıyoruz (daha güvenli)
    if (ilacDefteri == NULL) {
        printf("Hata: Dosya acilamadi!\n");
        return;
    }

    for (int i = 0; i < toplamIlacSayisi; i++) {
        fprintf(ilacDefteri, "%s %s %s %d %d %d %.2f\n",
            ilaclar[i].barkod,
            ilaclar[i].isim,
            ilaclar[i].skt,
            ilaclar[i].stok,
            ilaclar[i].sogukZincir,
            ilaclar[i].receteli,
            ilaclar[i].fiyat
        );
    }
    fclose(ilacDefteri);
    // printf("Kayitlar guncellendi.\n"); // İsteğe bağlı, çok sık çıkmasın diye kapattım
}

void DosyadanYukle() {
    FILE *ilacDefteri = fopen(DOSYA_ADI, "r");
    if (ilacDefteri == NULL) {
        // Dosya yoksa sorun değil, yeni oluşturulacak
        return;
    }

    toplamIlacSayisi = 0;
    while (fscanf(ilacDefteri, "%s %s %s %d %d %d %f",
            ilaclar[toplamIlacSayisi].barkod,
            ilaclar[toplamIlacSayisi].isim,
            ilaclar[toplamIlacSayisi].skt,
            &ilaclar[toplamIlacSayisi].stok,
            &ilaclar[toplamIlacSayisi].sogukZincir,
            &ilaclar[toplamIlacSayisi].receteli,
            &ilaclar[toplamIlacSayisi].fiyat) != EOF) {
        
        toplamIlacSayisi++;
        if (toplamIlacSayisi >= MAX_ILAC) break;
    }
    fclose(ilacDefteri);
    printf("%d adet ilac kaydi yuklendi.\n", toplamIlacSayisi);
}

void IlacEkle() {
    printf("\n--- YENI ILAC GIRISI ---\n"); 
    if (toplamIlacSayisi >= MAX_ILAC) {
        printf("Hata: Stok Kapasitesi dolu! (Max %d)\n", MAX_ILAC);
        return;
    }

    barkodUret(ilaclar[toplamIlacSayisi].barkod);
    printf("Otomatik Barkod: %s\n", ilaclar[toplamIlacSayisi].barkod);

    printf("Ilac Ismi (Bosluksuz giriniz): ");
    scanf("%s", ilaclar[toplamIlacSayisi].isim);

    printf("Son Kullanma Tarihi (GG.AA.YYYY): ");
    scanf("%s", ilaclar[toplamIlacSayisi].skt);
   
    printf("Stok Adedi: ");
    scanf("%d", &ilaclar[toplamIlacSayisi].stok);
   
    printf("Soguk Zincir mi? (1: Evet, 0: Hayir): ");
    scanf("%d", &ilaclar[toplamIlacSayisi].sogukZincir);

    printf("Receteli mi? (1: Evet, 0: Hayir): ");
    scanf("%d", &ilaclar[toplamIlacSayisi].receteli);

    printf("Birim Fiyati: ");
    scanf("%f", &ilaclar[toplamIlacSayisi].fiyat);

    toplamIlacSayisi++;
    
    DosyayaKaydet();
    printf("Ilac basariyla eklendi!\n");
}

void StokListele() {
    if (toplamIlacSayisi == 0) {
        printf("\nListelenecek ilac bulunamadi.\n");
        return;
    }

    printf("\n%-15s %-15s %-12s %-6s %-8s %-8s %-8s\n", 
           "BARKOD", "ISIM", "SKT", "STOK", "SOGUK", "RECETE", "FIYAT");
    printf("------------------------------------------------------------------------------\n");

    for (int i = 0; i < toplamIlacSayisi; i++) {
        printf("%-15s %-15s %-12s %-6d %-8s %-8s %-8.2f\n",
            ilaclar[i].barkod,
            ilaclar[i].isim,
            ilaclar[i].skt,
            ilaclar[i].stok,
            ilaclar[i].sogukZincir == 1 ? "EVET" : "HAYIR",
            ilaclar[i].receteli == 1 ? "EVET" : "HAYIR",
            ilaclar[i].fiyat
        );
    }
    printf("\n");
}

void Menu() {
    int secim;
    while (1) {
        printf("\n*******************************************************\n");
        printf("ECZANE ILAC TAKIP SISTEMI\n");
        printf("1. Ilac Stoklarini Listele\n");
        printf("2. Yeni Ilac Ekle\n");
        printf("3. Cikis\n");
        printf("Seciminiz: ");
        
        if (scanf("%d", &secim) != 1) {
            printf("Gecersiz giris! Lutfen bir sayi giriniz.\n");
            tamponTemizle();
            continue;
        }

        switch (secim) {
            case 1:
                StokListele();
                break;
            case 2:
                IlacEkle();
                break;
            case 3:
                printf("Cikis yapiliyor...\n");
                return;
            default:
                printf("Hatali secim! Lutfen tekrar deneyiniz.\n");
        }
    }
}

int main() {
    // Windows konsolunda Türkçe karakterleri düzgün göstermek için
    SetConsoleOutputCP(65001); 
    
    // Rastgele sayı üreteci için seed (çekirdek) ayarı
    srand(time(NULL)); 

    DosyadanYukle();
    Menu();
    return 0;
}
