#include <stdio.h>

int main() {
    int yas [] ={0};
    int sayac = 0,durum = 0;
    while (1)
    {
        printf("%d,ogrencinini yasini giriniz \n",sayac+1);
        scanf("%d",&yas[sayac]);
        printf("Devam mi ? (1), Tamam mi (2)? \n");
        scanf("%d",&durum);
        sayac+=1;
        if (durum==2)
        {
            break;
        }
        else if (durum==1)
        {
            continue;
        }
    }

    return 0;
}