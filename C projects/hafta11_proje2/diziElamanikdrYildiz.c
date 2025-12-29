#include <stdio.h>

int main() {
    int sayilar[10] = {19,3,15,7,11,9,13,5,17,1};
    for (int a = 0; a < 10; a++)
    {
        printf("%d.Elaminin degeri %d -->",a+1,sayilar[a]);
        
        for (int i = 0; i < sayilar[a]; i++)
        {
            printf("*");
        } 
        printf("\n");
    }
    return 0;
}