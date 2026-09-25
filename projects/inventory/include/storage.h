#ifndef STORAGE_H
#define STORAGE_H

#include <stdbool.h>
#include <stddef.h>
#include "inventory.h"

bool inv_load(Inventory *inv, const char *path);

#endif