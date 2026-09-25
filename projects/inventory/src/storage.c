#include "storage.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool inv_load(Inventory *inv, const char *path) {
    char line[1024] = {0};
    int id = 0;
    char name[PRODUCT_NAME_LEN] = {0};
    int price_cents = 0;
    int quantity = 0;
    int nextId = 0;

    FILE *pFile = fopen(path, "r");
    if (pFile == NULL) {
        // printf("Error: could not open file for reading.\n");
        return false;
    }

    Inventory fresh;
    inv_init(&fresh);

    if (fgets(line, sizeof(line), pFile) == NULL){
        inv_free(&fresh);
        fclose(pFile);
        return false;
    };
    if(sscanf(line, "INVDB 1 %d", &nextId) != 1){
        inv_free(&fresh);
        fclose(pFile);
        return false;
    }

    while (fgets(line, sizeof(line), pFile) != NULL) {
        if (sscanf(line, "%d|%49[^|]|%d|%d", &id, name, &price_cents, &quantity) != 4) {
            inv_free(&fresh);
            fclose(pFile);
            return false;
        };
        if (!inv_add(&fresh, name, price_cents, quantity)) {
            inv_free(&fresh);
            fclose(pFile);
            return false;
        }
        fresh.items[fresh.count - 1].id = id;                  
    }
    fresh.next_id = nextId;
    inv_free(inv);
    *inv = fresh;

    fclose(pFile);
    return true;
}