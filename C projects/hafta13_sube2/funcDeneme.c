#include <stdio.h>
#include <windows.h> 

int topla(int x,int y){
    int sonuc = x+y;
    return sonuc;
}

int main() {

    SetConsoleOutputCP(65001);

    int toplamasonucu ;
    int x,y;
    printf("Toplamak istediğiniz ilk değeri giriniz : ");
    scanf("%d",&x);
    printf("Toplamak istediğiniz ikinci değeri giriniz : ");
    scanf("%d",&y);

    toplamasonucu = topla(x,y);
    printf("Toplama işleminin sonucu : %d",toplamasonucu);
    return 0;
}