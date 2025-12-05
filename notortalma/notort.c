#include <stdio.h>

int main() {
    int notadet ,nottoplam =0 ;
    printf("Lutfen kac adet not girilcek bildiriniz : ");
    scanf("%d",&notadet);
    int notlist[notadet];
    
    for (int i = 0; i < notadet; i++)
    {
        printf("Lutfen %d.notu giriniz :",i+1);
        scanf("%d",&notlist[i]);
        if (notlist[i]>100 )
        {
            printf("100 den kucuk bir not girmeniz gerekmektedir : ");
            scanf("%d",&notlist[i]);
        }
        else if (notlist[i]<0)
        {
            printf("0 dan buyuk bir not girmeniz gerekmektedir : ");
            scanf("%d",&notlist[i]);
        }
        
        nottoplam = notlist[i]+nottoplam;
    }
    float ort = (float)nottoplam/notadet;
    printf("Ogrencinin %d adet sinavda not ortalmasi sudur: %f", notadet,ort);
    return 0;
}