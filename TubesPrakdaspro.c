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
    char kursiDipilih[30][4];  
    int jumlahKursi;
    int harga;
    int totalHarga;
} Ticket;

int seats[10][3][7][ROW][COL];

void isiDataAwal(){
    memset(seats, 0, sizeof(seats)); 
     // Film 0 - Avengers:Endgame
    seats[0][0][0][0][1] = 1;
    seats[0][0][0][1][2] = 1;
    seats[0][0][0][2][0] = 1;
    seats[0][0][0][2][1] = 1;
    seats[0][0][0][2][2] = 1;
    seats[0][0][0][3][3] = 1;
    seats[0][0][0][4][4] = 1;

    // Film 1 - interstellar
    seats[1][0][0][1][1] = 1;

    // Film 2 - Inside Out 2
    seats[2][0][0][0][0] = 1;
    seats[2][0][0][4][0] = 1;

    // Film 3 - Dune: Part Two
    seats[3][0][0][1][1] = 1;
    seats[3][0][0][1][2] = 1;
    seats[3][0][0][2][1] = 1;
    seats[3][0][0][3][2] = 1;
    seats[3][0][0][3][3] = 1;

    // Film 4 - Zootopia 2
    seats[4][0][0][0][2] = 1;
    seats[4][0][0][1][2] = 1;
    seats[4][0][0][2][2] = 1;
    seats[4][0][0][3][2] = 1;
    seats[4][0][0][4][2] = 1;

    // Film 5 - Inside Out 3
    seats[5][0][0][2][2] = 1;

    // Film 6 - Wicked
    seats[6][0][0][1][0] = 1;
    seats[6][0][0][1][4] = 1;

    // Film 7 - Moana 2
    seats[7][0][0][0][4] = 1;
    seats[7][0][0][4][0] = 1;

    // Film 8 - Gladiator 2
    seats[8][0][0][0][0] = 1;
    seats[8][0][0][1][1] = 1;
    seats[8][0][0][2][2] = 1;
    seats[8][0][0][3][3] = 1;
    seats[8][0][0][4][4] = 1;

    // Film 9 - Sonic 3
    seats[9][0][0][0][1] = 1;
    seats[9][0][0][1][3] = 1;
    seats[9][0][0][2][1] = 1;
}

void tampilSeat(int film, int studio, int tanggal) {
    printf("\n=== LAYOUT KURSI ===\n");
    printf("  1  2  3  4  5\n");

    for (int i = 0; i < ROW; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < COL; j++) {
            if (seats[film][studio][tanggal][i][j] == 0) printf("[O]");
            else printf("[X]");
        }
        printf("\n");
    }  
}

void lihatKursi(int film, int studio, int tanggal){
    printf("\n=== KURSI YANG SUDAH TERISI ===\n");
    tampilSeat(film,studio,tanggal);
}

void simpanTiket(Ticket t) {
    char filename[150];
    char namaPemesanShort[20];
    char filmShort[20];

    strncpy(namaPemesanShort, t.namaPemesan, sizeof(namaPemesanShort) - 1);
    namaPemesanShort[sizeof(namaPemesanShort) - 1] = '\0';

    strncpy(filmShort, t.film, sizeof(filmShort) - 1);
    filmShort[sizeof(filmShort) - 1] = '\0';

   snprintf(filename, sizeof(filename), "tiket_%s_%s.txt", namaPemesanShort, filmShort);
    
    for (int i = 0; filename[i] != '\0'; i++){
        if(filename[i] == ' ') filename[i] = '_';
    }
    
FILE *file = fopen(filename, "a");
if (file == NULL) {                  
    printf("Gagal membuka file!\n");
    return;
}
fprintf(file, "\n=== TIKET BIOSKOP ===\n");
fprintf(file, "Nama Pemesan        : %s\n", t.namaPemesan);
fprintf(file, "Film                : %s\n", t.film);
fprintf(file, "Studio              : %s\n", t.studio);
fprintf(file, "Hari/Tanggal        : %s\n", t.hariTanggal);
fprintf(file, "Jadwal              : %s\n", t.jadwal);
fprintf(file, "Kursi               : ");
for ( int i = 0; i < t.jumlahKursi; i++){
    fprintf(file, "%s ", t.kursiDipilih[i]);
}
fprintf(file, "\n");

fprintf(file, "Harga kursi         : Rp %d\n", t.harga);
fprintf(file, "Total Harga         : RP %d\n", t.totalHarga);
fprintf(file, "------------------------\n");

fclose(file);

printf("\nTiket berhasil disimpan ke '%s'!\n", filename);
}

int main() {
    int pilihanFilm, pilihanStudio, pilihanTanggal, pilihanJadwal;

    Ticket t;
    memset(&t, 0, sizeof(Ticket));
    
    isiDataAwal();

    printf("=== SELAMAT DATANG ===\n");
    printf("Masukkan nama Anda: ");
    scanf(" %[^\n]", t.namaPemesan);

    printf("\n=== PILIH FILM ===\n");
    printf("1. Avengers: Endgame\n");
    printf("2. Interstellar\n");
    printf("3. Inside Out 2\n");
    printf("4. Dune: Part Two\n");
    printf("5. Zootopia 2\n");
    printf("6. Inside Out 3\n");
    printf("7. Wicked\n");
    printf("8. Moana 2\n");
    printf("9. Gladiator 2\n");
    printf("10. Sonic 3\n");

    printf("Pilihan: ");
    while (scanf("%d", &pilihanFilm) !=1 || pilihanFilm < 1 || pilihanFilm > 10){
        printf("Input tidak valid! Masukkan angka 1-10:");
        while(getchar() !='\n');
    }
    pilihanFilm--;

    char daftarFilm[10][50] = {
        "Avengers: Endgame",
        "Interstellar",
        "Inside Out 2",
        "Dune: Part Two",
        "Zootopia 2",
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
    while (scanf("%d", &pilihanStudio) != 1 || pilihanStudio  < 1 || pilihanStudio > 3){
        printf("Input tidak valid! Masukkan angka 1-3:");
        while(getchar() !='\n');
    }
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
    while (scanf("%d", &pilihanTanggal) != 1 || pilihanTanggal < 1 || pilihanTanggal > 7){
        printf("Input tidak valid! Masukkan angka 1-7:");
        while (getchar() != '\n');
    }
    pilihanTanggal--;

    strcpy(t.hariTanggal, tanggal[pilihanTanggal]);

    printf("\n=== PILIH JADWAL ===\n");
    printf("1. 12:00\n");
    printf("2. 15:00\n");
    printf("3. 19:00\n");
    printf("4. 21:00\n");

    char jadwalFilm[4][20] = {"12:00", "15:00", "19:00", "21:00"};

    printf("Pilihan: ");
    while (scanf("%d", &pilihanJadwal) != 1 || pilihanJadwal < 1 || pilihanJadwal > 4){
    printf("Input tidak valid! Masukkan angka 1-4:");
    while (getchar() != '\n');
}
    pilihanJadwal--;               
    strcpy(t.jadwal, jadwalFilm[pilihanJadwal]);

    printf("\nBerapa kursi yang ingin dipesan? ");
    while (scanf("%d", &t.jumlahKursi) != 1 || t.jumlahKursi < 1 || t.jumlahKursi > 25){
        printf("Jumlah kursi harus 1-25. Coba lagi:");
        while (getchar() !='\n');
    }

    int menu;
    while(1){
        printf("\n=== MENU SEBELUM BOOKING ===\n");
        printf("1. Lanjut pilih kursi\n");
        printf("2. Lihat kursi terisi\n");
        printf("Pilihan:");

        while (scanf("%d",&menu) != 1 || menu < 1 || menu > 2){
            printf("Input tidak valid! Pilih 1 atau 2:");
            while (getchar() !='\n');
        }

        if(menu == 1)break;
        else lihatKursi(pilihanFilm, pilihanStudio, pilihanTanggal);
    }
    
    tampilSeat(pilihanFilm, pilihanStudio, pilihanTanggal);

    for (int i = 0; i < t.jumlahKursi; i++) {
        int row, col;
        char huruf;

        printf("\nPilih Kursi %d (format: A1, B3, dst): ", i+1);

        printf("Baris (A-E): ");
        while(scanf(" %c", &huruf) != 1 || !((huruf >= 'A' && huruf <= 'E') || (huruf >= 'a' && huruf <= 'e'))){
            printf("Baris tidak valid! Masukkan A-E:");
            while (getchar() !='\n');
        }
            
        if (huruf >= 'a' &&huruf <= 'e') 
            huruf -= 32;
        row = huruf - 'A';

        printf("Kolom (1-5):");
        while(scanf("%d", &col) != 1 || col < 1 || col > 5){
            printf("Kolom tidak valid! Masukkan 1-5:");
            while (getchar() !='\n');
        }
        col--;

         if (seats[pilihanFilm][pilihanStudio][pilihanTanggal][row][col] == 1) {
            printf("Seat sudah terisi! Pilih kursi lain.\n");
            i--;
            continue;
        }

        seats[pilihanFilm][pilihanStudio][pilihanTanggal][row][col] = 1;

        snprintf(t.kursiDipilih[i], sizeof(t.kursiDipilih[i]),
         "%c%d", huruf, col + 1);

    }

    t.totalHarga = t.harga * t.jumlahKursi;

    simpanTiket(t);

    printf("\n=== PEMESANAN BERHASIL ===\n");
    printf("Nama Pemesan:%s\n", t.namaPemesan);
    printf("Film        :%s\n", t.film);
    printf("Studio      :%s\n", t.studio);
    printf("Tanggal     :%s\n", t.hariTanggal);
    printf("Jadwal      :%s\n", t.jadwal);

    printf("Kursi       :");
    for (int i = 0; i < t.jumlahKursi; i++)
        printf("%s ", t.kursiDipilih[i]);

    printf("\nHarga per kursi : Rp %d\n", t.harga);
    printf("Total Harga       : Rp %d\n", t.totalHarga);

    tampilSeat(pilihanFilm, pilihanStudio, pilihanTanggal);
    
    printf("\nTerima kasih telah memesan tiket!\n");

    return 0;
    
}
