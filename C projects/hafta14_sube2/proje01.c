#include <stdio.h>
#include <windows.h>

float nothesapla(float vize, float final){
    float toplamNot = vize*0.4;
    toplamNot = toplamNot + final*0.6;
    return toplamNot;
}


int main() {
    float vize = 0,final = 0;
    SetConsoleOutputCP(65001);

    printf("Vize nıtunu giriniz : ");
    scanf("%f",&vize);
    printf("Final notunu giriniz : ");
    scanf("%f",&final);
    float not = nothesapla(vize,final);
    printf("%f NOTUNUZ ",not);
    return 0;
}