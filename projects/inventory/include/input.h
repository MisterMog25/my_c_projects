#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>
#include <stddef.h>

bool readLine(const char *prompt, char *buf, size_t size);
bool readInt(const char *prompt, int min, int max, int *out);
bool readString(const char *prompt, char *buf, size_t size);


#endif