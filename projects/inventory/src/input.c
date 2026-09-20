#include "input.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

bool readLine(const char *prompt, char *buf, size_t size) {
    printf("%s", prompt);
    if (fgets(buf, (int)size, stdin) == NULL) return false;

    size_t len = strcspn(buf, "\n");
    if (buf[len] == '\n') {
        buf[len] = '\0';
    } else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    }
    return true;
}

bool readString(const char *prompt, char *buf, size_t size) {
    for (;;) {
        if (!readLine(prompt, buf, size)) return false;

        if (buf[0] == '\0') {
            printf("Name cannot be empty. Please try again.\n");
            continue;
        }

        return true;
    }
}

bool readInt(const char *prompt, int min, int max, int *out) {
    char buf[64];
    for (;;) {
        if (!readLine(prompt, buf, sizeof buf)) return false;

        char *end;
        errno = 0;
        long v = strtol(buf, &end, 10);
        if (end == buf || *end != '\0' || errno == ERANGE || v < min || v > max) {
            printf("Please enter a whole number from %d to %d.\n", min, max);
            continue;
        }
        *out = (int)v;
        return true;
    }
}