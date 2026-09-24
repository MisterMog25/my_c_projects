#ifndef INVENTORY_H
#define INVENTORY_H
#define PRODUCT_NAME_LEN 50
#define FILE_LENGTH 250

#include <stdbool.h>
#include <stddef.h>

typedef struct{
    int id;
    char name[PRODUCT_NAME_LEN];
    int price_cents;
    int quantity;
} Product;

typedef struct{
    Product *items;
    size_t count;
    size_t capacity;
    int next_id;
} Inventory;

void inv_init(Inventory *inv);
void inv_free(Inventory *inv);
bool inv_add(Inventory *inv, const char *name, int price_cents, int quantity);
Product* inv_find(Inventory *inv, int id);
bool inv_remove(Inventory *inv, int id);
bool inv_save(const Inventory *inv, const char *path);



#endif