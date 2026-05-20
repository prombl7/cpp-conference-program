#pragma once
#include "conference.h"

int filterByAuthor(Report* src[], int n, Report* dst[],
    const char* lastName, const char* firstName, const char* middleName);

int filterByDuration(Report* src[], int n, Report* dst[], int minMinutes); 
