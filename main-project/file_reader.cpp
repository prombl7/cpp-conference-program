#include <cstdio>
#include <cstring>
#include "file_reader.h"

int readReports(Report reports[], const char* filename) {
    FILE* f = fopen(filename, "r");
    if (!f) return 0;
    int n = 0;
    char line[MAX_STR];
    while (fgets(line, MAX_STR, f) && n < MAX_SIZE) {
        Report& r = reports[n];
        char rest[MAX_STR];
        sscanf(line, "%d:%d %d:%d %s %s %s",
            &r.startHour, &r.startMin,
            &r.endHour, &r.endMin,
            r.lastName, r.firstName, r.middleName);
        // тема 
        int fields = 0, pos = 0;
        while (pos < (int)strlen(line) && fields < 7) {
            while (line[pos] == ' ') pos++;
            while (line[pos] && line[pos] != ' ' && line[pos] != '\n') pos++;
            fields++;
        }
        while (line[pos] == ' ') pos++;
        strncpy(r.topic, line + pos, MAX_STR);
        // убрал перенос
        int len = strlen(r.topic);
        if (len > 0 && r.topic[len - 1] == '\n') r.topic[len - 1] = '\0';
        n++;
    }
    fclose(f);
    return n;
}