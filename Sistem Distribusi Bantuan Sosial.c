#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Struktur data untuk menyimpan informasi warga
struct Warga {
    char nama[100];
    char ktp[30];
    int umur;
    int tanggungan;
};

// Array of struct untuk antrian warga
struct Warga daftarWarga[MAX];
int jumlahWarga = 0;

// Fungsi menambahkan warga ke dalam antrian
void tambahWarga() {
    if (jumlahWarga >= MAX) {
        printf("\nAntrian penuh, tidak bisa menambahkan warga baru.\n");
        return;
    }

    printf("\n--- Tambah Warga ---\n");
    printf("Nama: ");
    getchar(); // Membersihkan newline dari input sebelumnya
    fgets(daftarWarga[jumlahWarga].nama, sizeof(daftarWarga[jumlahWarga].nama), stdin);
    daftarWarga[jumlahWarga].nama[strcspn(daftarWarga[jumlahWarga].nama, "\n")] = '\0';

    printf("Nomor KTP: ");
    fgets(daftarWarga[jumlahWarga].ktp, sizeof(daftarWarga[jumlahWarga].ktp), stdin);
    daftarWarga[jumlahWarga].ktp[strcspn(daftarWarga[jumlahWarga].ktp, "\n")] = '\0';

    printf("Umur: ");
    scanf("%d", &daftarWarga[jumlahWarga].umur);

    printf("Jumlah Tanggungan: ");
    scanf("%d", &daftarWarga[jumlahWarga].tanggungan);

    jumlahWarga++;
    printf("\nData berhasil ditambahkan!\n");
}

// Fungsi menampilkan semua warga dalam antrian
void tampilkanAntrian() {
    if (jumlahWarga == 0) {
        printf("\nBelum ada data warga.\n");
        return;
    }

    printf("\n--- Daftar Antrian Warga ---\n");
    for (int i = 0; i < jumlahWarga; i++) {
        printf("%d. Nama: %s | KTP: %s | Umur: %d | Tanggungan: %d\n",
               i + 1,
               daftarWarga[i].nama,
               daftarWarga[i].ktp,
               daftarWarga[i].umur,
               daftarWarga[i].tanggungan);
    }
}

// Fungsi pencarian berdasarkan nama atau KTP
void cariWarga() {
    if (jumlahWarga == 0) {
        printf("\nData masih kosong.\n");
        return;
    }

    char keyword[100];
    printf("\nMasukkan Nama atau Nomor KTP yang dicari: ");
    getchar();
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    int ditemukan = 0;
    for (int i = 0; i < jumlahWarga; i++) {
        if (strstr(daftarWarga[i].nama, keyword) || strstr(daftarWarga[i].ktp, keyword)) {
            printf("\nDitemukan: Nama: %s | KTP: %s | Umur: %d | Tanggungan: %d\n",
                   daftarWarga[i].nama,
                   daftarWarga[i].ktp,
                   daftarWarga[i].umur,
                   daftarWarga[i].tanggungan);
            ditemukan = 1;
        }
    }

    if (!ditemukan) {
        printf("\nData tidak ditemukan.\n");
    }
}

// Fungsi mengurutkan data warga berdasarkan prioritas (umur dan tanggungan)
void urutkanPrioritas() {
    if (jumlahWarga < 2) {
        printf("\nTidak cukup data untuk diurutkan.\n");
        return;
    }

    for (int i = 0; i < jumlahWarga - 1; i++) {
        for (int j = i + 1; j < jumlahWarga; j++) {
            if ((daftarWarga[i].umur < daftarWarga[j].umur) ||
                (daftarWarga[i].umur == daftarWarga[j].umur && daftarWarga[i].tanggungan < daftarWarga[j].tanggungan)) {
                struct Warga temp = daftarWarga[i];
                daftarWarga[i] = daftarWarga[j];
                daftarWarga[j] = temp;
            }
        }
    }

    printf("\nData berhasil diurutkan berdasarkan prioritas.\n");
}

void tampilkanLansia() {
    if (jumlahWarga == 0) {
        printf("\nBelum ada data warga.\n");
        return;
    }

    int ditemukan = 0;

    printf("\n--- Warga dengan Umur Lebih dari 50 Tahun (---\n");
    for (int i = 0; i < jumlahWarga; i++) {
        if (daftarWarga[i].umur >= 50) {
            printf("Nama: %s | KTP: %s | Umur: %d | Tanggungan: %d\n",
                   daftarWarga[i].nama,
                   daftarWarga[i].ktp,
                   daftarWarga[i].umur,
                   daftarWarga[i].tanggungan);
            ditemukan = 1;
        }
    }

    if (!ditemukan) {
        printf("Tidak ada warga yang berusia 17 tahun ke bawah.\n");
    }
}


// Fungsi utama (menu)
int main() {
    int pilihan;

    do {
        printf("\n===== MENU SISTEM DISTRIBUSI BANTUAN SOSIAL =====\n");
        printf("1. Tambah Warga\n");
        printf("2. Tampilkan Antrian\n");
        printf("3. Cari Warga\n");
        printf("4. Urutkan Berdasarkan Prioritas\n");
        printf("5. Tampilkan Umur di Atas 50 tahun\n");
        printf("0. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahWarga();
                break;
            case 2:
                tampilkanAntrian();
                break;
            case 3:
                cariWarga();
                break;
            case 4:
                urutkanPrioritas();
                break;
            case 5:
                tampilkanLansia();
                break;
            case 0:
                printf("\nTerima kasih!\n");
                break;
            default:
                printf("\nPilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 0);

    return 0;
}


//INI MENGGUNAKAN STRUKTUR DATA STRUCT,SORTING UNTUK PRIORITAS DAN ARRAT OF STRUCT
