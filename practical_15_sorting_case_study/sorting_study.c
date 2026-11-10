/*
 * Practical 15 : Case study - comparing five sorting algorithms
 * Algorithms   : Bubble (with early exit), Selection, Insertion, Merge, Quick (last-element pivot)
 * Data sets    : A1..A5 as specified in the syllabus
 * Output       : table on screen + results.csv
 *
 * Time is the average of several repetitions (microseconds) and the number of
 * key comparisons is counted as a machine-independent measure.
 */
#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
static double nowUs(void)
{
    LARGE_INTEGER f, c;
    QueryPerformanceFrequency(&f);
    QueryPerformanceCounter(&c);
    return (double)c.QuadPart * 1e6 / (double)f.QuadPart;
}
#else
#include <time.h>
static double nowUs(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1e6 + ts.tv_nsec / 1e3;
}
#endif

static long long cmpCount;

static void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

/* ---------------- sorting algorithms ---------------- */
void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            cmpCount++;
            if (a[j] > a[j + 1]) { swap(&a[j], &a[j + 1]); swapped = 1; }
        }
        if (!swapped) break;
    }
}

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            cmpCount++;
            if (a[j] < a[min]) min = j;
        }
        if (min != i) swap(&a[i], &a[min]);
    }
}

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0) {
            cmpCount++;
            if (a[j] <= key) break;
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

static void merge(int a[], int tmp[], int lo, int mid, int hi)
{
    int i = lo, j = mid + 1, k = lo;
    while (i <= mid && j <= hi) {
        cmpCount++;
        tmp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= hi)  tmp[k++] = a[j++];
    for (k = lo; k <= hi; k++) a[k] = tmp[k];
}

static void mergeRec(int a[], int tmp[], int lo, int hi)
{
    if (lo >= hi) return;
    int mid = lo + (hi - lo) / 2;
    mergeRec(a, tmp, lo, mid);
    mergeRec(a, tmp, mid + 1, hi);
    merge(a, tmp, lo, mid, hi);
}

void mergeSort(int a[], int n)
{
    int *tmp = (int *)malloc(n * sizeof(int));
    if (!tmp) { printf("Out of memory!\n"); exit(1); }
    mergeRec(a, tmp, 0, n - 1);
    free(tmp);
}

static int partition(int a[], int lo, int hi)
{
    int pivot = a[hi], i = lo - 1;
    for (int j = lo; j < hi; j++) {
        cmpCount++;
        if (a[j] <= pivot) swap(&a[++i], &a[j]);
    }
    swap(&a[i + 1], &a[hi]);
    return i + 1;
}

static void quickRec(int a[], int lo, int hi)
{
    if (lo < hi) {
        int p = partition(a, lo, hi);
        quickRec(a, lo, p - 1);
        quickRec(a, p + 1, hi);
    }
}

void quickSort(int a[], int n) { quickRec(a, 0, n - 1); }

/* ---------------- data generation ---------------- */
static int cmpInt(const void *x, const void *y) { return *(const int *)x - *(const int *)y; }

typedef struct { const char *id, *desc; int n; int *data; } Dataset;

static int isSorted(const int a[], int n)
{
    for (int i = 1; i < n; i++) if (a[i - 1] > a[i]) return 0;
    return 1;
}

int main(void)
{
    srand(42);                                     /* fixed seed => reproducible results */

    int a1[10] = {9, 2, 5, 1, 8, 4, 3, 7, 6, 0};
    int a2[100], a3[1000], a4[1000], a5[1000];
    for (int i = 0; i < 100;  i++) a2[i] = rand() % 1000 + 1;
    for (int i = 0; i < 1000; i++) a3[i] = rand() % 10000 + 1;
    for (int i = 0; i < 1000; i++) a4[i] = rand() % 10000 + 1;
    qsort(a4, 950, sizeof(int), cmpInt);           /* first 950 sorted, last 50 left shuffled */
    for (int i = 0; i < 1000; i++) a5[i] = 1000 - i;

    Dataset sets[5] = {
        {"A1", "Small random (n=10)",          10,   a1},
        {"A2", "Medium random (n=100)",        100,  a2},
        {"A3", "Large random (n=1000)",        1000, a3},
        {"A4", "Nearly sorted (n=1000)",       1000, a4},
        {"A5", "Reverse sorted (n=1000)",      1000, a5},
    };

    struct { const char *name; void (*fn)(int[], int); } algo[5] = {
        {"Bubble",    bubbleSort},
        {"Selection", selectionSort},
        {"Insertion", insertionSort},
        {"Merge",     mergeSort},
        {"Quick",     quickSort},
    };

    FILE *csv = fopen("results.csv", "w");
    if (csv) fprintf(csv, "array,description,n,algorithm,avg_time_us,comparisons\n");

    printf("Sorting algorithm comparison (ascending order)\n");
    printf("Time = average over repetitions, Comparisons = key comparisons made\n");

    for (int s = 0; s < 5; s++) {
        int n = sets[s].n;
        int reps = (n <= 10) ? 20000 : (n <= 100) ? 2000 : 20;
        int *work = (int *)malloc(n * sizeof(int));
        if (!work) return 1;

        printf("\n%s - %s\n", sets[s].id, sets[s].desc);
        printf("%-10s %14s %14s\n", "Algorithm", "Time (us)", "Comparisons");
        printf("-------------------------------------------\n");

        double best = 1e18; const char *bestName = "";
        for (int k = 0; k < 5; k++) {
            double total = 0;
            for (int r = 0; r < reps; r++) {
                memcpy(work, sets[s].data, n * sizeof(int));
                cmpCount = 0;
                double t0 = nowUs();
                algo[k].fn(work, n);
                total += nowUs() - t0;
            }
            double avg = total / reps;
            if (!isSorted(work, n)) printf("ERROR: %s failed to sort!\n", algo[k].name);
            printf("%-10s %14.2f %14lld\n", algo[k].name, avg, cmpCount);
            if (csv) fprintf(csv, "%s,%s,%d,%s,%.2f,%lld\n", sets[s].id, sets[s].desc, n, algo[k].name, avg, cmpCount);
            if (avg < best) { best = avg; bestName = algo[k].name; }
        }
        printf("Fastest: %s\n", bestName);
        free(work);
    }

    if (csv) { fclose(csv); printf("\nResults saved to results.csv\n"); }
    return 0;
}
