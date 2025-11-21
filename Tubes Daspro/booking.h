int bookingMeja()
{
    char nama[50], tanggal[20];
    int orang, meja;
    int totalMakanan = 0;

    printf("\n--- BOOKING MEJA ---\n");
    printf("Nama: ");
    scanf(" %s", nama);

    printf("Tanggal (dd/mm/yyyy): ");
    scanf(" %s", tanggal);

    printf("Jumlah orang: ");
    scanf(" %d", &orang);

    printf("Nomor meja: ");
    scanf(" %d", &meja);

    printf("\nApakah ingin sekalian pesan makanan? (y/n): ");
    char pilih;
    scanf(" %c", &pilih);

    if (pilih == 'y' || pilih == 'Y')
        totalMakanan = pesanMakanan();

    FILE *file = fopen("booking.txt", "a");
    fprintf(file,
            "Booking: %s - %s - %d org - Meja %d - Total Makanan: Rp %d\n",
            nama, tanggal, orang, meja, totalMakanan);
    fclose(file);

    printf("\nBooking disimpan dengan total makanan Rp %d\n", totalMakanan);

    return totalMakanan; 
}
