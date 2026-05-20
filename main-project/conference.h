#pragma once
#include "constants.h"

struct Report {
    int startHour;
    int startMin;
    int endHour;
    int endMin;
    char lastName[MAX_STR];
    char firstName[MAX_STR];
    char middleName[MAX_STR];
    char topic[MAX_STR];
};