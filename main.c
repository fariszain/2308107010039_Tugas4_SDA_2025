#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include "sorting.h"

#define MAX_WORD_LEN 100
#define MAX_DATA 2000000

int *original_int = NULL;
int *copy_int = NULL;
char **original_str = NULL;
char **copy_str = NULL;
size_t current_allocated_size = 0;

void load_data_int(const char *filename, int *arr, int n);
void load_data_str(const char *filename, char **arr, int n);
void jalankan_sorting_int(int n);
void jalankan_sorting_str(int n);
void cleanup_memory();

void load_data_int(const char *filename, int *arr, int n) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Gagal membuka file %s: %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++) {
        if (fscanf(fp, "%d", &arr[i]) != 1) {
            fprintf(stderr, "File %s berisi kurang dari %d angka (hanya %d ditemukan).\n", filename, n, i);
            fclose(fp);
            exit(EXIT_FAILURE);
        }
    }
    fclose(fp);
}

void load_data_str(const char *filename, char **arr, int n) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Gagal membuka file %s: %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }
    char buffer[MAX_WORD_LEN];
    for (int i = 0; i < n; i++) {
        if (fscanf(fp, "%99s", buffer) != 1) {
            fprintf(stderr, "File %s berisi kurang dari %d kata (hanya %d ditemukan).\n", filename, n, i);
            fclose(fp);
            exit(EXIT_FAILURE);
        }
        arr[i] = (char *)malloc(strlen(buffer) + 1);
        if (!arr[i]) {
            fprintf(stderr, "Gagal mengalokasikan memori untuk kata ke-%d.\n", i);
            fclose(fp);
            exit(EXIT_FAILURE);
        }
        strcpy(arr[i], buffer);
    }
    fclose(fp);
}

void jalankan_sorting_int(int n) {
    original_int = (int *)malloc(n * sizeof(int));
    copy_int = (int *)malloc(n * sizeof(int));
    if (!original_int || !copy_int) {
        fprintf(stderr, "Gagal mengalokasikan memori untuk %d data integer (%zu MB).\n",
                n, (2 * n * sizeof(int)) / (1024.0 * 1024.0));
        cleanup_memory();
        exit(EXIT_FAILURE);
    }

    load_data_int("../data/data_angka.txt", original_int, n);

    printf("\nMenjalankan sorting untuk %d data...\n\n", n);
    printf("+----------------------------+--------------+--------------+\n");
    printf("|         Algoritma          |  Waktu (s)   | Memori (MB)  |\n");
    printf("+----------------------------+--------------+--------------+\n");

    memcpy(copy_int, original_int, n * sizeof(int));
    benchmark_sort_int("Bubble Sort (int)", bubble_sort_int, copy_int, n);

    memcpy(copy_int, original_int, n * sizeof(int));
    benchmark_sort_int("Selection Sort (int)", selection_sort_int, copy_int, n);

    memcpy(copy_int, original_int, n * sizeof(int));
    benchmark_sort_int("Insertion Sort (int)", insertion_sort_int, copy_int, n);

    memcpy(copy_int, original_int, n * sizeof(int));
    benchmark_sort_int("Merge Sort (int)", merge_sort_int_wrapper, copy_int, n);

    memcpy(copy_int, original_int, n * sizeof(int));
    benchmark_sort_int("Quick Sort (int)", quick_sort_int_wrapper, copy_int, n);

    memcpy(copy_int, original_int, n * sizeof(int));
    benchmark_sort_int("Shell Sort (int)", shell_sort_int, copy_int, n);

    printf("+----------------------------+--------------+--------------+\n");
}

void jalankan_sorting_str(int n) {
    original_str = (char **)malloc(n * sizeof(char *));
    copy_str = (char **)malloc(n * sizeof(char *));
    if (!original_str || !copy_str) {
        fprintf(stderr, "Gagal mengalokasikan memori untuk %d data string.\n", n);
        cleanup_memory();
        exit(EXIT_FAILURE);
    }

    current_allocated_size = n;

    load_data_str("../data/data_kata.txt", original_str, n);

    for (int i = 0; i < n; i++) {
        size_t len = strlen(original_str[i]);
        copy_str[i] = (char *)malloc(len + 1);
        if (!copy_str[i]) {
            fprintf(stderr, "Gagal mengalokasikan memori untuk copy_str[%d].\n", i);
            cleanup_memory();
            exit(EXIT_FAILURE);
        }
        strcpy(copy_str[i], original_str[i]);
    }

    printf("\nMenjalankan sorting untuk %d data...\n\n", n);
    printf("+----------------------------+--------------+--------------+\n");
    printf("|         Algoritma          |  Waktu (s)   | Memori (MB)  |\n");
    printf("+----------------------------+--------------+--------------+\n");

    const char *labels[] = {
        "Bubble Sort (kata)", "Selection Sort (kata)", "Insertion Sort (kata)",
        "Merge Sort (kata)", "Quick Sort (kata)", "Shell Sort (kata)"
    };
    void (*functions[])(char **, int) = {
        bubble_sort_str, selection_sort_str, insertion_sort_str,
        merge_sort_str_wrapper, quick_sort_str_wrapper, shell_sort_str
    };

    for (int s = 0; s < 6; s++) {
        for (int i = 0; i < n; i++) {
            size_t len = strlen(original_str[i]);
            free(copy_str[i]);
            copy_str[i] = (char *)malloc(len + 1);
            if (!copy_str[i]) {
                fprintf(stderr, "Gagal malloc ulang copy_str[%d].\n", i);
                cleanup_memory();
                exit(EXIT_FAILURE);
            }
            strcpy(copy_str[i], original_str[i]);
        }
        benchmark_sort_str(labels[s], functions[s], copy_str, n);
    }

    printf("+----------------------------+--------------+--------------+\n");
}

void cleanup_memory() {
    if (original_int) {
        free(original_int);
        original_int = NULL;
    }
    if (copy_int) {
        free(copy_int);
        copy_int = NULL;
    }
    if (original_str) {
        for (size_t i = 0; i < current_allocated_size; i++) {
            if (original_str[i]) free(original_str[i]);
            if (copy_str && copy_str[i]) free(copy_str[i]);
        }
        free(original_str);
        free(copy_str);
        original_str = NULL;
        copy_str = NULL;
        current_allocated_size = 0;
    }
}

int pilih_jenis_data() {
    int pilihan;
    printf("=== PILIH JENIS DATA ===\n");
    printf("1. Angka\n2. Kata\nMasukkan pilihan [1-2]: ");
    if (scanf("%d", &pilihan) != 1 || pilihan < 1 || pilihan > 2) {
        printf("Pilihan tidak valid.\n");
        while (getchar() != '\n');
        exit(EXIT_FAILURE);
    }
    while (getchar() != '\n');
    return pilihan;
}

int pilih_ukuran_data() {
    int pilihan;
    int ukuran_data[] = {10000, 50000, 100000, 250000, 500000, 1000000, 1500000, 2000000};
    printf("\n=== PILIH UKURAN DATA ===\n");
    for (int i = 0; i < 8; i++) printf("%d. %d data\n", i + 1, ukuran_data[i]);
    printf("Masukkan pilihan [1-8]: ");
    if (scanf("%d", &pilihan) != 1 || pilihan < 1 || pilihan > 8) {
        printf("Pilihan tidak valid.\n");
        while (getchar() != '\n');
        exit(EXIT_FAILURE);
    }
    while (getchar() != '\n');
    return ukuran_data[pilihan - 1];
}

int main() {
    int jenis = pilih_jenis_data();
    int n = pilih_ukuran_data();

    cleanup_memory();

    if (jenis == 1) {
        jalankan_sorting_int(n);
    } else {
        jalankan_sorting_str(n);
    }

    cleanup_memory();
    return 0;
}
    