#include <stdio.h>
#include <windows.h>

void yasHesapla(){
    int bugunyil = 0,dogumtarihi = 0;
    printf("Bügünün tarhini giriniz : ");
    scanf("%d",&bugunyil);
    printf("Dogum yılını giriniz : ");
    scanf("%d",&dogumtarihi);
    int sonuc = bugunyil - dogumtarihi;
    printf("yasiniz : %d",sonuc);
}

int main() {
    SetConsoleOutputCP(65001);
    yasHesapla();
    return 0;
}