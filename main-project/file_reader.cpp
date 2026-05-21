#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include "conference.h"

int readReports(Report reports[], const char* filename) {
    FILE* f = fopen(filename, "r");
    if (!f) return 0;

    int n = 0;
    char line[MAX_STR];

    while (fgets(line, MAX_STR, f) && n < MAX_SIZE) {
        Report& r = reports[n];

        int res = sscanf(line,
            "%d:%d %d:%d %s %s %s %s",
            &r.startHour, &r.startMin,
            &r.endHour, &r.endMin,
            r.lastName,
            r.firstName,
            r.middleName,
            r.topic
        );

        // защита от мусора и \n
        if (res == 8) {
            r.topic[strcspn(r.topic, "\r\n")] = 0;
            n++;
        }
    }

    fclose(f);
    return n;
}