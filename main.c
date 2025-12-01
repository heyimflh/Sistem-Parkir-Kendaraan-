#include <stdio.h>

int main() {
    int pilihan = 0;
    char *jenis;
    int biaya_per_jam;

    int masuk_jam, masuk_menit;
    int keluar_jam, keluar_menit;
    int total_menit, durasi_jam, durasi_menit;
    int waktu_bulat, biaya;

    // =======================
    // Validasi pilihan kendaraan
    // =======================
    while (1) {
        printf("=== SISTEM PARKIR KENDARAAN ===\n");
        printf("1. Motor\n");
        printf("2. Mobil\n");
        printf("3. Bus\n");
        printf("Pilih jenis kendaraan (1-3): ");

        if (scanf("%d", &pilihan) != 1) {
            printf("\nInput harus berupa angka!\n\n");
            while (getchar() != '\n'); // membersihkan input
            continue;
        }

        if (pilihan == 1) {
            jenis = "Motor";
            biaya_per_jam = 2000;
            break;
        } else if (pilihan == 2) {
            jenis = "Mobil";
            biaya_per_jam = 5000;
            break;
        } else if (pilihan == 3) {
            jenis = "Bus";
            biaya_per_jam = 20000;
            break;
        } else {
            printf("\nPilihan tidak valid! Harus 1-3.\n\n");
        }
    }

    // =======================
    // Validasi waktu masuk
    // =======================
    while (1) {
        printf("\nWaktu masuk kendaraan (HH:MM) : ");
        
        if (scanf("%d:%d", &masuk_jam, &masuk_menit) != 2) {
            printf("Format salah! Gunakan format HH:MM\n");
            while (getchar() != '\n');
            continue;
        }

        if (masuk_jam < 0 || masuk_jam > 23 || masuk_menit < 0 || masuk_menit > 59) {
            printf("Jam atau menit tidak valid!\n");
        } else {
            break;
        }
    }

    // =======================
    // Validasi waktu keluar
    // =======================
    while (1) {
        printf("Waktu keluar kendaraan (HH:MM): ");
        
        if (scanf("%d:%d", &keluar_jam, &keluar_menit) != 2) {
            printf("Format salah! Gunakan format HH:MM\n");
            while (getchar() != '\n');
            continue;
        }

        if (keluar_jam < 0 || keluar_jam > 23 || keluar_menit < 0 || keluar_menit > 59) {
            printf("Jam atau menit tidak valid!\n");
        } else {
            break;
        }
    }

    // =======================
    // Hitung durasi termasuk lewat tengah malam
    // =======================
    int masuk_total = masuk_jam * 60 + masuk_menit;
    int keluar_total = keluar_jam * 60 + keluar_menit;

    if (keluar_total < masuk_total) {
        // lewat tengah malam
        keluar_total += 24 * 60;
    }

    total_menit = keluar_total - masuk_total;
    durasi_jam = total_menit / 60;
    durasi_menit = total_menit % 60;

    // Pembulatan
    if (durasi_menit > 0)
        waktu_bulat = durasi_jam + 1;
    else
        waktu_bulat = durasi_jam;

    biaya = waktu_bulat * biaya_per_jam;

    // =======================
    // Output
    // =======================
    printf("\n============== TIKET PARKIR ==============\n");
    printf("Jenis kendaraan         : %s\n", jenis);
    printf("Waktu masuk kendaraan   : %02d:%02d\n", masuk_jam, masuk_menit);
    printf("Waktu keluar kendaraan  : %02d:%02d\n", keluar_jam, keluar_menit);
    printf("Durasi parkir           : %d jam %d menit\n", durasi_jam, durasi_menit);
    printf("Dibulatkan              : %d jam\n", waktu_bulat);
    printf("Total biaya             : Rp %d\n", biaya);
    printf("==========================================\n");

    return 0;
}
