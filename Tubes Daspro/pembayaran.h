#ifndef PEMBAYARAN_H
#define PEMBAYARAN_H

#include <stdio.h>

void pembayaran(int totalPesanan, int totalBooking, int panjar)
{
    int pilih, uang;

    printf("\n=== PEMBAYARAN ===\n");
    printf("1. Bayar Pesanan\n");
    printf("2. Bayar Booking\n");
    printf("Pilih: ");
    scanf("%d", &pilih);

    // ============================================
    // 1. PEMBAYARAN PESANAN
    // ============================================
    if (pilih == 1)
    {
        if (totalPesanan <= 0)
        {
            printf("Belum ada pesanan! Tidak bisa bayar.\n");
            return;
        }

        printf("\nTotal yang harus dibayar: Rp %d\n", totalPesanan);
        printf("\nPilih metode:\n");
        printf("1. Cash\n");
        printf("2. BRI\n");
        printf("3. Mandiri\n");
        printf("4. BNI\n");
        printf("Metode: ");

        int m;
        scanf("%d", &m);

        uang = 0;

        // ===== METODE CASH =====
        if (m == 1)
        {
            printf("Masukkan uang cash: Rp ");
            scanf("%d", &uang);

            while (uang < totalPesanan)
            {
                printf("Uang kurang! Masukkan lagi: Rp ");
                scanf("%d", &uang);
            }

            printf("Kembalian Anda: Rp %d\n", uang - totalPesanan);
            printf("Pembayaran cash berhasil!\n");
        }
        // ===== METODE TRANSFER =====
        else if (m >= 2 && m <= 4)
        {
            if (m == 2)
                printf("No Rek BRI: 1234-5678-1111\n");
            if (m == 3)
                printf("No Rek Mandiri: 3245-6575-4325\n");
            if (m == 4)
                printf("No Rek BNI: 9876-5432-1098\n");

            printf("Masukkan jumlah transfer: Rp ");
            scanf("%d", &uang);

            while (uang < totalPesanan)
            {
                printf("Transfer kurang! Masukkan lagi: Rp ");
                scanf("%d", &uang);
            }

            if (uang > totalPesanan)
                printf("Kembalian otomatis dikirim: Rp %d\n", uang - totalPesanan);

            printf("Pembayaran berhasil!\n");
        }
        else
        {
            printf("Metode tidak valid!\n");
            return;
        }

        // Simpan riwayat
        FILE *file = fopen("riwayat.txt", "a");
        fprintf(file, "Pembayaran Pesanan: Rp %d\n", totalPesanan);
        fclose(file);

        printf("Riwayat pembayaran pesanan disimpan.\n");
    }

    // ============================================
    // 2. PEMBAYARAN BOOKING
    // ============================================
    else if (pilih == 2)
    {
        if (panjar < 50000)
        {
            printf("\nPanjar minimal Rp 50.000! Anda baru bayar Rp %d\n", panjar);
            return;
        }

        int sisaBayar = totalBooking - panjar;

        printf("\nTotal Booking       : Rp %d\n", totalBooking);
        printf("Panjar yang dibayar : Rp %d\n", panjar);
        printf("Sisa harus dibayar  : Rp %d\n", sisaBayar);

        if (sisaBayar <= 0)
        {
            printf("Booking sudah lunas!\n");
            return;
        }

        printf("\nPilih metode:\n");
        printf("1. Cash\n");
        printf("2. BRI\n");
        printf("3. Mandiri\n");
        printf("4. BNI\n");
        printf("Metode: ");

        int mp;
        scanf("%d", &mp);

        uang = 0;

        if (mp == 2)
            printf("No Rek BRI: 1234-5678-1111\n");
        if (mp == 3)
            printf("No Rek Mandiri: 3245-6575-4325\n");
        if (mp == 4)
            printf("No Rek BNI: 9876-5432-1098\n");

        printf("Masukkan jumlah pembayaran: Rp ");
        scanf("%d", &uang);

        while (uang < sisaBayar)
        {
            printf("Uang kurang! Masukkan lagi: Rp ");
            scanf("%d", &uang);
        }

        printf("Kembalian: Rp %d\n", uang - sisaBayar);
        printf("Pembayaran booking berhasil!\n");  

        FILE *file = fopen("booking.txt", "a");
        fprintf(file, "Pelunasan Booking: Sisa %d dibayar. Panjar %d\n", sisaBayar, panjar);
        fclose(file);

        printf("Riwayat pelunasan booking disimpan.\n");
    }

    else
    {
        printf("Pilihan tidak valid!\n");
    }
}

#endif
 