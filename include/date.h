#ifndef DATE_H
#define DATE_H

#include "types.h"
#include "date.h"

typedef size_t Year;
typedef byte Month;
typedef byte Day;
typedef struct Date Date;

struct Date {
    Day day;
    Month month;
    Year year;
};

#endif