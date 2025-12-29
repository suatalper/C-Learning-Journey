#include <stdio.h>
#include <string.h>

int main() {
    int i =  0 ;
    char isim [50];
    printf("Lütfen İsminizi giriniz: ");
    fgets(isim,50,stdin);

    int uzunluk = strlen(isim);
    for ( i = 0; i < uzunluk; i++)
    {
        printf("%c \n",isim[i]);
    }
    char soyisim [50];
    printf("Soy isim giriniz : ");
    fgets(soyisim,50,stdin);
    strcat(isim,soyisim);
    printf("Birlesen isim %s",isim);
    char bosluk[1];
    strcpy(bosluk,"");
    strcat(isim,bosluk);

    return 0;
}