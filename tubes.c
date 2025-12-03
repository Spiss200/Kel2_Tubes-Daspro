Tahap 2:

#include <stdio.h>
#include <string.h>

typedef struct {
    char namaPemesan[50];
    char film[50];
    char studio[20];
    char jadwal[20];
    char hariTanggal[40];
    char kursiDipilih[30][3];  
    int jumlahKursi;
    int harga;
    int totalHarga;
} Ticket;

int main() {
    int pilihanFilm, pilihanStudio, pilihanTanggal, pilihanJadwal;

    Ticket t;

    //  NAMA PEMESAN 
    printf("=== SELAMAT DATANG ===\n");
    printf("Masukkan nama Anda: ");
    scanf(" %[^\n]", t.namaPemesan);

    //  PILIH FILM 
    printf("\n=== PILIH FILM ===\n");
    printf("1. Avengers: Endgame\n");
    printf("2. Interstellar\n");
    printf("3. Inside Out 2\n");
    printf("4. Dune: Part Two\n");
    printf("5. Joker: Folie à Deux\n");
    printf("6. Inside Out 3\n");
    printf("7. Wicked\n");
    printf("8. Moana 2\n");
    printf("9. Gladiator 2\n");
    printf("10. Sonic 3\n");

    printf("Pilihan: ");
    scanf("%d", &pilihanFilm);
    pilihanFilm--;

    char daftarFilm[10][50] = {
        "Avengers: Endgame",
        "Interstellar",
        "Inside Out 2",
        "Dune: Part Two",
        "Joker: Folie à Deux",
        "Inside Out 3",
        "Wicked",
        "Moana 2",
        "Gladiator 2",
        "Sonic 3"
    };
    strcpy(t.film, daftarFilm[pilihanFilm]);

    // PILIH STUDIO 
    printf("\n=== PILIH STUDIO ===\n");
    printf("1. Reguler (35000)\n");
    printf("2. Dolby Atmos (50000)\n");
    printf("3. IMAX (70000)\n");

    printf("Pilihan: ");
    scanf("%d", &pilihanStudio);
    pilihanStudio--;

    char namaStudio[3][20] = {"Reguler", "Dolby Atmos", "IMAX"};
    int hargaStudio[3] = {35000, 50000, 70000};

    strcpy(t.studio, namaStudio[pilihanStudio]);
    t.harga = hargaStudio[pilihanStudio];

    //  PILIH HARI & TANGGAL 
    char tanggal[7][40] = {
        "Senin, 1 Des 2025",
        "Selasa, 2 Des 2025",
        "Rabu, 3 Des 2025",
        "Kamis, 4 Des 2025",
        "Jumat, 5 Des 2025",
        "Sabtu, 6 Des 2025",
        "Minggu, 7 Des 2025"
    };

    printf("\n=== PILIH TANGGAL ===\n");
    for (int i = 0; i < 7; i++)
        printf("%d. %s\n", i+1, tanggal[i]);

    printf("Pilihan: ");
    scanf("%d", &pilihanTanggal);
    pilihanTanggal--;

    strcpy(t.hariTanggal, tanggal[pilihanTanggal]);

    // PILIH JADWAL
    printf("\n=== PILIH JADWAL ===\n");
    printf("1. 12:00\n");
    printf("2. 15:00\n");
    printf("3. 19:00\n");
    printf("4. 21:00\n");

    printf("Pilihan: ");
    scanf("%d", &pilihanJadwal);

    char jadwalFilm[4][20] = {"12:00", "15:00", "19:00", "21:00"};
    strcpy(t.jadwal, jadwalFilm[pilihanJadwal - 1]);

    printf("\nData telah dipilih:\n");
    printf("Nama: %s\n", t.namaPemesan);
    printf("Film: %s\n", t.film);
    printf("Studio: %s\n", t.studio);
    printf("Tanggal: %s\n", t.hariTanggal);
    printf("Jadwal: %s\n", t.jadwal);
    printf("Harga: %d\n", t.harga);

    return 0;
}