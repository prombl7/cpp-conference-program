#include "processing.h"

int findMaxDurationIndex(Report reports[], int n) {
    if (n == 0) return -1;
    int maxIndex = 0;
    int maxDur = (reports[0].endHour * 60 + reports[0].endMin)
        - (reports[0].startHour * 60 + reports[0].startMin);

    for (int i = 1; i < n; i++) {
        int dur = (reports[i].endHour * 60 + reports[i].endMin)
            - (reports[i].startHour * 60 + reports[i].startMin);
        if (dur > maxDur) {
            maxDur = dur;
            maxIndex = i;
        }
    }
    return maxIndex;
}