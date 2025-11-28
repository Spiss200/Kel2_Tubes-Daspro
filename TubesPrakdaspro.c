#include <stdio.h>
#include <string.h>

typedef struct {
    char namaPemesan[50];
    char film[50];
    char studio[20];
    char jadwal[20];
    char hariTanggal[40];
    char kursiDipilih[30][3];  // contoh "A1"
    int jumlahKursi;
    int harga;
    int totalHarga;
} Ticket;

int main() {
    int pilihanFilm, pilihanStudio, pilihanTanggal, pilihanJadwal;
    ticket t;

    printf("=== Selamat Datang ===\n");
    printf("Nama Pemesan: ");
    scanf(" %[^\n]", t.namaPemesan);
}