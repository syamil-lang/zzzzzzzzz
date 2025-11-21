#include <stdio.h>
int main()
{
    char YesNo;
    printf("Masukkan Karakter Y atau N\n");
    scanf("%c", &YesNo);
    if ((YesNo == 'Y') || (YesNo == 'y'))
        printf("Silahkan Lanjutkan");
    else if ((YesNo == 'N') || (YesNo == 'n'))
        printf("Silahkan Keluar");
    else
        printf("Bukan jawaban yang diinginkan");
    printf("\n\n");
    return 0;
}