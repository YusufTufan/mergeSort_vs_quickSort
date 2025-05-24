#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_TESTS 50

int comparisons = 0;

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;

    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L); free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1); 
    for (int j = low; j <= high - 1; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
        }
    }
    int t = arr[i+1]; arr[i+1] = arr[high]; arr[high] = t;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void fillRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand();
}

double avgTime(void (*sortFn)(int*, int, int), int n) {
    int *arr = malloc(n * sizeof(int));
    clock_t start, end;
    double total_time = 0;

    for (int i = 0; i < NUM_TESTS; i++) {
        fillRandomArray(arr, n);
        start = clock();
        sortFn(arr, 0, n - 1);
        end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }

    free(arr);
    return total_time / NUM_TESTS;
}

int main() {
    srand(time(NULL));
    int sizes[] = {1000, 5000, 10000, 50000, 100000, 200000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("QuickSort:\n");
    for (int i = 0; i < num_sizes; i++) {
        double t = avgTime(quickSort, sizes[i]);
        double c = t / (sizes[i] * log2(sizes[i]));
        printf("n=%d, T(n)=%.6f, c=%.8f\n", sizes[i], t, c);
    }

    printf("\nMergeSort:\n");
    for (int i = 0; i < num_sizes; i++) {
        double t = avgTime(mergeSort, sizes[i]);
        double c = t / (sizes[i] * log2(sizes[i]));
        printf("n=%d, T(n)=%.6f, c=%.8f\n", sizes[i], t, c);
    }

    return 0;
}
