#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);

    FILE *dosya;
    char metin[50];
    int i = 0;
    strcpy(metin, "Merhaba Dünya!\n");
    dosya = fopen("output.txt", "a");

    for (int i = 0; i < strlen(metin); i++)
    {
        putc(metin[i], dosya);
    }
    putc('\n',dosya);
    fclose(dosya);

    int c = 0;
    dosya = fopen("output.txt", "r");
    if (dosya!= NULL)
    {
        do
        {
            c = getc(dosya);
            putchar(c);
        } while (c!=EOF);
        
        fclose(dosya);
        return 0;
    }
    

    return 0;
}