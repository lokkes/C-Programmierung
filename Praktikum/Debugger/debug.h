#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>

#define FNAME "prot.log"

extern FILE *ProtFile;

#ifdef DEBUG

#define DEBUG_STR(Str) do {                          \
    if (ProtFile == NULL) {                          \
        ProtFile = fopen(FNAME, "w");                \
    }                                                \
    if (ProtFile != NULL) {                          \
        fprintf(ProtFile, "%s", (Str));              \
        fclose(ProtFile);                            \
        ProtFile = fopen(FNAME, "a");                \
    }                                                \
} while (0)

#define DEBUG_INT(i) do {                          \
    if (ProtFile == NULL) {                        \
        ProtFile = fopen(FNAME, "w");              \
    }                                              \
    if (ProtFile != NULL) {                        \
        fprintf(ProtFile, "%d\n", (i));            \
        fclose(ProtFile);                          \
        ProtFile = fopen(FNAME, "a");              \
    }                                              \
} while (0)

#define DEBUG_CHR(c) do {                          \
    if (ProtFile == NULL) {                        \
        ProtFile = fopen(FNAME, "w");              \
    }                                              \
    if (ProtFile != NULL) {                        \
        fprintf(ProtFile, "%c\n", (c));            \
        fclose(ProtFile);                          \
        ProtFile = fopen(FNAME, "a");              \
    }                                              \
} while (0)

#define DEBUG_LONG(l) do {                         \
    if (ProtFile == NULL) {                        \
        ProtFile = fopen(FNAME, "w");              \
    }                                              \
    if (ProtFile != NULL) {                        \
        fprintf(ProtFile, "%ld\n", (l));           \
        fclose(ProtFile);                          \
        ProtFile = fopen(FNAME, "a");              \
    }                                              \
} while (0)

#else

#define DEBUG_STR(Str) do { } while (0)

#endif

#endif
