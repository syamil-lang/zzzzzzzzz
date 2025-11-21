#ifndef PESAN_MAKANAN_H
#define PESAN_MAKANAN_H
#include <stdlib.h>
#include <stdio.h>

int pesanMakanan()
{
    int pilih, jumlah, harga = 0, total = 0;
    char lagi;

    do
    {
        printf("\n--- PESAN MAKANAN ---\n");
        printf("1.  Nasi Goreng      - 15000\n");
        printf("2.  Ayam Geprek      - 18000\n");
        printf("3.  Es Teh           - 5000\n");
        printf("4.  Mie Ayam         - 12000\n");
        printf("5.  Ayam Bakar       - 25000\n");
        printf("6.  Sate             - 20000\n");
        printf("7.  Martabak Telor   - 30000\n");
        printf("8.  Jus Alpukat      - 10000\n");

        printf("Pilih menu: ");
        scanf("%d", &pilih);

        switch (pilih)
        {
        case 1:
            harga = 15000;
            break;
        case 2:
            harga = 18000;
            break;
        case 3:
            harga = 5000;
            break;
        case 4:
            harga = 12000;
            break;
        case 5:
            harga = 25000;
            break;
        case 6:
            harga = 20000;
            break;
        case 7:
            harga = 30000;
            break;
        case 8:
            harga = 10000;
            break;
        default:
            printf("Menu tidak ada!\n");
            continue; // balik ke loop
        }

        printf("Jumlah pesanan: ");
        scanf("%d", &jumlah);

        int subtotal = harga * jumlah;
        total += subtotal;

        printf("Subtotal: %d\n", subtotal);

        // Simpan ke file
        FILE *file = fopen("pesanan.txt", "a");
        fprintf(file, "Menu %d x %d = %d\n", pilih, jumlah, subtotal);
        fclose(file);

        printf("Ada lagi? (y/n): ");
        scanf(" %c", &lagi); // spasi penting supaya input aman

    } while (lagi == 'y' || lagi == 'Y');
    system("cls");
    printf("\nTotal semua pesanan: %d\n", total);
    
    return total;
}

#endif
