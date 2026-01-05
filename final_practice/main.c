#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);
    
    FILE * fp;
    char urun [50];
    float fiyat = 0;
    int secim ;

    printf("Satış Takip Sistemine Hoş Geldiniz \n");
    printf("Satış girmek için 1'e basınız\n");
    printf("Satışları Görüntülemek için 2'basınız\n");
    printf("Çıkış için 3' basın : ");
    scanf("%d",&secim);

    getchar();

    if (secim == 1)
    {
        printf("Urun ismini girimiz :");

        fgets(urun,sizeof(urun),stdin);

        printf("Ürünün fiyatını giriniz : ");
        scanf("%f",&fiyat);

        fp = fopen("defter.txt","a");
        if (fp != NULL)
        {
          fprintf(fp,"Ürün ismi : %s Ürün fiyatı : %f",urun,fiyat );   
        }

        fclose(fp);
        
    }
    else if (secim == 2)    
    {
        FILE *fp ;
        fp = fopen("defter.txt","r");
        char urunbilgisi [256];
        if (fp != NULL)
        {
                while (fgets(urunbilgisi,sizeof(urunbilgisi),fp) != NULL)
                {
                    printf("%s \n",urunbilgisi);
                }

        }
        
    }
    else if (secim == 3)
    {
        exit(0);
    }
    return 0;
}