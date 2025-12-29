#include <stdio.h>

int main() {
    int ogrencisayisi = 0;
    float yasToplam = 0;
    printf("Sinifte kac tane ogrneci var ? \n");
    scanf("%d",&ogrencisayisi);
    int ogrenc_yas[ogrencisayisi];

    for ( int i = 0; i < ogrencisayisi; i++)
    {
        printf("%d.Ogrencicninin yasini giriniz : ",i+1);
        scanf("%d",&ogrenc_yas[i]);
        yasToplam = yasToplam +ogrenc_yas[i];
    }

    float yasOrt = yasToplam/ogrencisayisi;
    printf("%d tane ogrencinin yas ortalmasi sudur : %f",ogrencisayisi,yasOrt);

    return 0;
}