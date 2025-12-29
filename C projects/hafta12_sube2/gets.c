#include <stdio.h>
// burda neden 50,stdin yaptik ve forda neden isim[i] var
int main() {
    char isim [50];
    printf("Lütfen İsminizi giriniz: ");
    fgets(isim,50,stdin);
    printf("Benim adim %s",isim);
    for (int i = 0; i < isim[i]; i++)
    {
        printf("%c\n",isim[i]);
    }
    return 0;
}