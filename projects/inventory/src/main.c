#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct{
    int id;
    char name[50];
    int price_cents;
    int quantity;
} Product;

typedef struct{
    Product *items;
    size_t count;
    size_t capacity;
    int next_id;
} Inventory;

void inv_print(const Inventory *inv);
void inv_init(Inventory *inv);
void inv_free(Inventory *inv);
bool inv_add(Inventory *inv, const char *name, int price_cents, int quantity);

int main(void){
    Inventory inv;
    inv_init(&inv); 
    int choice = 0;
    bool isRunning = true;

    printf("*** INVENTORY V2 ***\n");

    inv_add(&inv, "keyboard", 12900, 4);
    inv_add(&inv, "mouse", 5900, 4);
    inv_add(&inv, "laptop", 289999, 4);

    inv_print(&inv);
    inv_free(&inv);
    return 0;
}

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

void inv_print(const Inventory *inv){
    int price_dollars = 0;
    int price_cents = 0;
    Product *prods = inv->items;

    for (size_t i = 0; i < inv->count; i++){
        price_dollars = prods[i].price_cents / 100;
        price_cents = prods[i].price_cents % 100;
        printf("Product #%d\n", prods[i].id);
        printf("Name: %s\n", prods[i].name);
        printf("Price: $%d.%02d\n", price_dollars, price_cents);
        printf("Quantity: %d\n", prods[i].quantity);
    }
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