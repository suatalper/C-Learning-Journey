#include <stdio.h>
//bu uygulamayı çaılışr bir hale getir ve fgets ve getse bak strlen strcat strcopy 
int main() {
    int toplam = 0, i = 0,j = 0 , ogrenciSay = 0,dersSay = 0;
    float ortolama = 0 ;
    printf("Ogrenci sayisini giriniz : ");
    scanf("%d",&ogrenciSay);
    printf("Ders sayisinizi giriniz : ");
    scanf("%d",&dersSay);

    int dersnotu [ogrenciSay][dersSay];

    for ( i = 0; i < ogrenciSay; i++)
    {
        for ( j = 0; j < dersSay; j++)
        {
            printf("%d.ders notunu giriniz \n",j+1);
            scanf("%d",&dersnotu[i][j]);
            toplam += dersnotu[i][j];
        }
        ortolama = toplam/4;
        toplam = 0;
        printf("%d. ogrencinin %d dersten ortalmasi %f dir.",i+1,dersSay,ortolama);
    }
    return 0;
}