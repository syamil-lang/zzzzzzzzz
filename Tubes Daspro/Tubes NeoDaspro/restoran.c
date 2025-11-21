#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>  // Untuk tanggal/waktu struk

// Struktur untuk item menu
typedef struct {
    char nama[50];
    float harga;
} MenuItem;

// Struktur untuk pesanan
typedef struct {
    MenuItem items[10]; // Maksimal 10 item per pesanan
    int jumlahItem;
    float total;
    int status; // 0: aktif, 1: dibatalkan, 2: dibayar
} Pesanan;

// Struktur untuk booking
typedef struct {
    char nama[50];
    char tanggal[20];
    char waktu[10];
    int jumlahOrang;
    int panjar;
    int status; // 0: aktif, 1: dibatalkan
} Booking;

// Array untuk menyimpan riwayat
Pesanan riwayatPesanan[100];
Booking riwayatBooking[100];
int countRiwayatPesanan = 0;
int countRiwayatBooking = 0;

// Menu makanan
MenuItem menu[] = {
    {"Nasi Goreng", 15000},
    {"Ayam Geprek", 18000},
    {"Es Teh", 5000},
    {"Mie Ayam", 12000},
    {"Ayam Bakar", 25000},
    {"Sate", 20000},
    {"Martabak Telor", 30000},
    {"Jus Alpukat", 10000}
};
int jumlahMenu = 8;

// Variabel global sesuai kode Anda
int totalPesanan = 0;
int totalBooking = 0;
int panjar = 0;

// Prototipe fungsi (untuk menghindari implicit declaration)
void cetakStruk(char *jenis, int total, int metode, int uangDibayar);

// Fungsi untuk pesan makanan (mengembalikan total pesanan)
int pesanMakanan() {
    Pesanan pesananBaru;
    pesananBaru.jumlahItem = 0;
    pesananBaru.total = 0;
    pesananBaru.status = 0;
    
    int pilihan;
    do {
        printf("\n--- PESAN MAKANAN ---\n");
        printf("1.  Nasi Goreng      - 15000\n");
        printf("2.  Ayam Geprek      - 18000\n");
        printf("3.  Es Teh           - 5000\n");
        printf("4.  Mie Ayam         - 12000\n");
        printf("5.  Ayam Bakar       - 25000\n");
        printf("6.  Sate             - 20000\n");
        printf("7.  Martabak Telor   - 30000\n");
        printf("8.  Jus Alpukat      - 10000\n");
        printf("0. Selesai Pesan\n");
        printf("Pilih item: ");
        scanf("%d", &pilihan);
        
        if (pilihan >= 1 && pilihan <= jumlahMenu) {
            pesananBaru.items[pesananBaru.jumlahItem] = menu[pilihan-1];
            pesananBaru.total += menu[pilihan-1].harga;
            pesananBaru.jumlahItem++;
            printf("Ditambahkan: %s\n", menu[pilihan-1].nama);
        } else if (pilihan != 0) {
            printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 0);
    
    printf("Pesanan dibuat. Total: Rp %.2f\n", pesananBaru.total);
    return (int)pesananBaru.total;  // Kembalikan total sebagai int
}

// Fungsi untuk batal pesanan
void batalPesanan(int *totalPesanan) {
    if (*totalPesanan <= 0) {
        printf("Tidak ada pesanan aktif untuk dibatalkan.\n");
        return;
    }
    
    *totalPesanan = 0;
    printf("Pesanan dibatalkan.\n");
}

// Fungsi untuk booking meja (mengembalikan total booking tetap Rp 50.000)
int bookingMeja() {
    Booking bookingBaru;
    printf("Masukkan nama: ");
    scanf("%s", bookingBaru.nama);
    printf("Masukkan tanggal (DD/MM/YYYY): ");
    scanf("%s", bookingBaru.tanggal);
    printf("Masukkan waktu (HH:MM): ");
    scanf("%s", bookingBaru.waktu);
    printf("Masukkan jumlah orang: ");
    scanf("%d", &bookingBaru.jumlahOrang);
    printf("Masukkan panjar (minimal Rp 50.000): Rp ");
    scanf("%d", &bookingBaru.panjar);
    
    while (bookingBaru.panjar < 50000) {
        printf("Panjar kurang! Masukkan lagi (minimal Rp 50.000): Rp ");
        scanf("%d", &bookingBaru.panjar);
    }
    
    panjar = bookingBaru.panjar;  // Update global panjar
    int total = 50000;  // Biaya booking tetap Rp 50.000
    printf("Booking berhasil untuk %s pada %s %s. Total: Rp %d, Panjar: Rp %d\n", bookingBaru.nama, bookingBaru.tanggal, bookingBaru.waktu, total, panjar);
    return total;
}

// Fungsi pembayaran (dengan struk)
void pembayaran(int totalPesanan, int totalBooking, int panjar) {
    int pilih, uang;

    printf("\n=== PEMBAYARAN ===\n");
    printf("1. Bayar Pesanan\n");
    printf("2. Bayar Booking\n");
    printf("Pilih: ");
    scanf("%d", &pilih);

    // ============================================
    // 1. PEMBAYARAN PESANAN
    // ============================================
    if (pilih == 1) {
        if (totalPesanan <= 0) {
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
        if (m == 1) {
            printf("Masukkan uang cash: Rp ");
            scanf("%d", &uang);

            while (uang < totalPesanan) {
                printf("Uang kurang! Masukkan lagi: Rp ");
                scanf("%d", &uang);
            }

            printf("Kembalian Anda: Rp %d\n", uang - totalPesanan);
            printf("Pembayaran cash berhasil!\n");
        }
        // ===== METODE TRANSFER =====
        else if (m >= 2 && m <= 4) {
            if (m == 2)
                printf("No Rek BRI: 1234-5678-1111\n");
            if (m == 3)
                printf("No Rek Mandiri: 3245-6575-4325\n");
            if (m == 4)
                printf("No Rek BNI: 9876-5432-1098\n");

            printf("Masukkan jumlah transfer: Rp ");
            scanf("%d", &uang);

            while (uang < totalPesanan) {
                printf("Transfer kurang! Masukkan lagi: Rp ");
                scanf("%d", &uang);
            }

            if (uang > totalPesanan)
                printf("Kembalian otomatis dikirim: Rp %d\n", uang - totalPesanan);

            printf("Pembayaran berhasil!\n");
        }
        else {
            printf("Metode tidak valid!\n");
            return;
        }

        // Cetak struk
        cetakStruk("Pesanan", totalPesanan, m, uang);

        // Simpan riwayat
        FILE *file = fopen("riwayat.txt", "a");
        fprintf(file, "Pembayaran Pesanan: Rp %d\n", totalPesanan);
        fclose(file);

        printf("Riwayat pembayaran pesanan disimpan.\n");
    }

    // ============================================
    // 2. PEMBAYARAN BOOKING
    // ============================================
    else if (pilih == 2) {
        if (panjar < 50000) {
            printf("\nPanjar minimal Rp 50.000! Anda baru bayar Rp %d\n", panjar);
            return;
        }

        int sisaBayar = totalBooking - panjar;

        printf("\nTotal Booking       : Rp %d\n", totalBooking);
        printf("Panjar yang dibayar : Rp %d\n", panjar);
        printf("Sisa harus dibayar  : Rp %d\n", sisaBayar);

        if (sisaBayar <= 0) {
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

        while (uang < sisaBayar) {
            printf("Uang kurang! Masukkan lagi: Rp ");
            scanf("%d", &uang);
        }

        printf("Kembalian: Rp %d\n", uang - sisaBayar);
        printf("Pembayaran booking berhasil!\n");  

        // Cetak struk
        cetakStruk("Booking", sisaBayar, mp, uang);

        FILE *file = fopen("booking.txt", "a");
        fprintf(file, "Pelunasan Booking: Sisa %d dibayar. Panjar %d\n", sisaBayar, panjar);
        fclose(file);

        printf("Riwayat pelunasan booking disimpan.\n");
    }

    else {
        printf("Pilihan tidak valid!\n");
    }
}

// Fungsi untuk cetak struk
void cetakStruk(char *jenis, int total, int metode, int uangDibayar) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    printf("\n=====================================\n");
    printf("            STRUK PEMBAYARAN\n");
    printf("=====================================\n");
    printf("Restoran: RESTORAN 9Nine\n");
    printf("Alamat: JL.merdeka simpang3 usu\n");
    printf("Tanggal: %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    printf("Waktu: %02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("Jenis: %s\n", jenis);
    printf("Total: Rp %d\n", total);
    printf("Metode: %s\n", metode == 1 ? "Cash" : (metode == 2 ? "BRI" : (metode == 3 ? "Mandiri" : "BNI")));
    printf("Dibayar: Rp %d\n", uangDibayar);
    printf("Kembalian: Rp %d\n", uangDibayar - total);
    printf("=====================================\n");
    printf("Terima kasih atas kunjungannya!\n");
    printf("=====================================\n");
    
    // Simpan ke file
    FILE *file = fopen("struk.txt", "a");
    fprintf(file, "=====================================\n");
    fprintf(file, "            STRUK PEMBAYARAN\n");
    fprintf(file, "=====================================\n");
    fprintf(file, "Restoran: RESTORAN 9Nine\n");
    fprintf(file, "Alamat: JL.merdeka simpang3 usu\n");
    fprintf(file, "Tanggal: %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    fprintf(file, "Waktu: %02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
    fprintf(file, "Jenis: %s\n", jenis);
    fprintf(file, "Total: Rp %d\n", total);
    fprintf(file, "Metode: %s\n", metode == 1 ? "Cash" : (metode == 2 ? "BRI" : (metode == 3 ? "Mandiri" : "BNI")));
    fprintf(file, "Dibayar: Rp %d\n", uangDibayar);
    fprintf(file, "Kembalian: Rp %d\n", uangDibayar - total);
    fprintf(file, "=====================================\n\n");
    fclose(file);
}

// Fungsi untuk lihat riwayat
void lihatRiwayat() {
    printf("\n=== Riwayat Pesanan ===\n");
    FILE *file = fopen("riwayat.txt", "r");
    if (file) {
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
        fclose(file);
    } else {
        printf("Tidak ada riwayat pesanan.\n");
    }
    
    printf("\n=== Riwayat Booking ===\n");
    file = fopen("booking.txt", "r");
    if (file) {
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
        fclose(file);
    } else {
        printf("Tidak ada riwayat booking.\n");
    }
}

int main() {
    int pilih;

    do {
        printf("=====================================\n");
        printf("welcome to RESTORAN 9Nine\n");
        printf("Alamat : JL.merdeka simpang3 usu\n");
        printf("=====================================\n");

        printf("1. Pesan Makanan\n");
        printf("2. Batal Pesanan\n");
        printf("3. Booking Meja\n");
        printf("4. Pembayaran\n");
        printf("5. Lihat Riwayat\n");
        printf("6. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);
        
        switch (pilih) {
        case 1:
            totalPesanan += pesanMakanan();
            break;
        case 2:
            batalPesanan(&totalPesanan);
            break;
        case 3:
            totalBooking = bookingMeja();
            break;
        case 4:
            pembayaran(totalPesanan, totalBooking, panjar);
            break;
        case 5:
            lihatRiwayat();
            break;
        case 6:
            printf("==================================\n");
            printf("Terima kasih sudah berkunjung!\n");
            printf("==================================\n");
            break;
        default:
            printf("Pilihan tidak valid.\n");
        }
    } while (pilih != 6);

    return 0;
}
