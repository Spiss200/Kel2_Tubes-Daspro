#include <stdio.h>
#include <string.h>

#define ROW 5
#define COL 5

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

int seats[10][3][7][ROW][COL];

void tampilSeat(int film, int studio, int tanggal) {
    printf("\=== LAYOUT KURSI ===\n");
    printf("  1  2  3  4  5\n");

    for (int i = 0; I < ROW; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < COL; j++) {
            if (seats[film][studio][tanggal][i][j] == 0) printf("[0]");
            else printf("[X]");
        }
        printf("\n");
    }  
}

void simpanTiket(Ticket t) {
    char filename[150];
    char namaPemesanShort[20];
    char filShort[20];

    strncpy(namaPemesanShort, t.namaPemesan, sizeof(namaPemesanShort) - 1);
    namaPemesanShort[sizeof(namaPemesanShort) - 1] = '\0';

    strncpy(filmShort, t.film, sizeof(filmShort) - 1);
    filmShort[sizeof(filmShort) - 1] = '\0';

    sprintf(filename, "tiket_%s_%s.txt", namaPemesanShort, filmShort);

    for (int i = 0; filenam[i] != '\0'; i++){
        if(filename[i] == '') filename[i] = '_';
            }
FILE *file = fopen(filename, "a");

fprintf(file, "\n=== TIKET BIOSKOP ===\n");
fprintf(file, "Nama Pemesan:%s\n", t.namaPemesan);
fprintf(file, "Film    : %s\n", t.film);
fprintf(file, "Studio    : %s\n", t.studio);
fprintf(file, "Hari/Tanggal : %s\n", t.hariTanggal);
fprintf(file, "Jadwal    : %s\n", t.jadwal);

fprintf(file, "Kursi"    :);
for ( int i = 0; i < t.jumlahKursi; i++){
    fprintf(file, "%s"' t.kursiDipilih[i]
        }
fprintf(file, "\n");

fprintf(file, "Harga per kursi : Rp %d\n", t.harga);
fprintf(file, "Total Harga : RP %d\n", t.totalHarga);
fprintf(file, "------------------------\n");

fclose(file);

printf("\nTiket berhasil disimpan ke '%s'!\n", filename);
}

int main() {
    int pilihanFilm, pilihanStudio, pilihanTanggal, pilihanJadwal;

    Ticket t;

    printf("=== SELAMAT DATANG ===\n");
    printf("Masukkan nama Anda: ");
    scanf(" %[^\n]", t.namaPemesan);

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

    printf("\n=== PILIH JADWAL ===\n");
    printf("1. 12:00\n");
    printf("2. 15:00\n");
    printf("3. 19:00\n");
    printf("4. 21:00\n");

    printf("Pilihan: ");
    scanf("%d", &pilihanJadwal);

    char jadwalFilm[4][20] = {"12:00", "15:00", "19:00", "21:00"};
    strcpy(t.jadwal, jadwalFilm[pilihanJadwal - 1]);

    printf("\nBerapa kursi yang ingin dipesan? ");
    scanf("%d", &t.jumlahKursi);
    
    tampilSeat(pilihanFilm, pilihanStudio, pilihanTanggal);

    for (int i = 0; i < t.jumlahKursi; i++) {
        int row, col;
        char huruf;

        printf("\nPilih Kursi %d (format: A1, B3, dst): ", i+1);

        printf("Baris (A-E): ");
        scanf("%c", &huruf);
        if (huruf >= 'a' &&huruf <= 'e') huruf -= 32;
        row = huruf - 'A';

        printf("Kolom (1-5)");
        scanf("%d", &col);
        col--;

         if (seats[pilihanFilm][pilihanStudio][pilihanTanggal][row][col] == 1) {
            printf("Seat sudah terisi! Pilih kursi lain.\n");
            i--;
            continue;
        }

        seats[pilihanFilm][pilihanStudio][pilihanTanggal][row][col] = 1;

        sprintf(t.kursiDipilih[i], "%c%d", huruf, col+1);
    }

    t.totalHarga = t.harga * t.jumlahKursi;

    simpanTiket(t);

    printf("\n=== PEMESANAN BERHASIL ===\n");
    printf("Nama Pemesan:%s\n", t.namaPemesan);
    printf("Film    :%s\n", t.film);
    printf("Studio    :%s\n", t.studio);
    printf("Tanggal    :%s\n", t.hariTanggal);
    printf("Jadwal    :%s\n", t.jadwal);

    printf("Kursi    :");
    for (int i = 0; i < t.jumlahKursi; i++)
        printf("%s", t.kursiDipilih[i];

    printf("\nHarga per kursi : Rp %d\n", t.harga);
    printf("Total Harga : Rp %d\n", t.totalHarga);

    printf("\nTerima kasih telah memesan tiket!\n");
    
    printf("\nKursi yang dipilih: ");
    for (int i = 0; i < t.jumlahKursi; i++)
        printf("%s ", t.kursiDipilih[i]);

    printf("\nTotal Harga: Rp %d\n", t.totalHarga);

    printf("\nData telah dipilih:\n");
    printf("Nama: %s\n", t.namaPemesan);
    printf("Film: %s\n", t.film);
    printf("Studio: %s\n", t.studio);
    printf("Tanggal: %s\n", t.hariTanggal);
    printf("Jadwal: %s\n", t.jadwal);
    printf("Harga: %d\n", t.harga);


    return 0;
}
    
}
