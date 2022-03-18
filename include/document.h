#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "types.h"
#include "date.h"

typedef struct Document Document;
struct Document {
    char* issuer;
    char* type;
    char* name;
    Date adoption;
    Date info_force;
    bool ru_translation;
};

#endif