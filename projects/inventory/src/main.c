#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <time.h> 

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
bool add_product(Inventory *inv, const char *name, int price_cents, int quantity);

int main(){
    Inventory inv;
    inv_init(&inv); 

    Product product1 = {1, "keyboard", 12900, 4};
    Product product2 = {2, "mouse", 5900, 4};
    Product product3 = {3, "laptop", 289999, 4};
    Product items[] = {product1, product2, product3};

    bool isRunning = true;
    printf("*** INVENTORY V2 ***\n");
    
    inv = (Inventory){.items = items, .count = 3, .capacity = 8, .next_id = 4};

    inv_print(&inv);
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
        printf("Quantity %d\n", prods[i].quantity);
    }
}