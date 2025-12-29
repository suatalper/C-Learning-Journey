#include <stdio.h>
#include <windows.h> 
/*
1-Giriş Yap
2-Üye ol
3-Rezervasyon yap
4-Çıkış Yap

Bir fonksiyonda olucak. Fonksiyonun içi boş olucak.
*/
void girisyap(){

}
void uyeOl(){

}
void rezervasyonYap(){

}
void cikisYap(){

}
void hataMsg(){

}

void menu(){
    printf("******************************************************\n");
    printf("Restoranımız HOŞ GELDİNİZ \nGiriş yapmak için (1)\nÜye olmak için (2)\nRezevasyon yapmak için (3)\nÇıkış için (4)\n");
    printf("******************************************************");

    int durum = 0;
    scanf("%d",&durum);
    if (durum==1)
    {
        girisyap();
    }else if (durum == 2)
    {
        uyeOl();
    }else if (durum == 3)
    {
        rezervasyonYap();
    }else if (durum==4)
    {
        cikisYap();
    }
    else
    {
        hataMsg();
    }
}
int main() {
    SetConsoleOutputCP(65001);
    menu();
    return 0;
}