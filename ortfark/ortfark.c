#include <stdio.h>
#include <stdlib.h>
int comparetor (const void *a, const void *b){
    
}

int main() {
    int girilenAdet = 0 ;
    printf("Lutfen kac tane sayi ile islem yapilcak giriniz");
    scanf("%d",&girilenAdet);
    int sayiList[girilenAdet];

    for (size_t i = 0; i < girilenAdet; i++)
    {
        printf("%d.Sayiyi giriniz : ",i++);
        scanf("%d",&sayiList[i]);
    }

    return 0;
}