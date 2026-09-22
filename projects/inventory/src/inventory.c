#include "inventory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

Product* inv_find(Inventory *inv, int id){
    if (inv->count == 0) {
        return NULL;
    }
    for (size_t i = 0; i <inv->count; i++){
        if (inv->items[i].id == id){
            return inv->items + i;
        }
    }
    return NULL;
}
// [A, B, C, D, E]
bool inv_remove(Inventory *inv, int id) {
    Product *p = inv_find(inv, id);

    if (p == NULL){
        return false;
    }

    size_t idx = p - inv->items;
    size_t num_after = inv->count - idx - 1;

    if (num_after > 0) {
        memmove(p, p+1, sizeof(Product) * num_after);
    }

    (inv->count)--;
    return true;

}



