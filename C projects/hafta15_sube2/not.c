#include <stdio.h>
#include <windows.h>

void harfNotuHesapla(){

    FILE * fp;
    int vize, final,dogrulama = 1;
    char harfNotu;
    
    do
    {
        fp = fopen("Projem.txt","a");
        printf("Vize notunu giriniz: ");
        scanf("%d", &vize);
        printf("Final notunu giriniz: ");
        scanf("%d", &final);
        float sonNot = vize*0.4 + final*0.6;


        if (sonNot >= 70)
        {
            harfNotu = 'A';
            fprintf(fp,"%f",sonNot);
            fprintf(fp,"%c \n",harfNotu);
            printf("Başka bir nıt girmek istiyormusunuz? istiyorsannız 1 e basınız istemiyorsanız 0: ");
            scanf("%d",&dogrulama);
            if (dogrulama == 1)
            {
                continue;
            }else
            {
                fclose(fp);
                break;
            }
            
 

        }else
        {
            harfNotu = 'F';
            fprintf(fp,"%f",sonNot);
            fprintf(fp,"%c \n",harfNotu);
            printf("Başka bir nıt girmek istiyormusunuz? istiyorsannız 1 e basınız istemiyorsanız 0: ");
            scanf("%d",&dogrulama);
            if (dogrulama == 1)
            {
                continue;
            }
            else
            {
                fclose(fp);
                break;
            }
            
        }
    } while (dogrulama == 1);
}

int main() {
    //projem.txt dosyaını sınavdan aldığı
    //harf noyu yazdıran kodu c dilinde yazınız
    //vize ve final girilcek.70den büyükse a küçkse f yazılcak not hesabı paramaterr olan bir fonksiyon yazıılcal.
    SetConsoleOutputCP(65001);
    harfNotuHesapla();
    return 0;
}