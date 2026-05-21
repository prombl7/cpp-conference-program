#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "filter.h"

int filterByAuthor(Report* src[], int n, Report* dst[],
    const char* lastName, const char* firstName, const char* middleName) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(src[i]->lastName, lastName) == 0 &&
            strcmp(src[i]->firstName, firstName) == 0 &&
            strcmp(src[i]->middleName, middleName) == 0)
            dst[k++] = src[i];
    }
    return k;
}

int filterByDuration(Report* src[], int n, Report* dst[], int minMinutes) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        int dur = (src[i]->endHour * 60 + src[i]->endMin)
            - (src[i]->startHour * 60 + src[i]->startMin);
        if (dur > minMinutes)
            dst[k++] = src[i];
    }
    return k;
}