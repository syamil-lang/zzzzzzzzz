#include <stdio.h>

int main() {
  FILE *file = fopen("file.txt", "w");
  if (file == NULL) {
    printf("Gagal membuka file.\n");
    return 1;
  } else {
    int umur = 10;
    float tinggi = 1.75;
    fprintf(file, "Umur: %d tahun\n", umur);
    fprintf(file, "Tinggi: %.2f meter\n", tinggi);

    printf("File berhasil diakses");
    fclose(file);
  }

  return 0;
}