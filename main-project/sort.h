#pragma once
#include "conference.h"

typedef int (*CompareFunc)(Report*, Report*);
typedef void (*SortFunc)(Report* [], int, CompareFunc);

void heapSort(Report* arr[], int n, CompareFunc cmp);
void mergeSort(Report* arr[], int n, CompareFunc cmp);

int compareByDurationDesc(Report* a, Report* b);
int compareByAuthorTopic(Report* a, Report* b);