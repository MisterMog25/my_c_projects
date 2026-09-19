#include <stdio.h>

typdef struct{
    int id;
    char name[50];
    int price_cents;
    int quantity;
} Product;

typdef struct{
    Product *items;
    size_t count;
    size_t capacity;
    int next_id;
} Inventory;

void inv_init(Inventory *inv);
void inv_free(Inventory *inv);

int main(){
    Inventory *inv = NULL;
    inv_init(inv)

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