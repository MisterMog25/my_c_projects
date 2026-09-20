#include "inventory.h"
#include <stdio.h>
#include <stdlib.h>

void inv_init(Inventory *inv){
    inv->items = NULL;
    inv->count = 0;
    inv -> capacity = 0;
    inv -> next_id = 1;
}

void inv_free(Inventory *inv){
    free(inv->items);
    inv_init(inv);
}

bool inv_add(Inventory *inv, const char *name, int price_cents, int quantity) {
    if (inv->capacity == inv->count) {
        size_t newCap = (inv->capacity) ? inv->capacity * 2 : 8;
        Product *temp = realloc(inv->items, sizeof(Product) * newCap);
        if (temp == NULL) return 0;
        inv->items = temp;
        inv->capacity = newCap;
        temp = NULL;
    }

    Product *p = &inv->items[inv->count];
    p->id = inv->next_id;
    snprintf(p->name, sizeof p->name, "%s", name);
    p->price_cents = price_cents;
    p->quantity = quantity;

    (inv->count)++;
    (inv->next_id)++;
    return 1;
}

