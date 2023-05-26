#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quick_sort(int arr[], int left, int right) {
    int i = left, j = right;
    int temp;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (left < j) {
        quick_sort(arr, left, j);
    }
    if (i < right) {
        quick_sort(arr, i, right);
    }
}

int main(int argc, char *argv[]) {
    int n = argc - 1;
    int arr[n];
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = atoi(argv[i+1]);
    }
    clock_t start = clock();
    quick_sort(arr, 0, n-1);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken: %f seconds\n", time_spent);
    return 0;
}
