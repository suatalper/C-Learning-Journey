#include <stdio.h>

int main() {
    int ornekdizi[5];
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        ornekdizi[i] = i*3;
    }
    for ( i = 0; i < 5; i++)
    {
        printf("%d.dizi elemainin degeri %d \n",i,ornekdizi[i]);
    }
    
    
    return 0;
}