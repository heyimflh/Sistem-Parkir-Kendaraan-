## Identitas Kelompok

**Kelompok 4**

Anggota:

1. Muhammad Fakhri Abdullah
2. Alldita Putri Amelia
3. Nabila Salma Az Zahra

---

## Pendahuluan Singkat

Program ini merupakan **program konsol sederhana** yang mensimulasikan cara kerja **mesin tiket parkir**. Pengguna diminta memilih jenis kendaraan (Motor, Mobil, atau Bus), memasukkan waktu masuk dan waktu keluar dalam format **HH:MM**, lalu program akan:

1. Memvalidasi semua input agar sesuai aturan,
2. Menghitung lama parkir (termasuk jika melewati tengah malam),
3. Membulatkan durasi ke **jam penuh** bila ada sisa menit,
4. Menghitung total biaya berdasarkan tarif per jam.

Program ini dirancang sebagai **latihan logika pemrograman C** yang realistis dan mudah dipahami, terutama untuk topik input–output, validasi data, percabangan, loop, dan perhitungan waktu.

---

## Cara Berpikir Penulis 

Bayangkan seorang **petugas parkir** yang bekerja secara sistematis. Ia selalu bertanya:

* “Kendaraannya apa?”
* “Masuk jam berapa?”
* “Keluar jam berapa?”

Petugas tersebut hanya menerima **jawaban yang valid**. Jika pengunjung salah mengetik (misalnya memasukkan huruf saat diminta angka), petugas akan berkata:

> “Input salah, silakan ulangi.”

Jika waktu keluar terlihat lebih kecil dari waktu masuk (contoh: masuk 23:00, keluar 01:00), petugas paham bahwa kendaraan **keluar keesokan harinya**. Selain itu, jika ada sisa menit meskipun hanya sedikit, petugas tetap **membulatkan ke satu jam penuh**, sesuai aturan umum parkir.

Program ini meniru cara berpikir petugas tersebut, tetapi dilakukan **secara otomatis oleh komputer**.

---

## Alur Eksekusi Program (Langkah demi Langkah)

### 1. Inisialisasi Variabel

Program diawali dengan deklarasi variabel seperti:

* `pilihan` → menyimpan menu kendaraan yang dipilih
* `jenis` → nama kendaraan (Motor/Mobil/Bus)
* `biaya_per_jam` → tarif parkir per jam
* Variabel jam dan menit untuk waktu masuk dan keluar

Tahap ini bisa diibaratkan sebagai **menyiapkan formulir kosong** sebelum diisi data oleh pengguna.

---

### 2. Menampilkan Menu Kendaraan & Validasi Pilihan

Program menampilkan menu:

1. Motor
2. Mobil
3. Bus

Input dibaca menggunakan `scanf`. Program berada di dalam **loop** sampai pengguna memasukkan pilihan yang benar.

* Jika input **bukan angka**, program membersihkan buffer input lalu meminta ulang.
* Jika angka di luar 1–3, program menolak dan meminta ulang.

Setelah valid:

* `jenis` diisi sesuai kendaraan,
* `biaya_per_jam` ditentukan (Motor = 2000, Mobil = 5000, Bus = 20000).

**Mengapa perlu loop?**
Agar program tidak melanjutkan perhitungan dengan data salah yang bisa menghasilkan output keliru.

---

### 3. Input & Validasi Waktu Masuk (HH:MM)

Pengguna diminta memasukkan waktu masuk dalam format **HH:MM**.

Program:

* Menggunakan `scanf("%d:%d")` untuk membaca jam dan menit,
* Mengecek apakah format benar,
* Memastikan jam berada pada rentang 0–23 dan menit 0–59.

Jika salah, input diminta ulang.

> Catatan: Cara ini cukup sederhana dan efektif untuk latihan, meskipun versi produksi sebaiknya menggunakan `fgets()` + `sscanf()`.

---

### 4. Input & Validasi Waktu Keluar

Langkahnya **identik** dengan waktu masuk.

Perlu dicatat bahwa program **tidak langsung menolak** waktu keluar yang lebih kecil dari waktu masuk, karena itu bisa berarti parkir melewati tengah malam.

---

### 5. Konversi Waktu ke Menit & Penanganan Tengah Malam

Agar perhitungan mudah, waktu diubah menjadi **total menit sejak tengah malam**:

* `masuk_total = jam * 60 + menit`
* `keluar_total = jam * 60 + menit`

Jika `keluar_total < masuk_total`, berarti kendaraan keluar **keesokan hari**, sehingga:

* `keluar_total += 1440` (24 jam × 60 menit)

Dengan cara ini, selisih waktu dapat dihitung dengan aman.

---

### 6. Menghitung Durasi Parkir

Durasi dihitung sebagai:

* `total_menit = keluar_total - masuk_total`

Kemudian dipecah menjadi:

* `durasi_jam = total_menit / 60`
* `durasi_menit = total_menit % 60`

Hasilnya mudah dibaca oleh manusia: **X jam Y menit**.

---

### 7. Pembulatan ke Jam Penuh

Aturan parkir yang dipakai:

* Jika masih ada sisa menit, durasi **dibulatkan ke atas**.

Artinya:

* Jika `durasi_menit > 0` → `waktu_bulat = durasi_jam + 1`
* Jika tidak → `waktu_bulat = durasi_jam`

Logika ini mencerminkan praktik nyata parkir: *jam yang sudah dimulai tetap dihitung satu jam penuh*.

---

### 8. Perhitungan Biaya

Biaya dihitung sangat sederhana:

```
biaya = waktu_bulat × biaya_per_jam
```

Nilai inilah yang akan dibayar pengguna.

---

### 9. Menampilkan Tiket Parkir

Program menampilkan ringkasan akhir berupa:

* Jenis kendaraan
* Waktu masuk & keluar
* Durasi parkir sebenarnya
* Durasi setelah pembulatan
* Total biaya

Tampilan ini menyerupai **struk tiket parkir**.

---

## Contoh Perhitungan Nyata

**Input pengguna:**

* Kendaraan: Mobil
* Masuk: 22:30
* Keluar: 01:15

**Proses:**

* Masuk = 1350 menit
* Keluar = 75 → +1440 = 1515 menit
* Durasi = 165 menit = 2 jam 45 menit
* Dibulatkan → 3 jam
* Biaya = 3 × 5000 = **Rp 15.000**

---

## Tips & Catatan Praktis

* Input tidak valid akan selalu diminta ulang → program aman dari kesalahan pengguna.
* Jika masuk dan keluar sama persis, durasi = 0 → biaya = 0 (bisa diubah sesuai kebijakan).
* Program hanya mendukung satu kali lewat tengah malam.

---

## Keterbatasan & Saran Pengembangan

1. Gunakan `fgets()` untuk input yang lebih aman
2. Terapkan biaya minimal 1 jam
3. Format mata uang agar lebih rapi
4. Tambahkan dukungan parkir multi-hari
5. Pecah program menjadi fungsi-fungsi kecil
6. Simpan transaksi ke file untuk laporan

---

## Penutup

Program ini menerapkan logika parkir secara **jelas, bertahap, dan realistis**. Sangat cocok sebagai latihan bahasa C untuk memahami validasi input, perhitungan waktu, dan logika bisnis sederhana. Dengan sedikit pengembangan, program ini dapat menjadi dasar aplikasi parkir yang lebih lengkap dan profesional.
