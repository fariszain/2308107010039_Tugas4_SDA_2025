Tugas 4 Struktur Data dan Algoritma 2025
Informasi Proyek
Tugas ini merupakan bagian dari mata kuliah Struktur Data dan Algoritma, Program Studi Informatika, Fakultas Matematika dan Ilmu Pengetahuan Alam, Universitas Syiah Kuala, yang disusun untuk mengevaluasi performa enam algoritma pengurutan: Bubble Sort, Selection Sort, Insertion Sort, Shell Sort, Merge Sort, dan Quick Sort. Proyek ini mengukur efisiensi algoritma berdasarkan waktu eksekusi (dalam detik) dan penggunaan memori (dalam megabyte) pada data acak berupa angka dan kata, dengan ukuran data berkisar dari 10.000 hingga 2.000.000 elemen. Implementasi dilakukan menggunakan bahasa pemrograman C, dengan visualisasi hasil melalui grafik interaktif berbasis Chart.js dalam file HTML. Laporan lengkap, kode sumber, file data, dan visualisasi disertakan dalam repositori ini, memenuhi persyaratan tugas yang diberikan oleh dosen pengasuh, Alim Misbullah, S.Si., M.Si.
Informasi Pengembang

Nama: Faris Zain As-Shadiq  
NPM: 2308107010039  
Program Studi: Informatika  
Fakultas: Matematika dan Ilmu Pengetahuan Alam  
Universitas: Syiah Kuala  
Tahun: 2025

Deskripsi Proyek
Proyek ini bertujuan untuk membandingkan performa enam algoritma pengurutan dalam mengolah data berskala besar. Data uji terdiri dari 2.000.000 angka acak (disimpan dalam data_angka.txt) dan 2.000.000 kata acak (disimpan dalam data_kata.txt), yang dihasilkan menggunakan kode pembangkit yang disediakan. Program utama (main.c) memungkinkan pengguna memilih jenis data (angka atau kata) dan ukuran data melalui antarmuka interaktif, kemudian menjalankan setiap algoritma pada salinan data untuk mengukur waktu eksekusi menggunakan fungsi clock() dan menghitung estimasi memori dengan formula 0.95 * (n / 10000.0) MB. Fungsi pengurutan didefinisikan dalam file header sorting.h, yang mencakup implementasi untuk data angka dan kata, masing-masing dengan komentar yang menjelaskan prinsip kerja dan kompleksitas. Hasil eksperimen ditampilkan dalam tabel terformat di konsol dan divisualisasikan melalui grafik garis interaktif dalam index.html, yang memungkinkan perbandingan waktu eksekusi dan penggunaan memori untuk kedua jenis data. Laporan lengkap dalam format PDF (2308107010039_Tugas4_SDA_2025.pdf) mendokumentasikan deskripsi algoritma, implementasi, hasil eksperimen, grafik, analisis, dan kesimpulan, menunjukkan bahwa Quick Sort adalah algoritma tercepat, diikuti oleh Merge Sort dan Shell Sort, sementara Bubble Sort, Selection Sort, dan Insertion Sort kurang efisien untuk data besar.
Struktur Direktori
Repositori ini memiliki struktur sebagai berikut:  

src/: Berisi kode sumber proyek.  
main.c: Program utama yang mengatur alur eksperimen dan menampilkan hasil.  
sorting.h: File header yang mendefinisikan fungsi-fungsi pengurutan untuk angka dan kata.


data/: Berisi file data uji.  
data_angka.txt: File teks berisi 2.000.000 angka acak.  
data_kata.txt: File teks berisi 2.000.000 kata acak.  
generate_data.c: Kode untuk menghasilkan file data (opsional, jika file data tidak diunggah langsung).


visualization/: Berisi file visualisasi.  
index.html: File HTML dengan grafik interaktif menggunakan Chart.js untuk memvisualisasikan waktu eksekusi dan penggunaan memori.


docs/: Berisi dokumentasi proyek.  
2308107010039_Tugas4_SDA_2025.pdf: Laporan lengkap dalam format PDF.


README.md: File ini, yang menjelaskan proyek dan cara penggunaannya.

Petunjuk Penggunaan
Untuk menjalankan proyek ini, ikuti langkah-langkah berikut:  

Prasyarat: Pastikan Anda memiliki kompiler C (misalnya, gcc) dan peramban web modern untuk membuka file HTML.  
Kompilasi dan Eksekusi Program:  
Navigasi ke direktori src/ menggunakan terminal.  
Kompilasi program dengan perintah:  gcc -o main main.c


Jalankan program dengan perintah:  ./main


Ikuti petunjuk di konsol untuk memilih jenis data (1 untuk angka, 2 untuk kata) dan ukuran data (1 hingga 8 untuk 10.000 hingga 2.000.000 elemen). Program akan menampilkan tabel hasil berisi waktu eksekusi dan penggunaan memori untuk setiap algoritma.


Melihat Visualisasi:  
Buka file visualization/index.html di peramban web.  
Gunakan tombol interaktif untuk beralih antara grafik waktu eksekusi dan penggunaan memori, serta antara data angka dan kata. Skala logaritmik digunakan untuk waktu agar rentang nilai lebih jelas.


Membaca Laporan:  
Buka file docs/2308107010039_Tugas4_SDA_2025.pdf untuk membaca laporan lengkap, yang mencakup deskripsi algoritma, hasil eksperimen, grafik, analisis, dan kesimpulan.



Catatan Tambahan

Hasil Eksperimen: Tabel dalam laporan menunjukkan bahwa Quick Sort memiliki waktu eksekusi tercepat (0.217 detik untuk 2.000.000 angka, 0.713 detik untuk kata), diikuti oleh Merge Sort (0.522 detik untuk angka, 1.240 detik untuk kata) dan Shell Sort (0.412 detik untuk angka, 3.004 detik untuk kata). Bubble Sort adalah yang terlambat (8312.124 detik untuk angka, 42011.117 detik untuk kata), diikuti oleh Selection Sort dan Insertion Sort. Penggunaan memori bersifat linier (0.95 MB hingga 190.00 MB), tetapi estimasi ini tidak mencerminkan kebutuhan memori spesifik algoritma.  
Keterbatasan: Pengukuran memori menggunakan formula estimasi karena keterbatasan platform, sehingga alat seperti Valgrind tidak digunakan. Pengujian dilakukan sekali per ukuran data, tanpa rata-rata dari beberapa percobaan.  
Rekomendasi: Untuk pengembangan lebih lanjut, pertimbangkan pengukuran memori dengan Valgrind, pengujian berulang untuk hasil yang lebih akurat, atau pengujian dengan distribusi data tambahan (misalnya, data terurut atau terbalik).  
Integritas Akademik: Proyek ini dikerjakan secara individu oleh Faris Zain As-Shadiq, sesuai dengan pedoman tugas.
