#include <cstring>
#include "sort.h"

static int duration(Report* r) {
    return (r->endHour * 60 + r->endMin) - (r->startHour * 60 + r->startMin);
}

int compareByDurationDesc(Report* a, Report* b) {
    return duration(b) - duration(a);
}

int compareByAuthorTopic(Report* a, Report* b) {
    int c = strcmp(a->lastName, b->lastName);
    if (c != 0) return c;
    return strcmp(a->topic, b->topic);
}

// 1
static void heapify(Report* arr[], int n, int i, CompareFunc cmp) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && cmp(arr[l], arr[largest]) < 0) largest = l;
    if (r < n && cmp(arr[r], arr[largest]) < 0) largest = r;
    if (largest != i) {
        Report* tmp = arr[i]; arr[i] = arr[largest]; arr[largest] = tmp;
        heapify(arr, n, largest, cmp);
    }
}

void heapSort(Report* arr[], int n, CompareFunc cmp) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i, cmp);
    for (int i = n - 1; i > 0; i--) {
        Report* tmp = arr[0]; arr[0] = arr[i]; arr[i] = tmp;
        heapify(arr, i, 0, cmp);
    }
}

// 1
static void merge(Report* arr[], int l, int m, int r, CompareFunc cmp) {
    int n1 = m - l + 1, n2 = r - m;
    Report** L = new Report * [n1];
    Report** R = new Report * [n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (cmp(L[i], R[j]) <= 0) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    delete[] L; delete[] R;
}

static void mergeSortHelper(Report* arr[], int l, int r, CompareFunc cmp) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSortHelper(arr, l, m, cmp);
        mergeSortHelper(arr, m + 1, r, cmp);
        merge(arr, l, m, r, cmp);
    }
}

void mergeSort(Report* arr[], int n, CompareFunc cmp) {
    mergeSortHelper(arr, 0, n - 1, cmp);
}