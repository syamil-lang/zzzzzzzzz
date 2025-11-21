#ifndef RIWAYAT_H
#define RIWAYAT_H

#include <stdio.h>

void lihatRiwayat() {
    char line[200];

    printf("\n=== RIWAYAT PESANAN ===\n");
    FILE *p = fopen("pesanan.txt", "r");
    
    if (!p) printf("Belum ada pesanan.\n");
    else {
        while (fgets(line, sizeof(line), p)) printf("%s", line);
        fclose(p);
    }

    printf("\n=== RIWAYAT BOOKING ===\n");
    FILE *b = fopen("booking.txt", "r");
    if (!b) printf("Belum ada booking.\n");
    else {
        while (fgets(line, sizeof(line), b)) printf("%s", line);
        fclose(b);
    }
}

#endif
