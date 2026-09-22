#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "inventory.h"
#include "input.h"

void inv_print(const Inventory *inv);
void prod_print(const Product *p);

int main(void){
    Inventory inv;
    inv_init(&inv); 

    int choice = 0;
    char name[PRODUCT_NAME_LEN] = "";
    int price = 0;
    int quantity = 0;
    bool isRunning = true;
    int id = 0;

    printf("*** INVENTORY V2 ***\n");

    while (isRunning){
        printf("\n1 Add   2 List   3 Find by id   4 Remove by id   5 Exit\n");
        if (!readInt("Enter the number: ", 1, 5, &choice)) break;
        switch (choice) {
            case 1:
                if (!readString("\nEnter the name of the product: ", name, PRODUCT_NAME_LEN) ||
                    !readInt("Enter the price in cents: ", 1, 999999999, &price) ||
                    !readInt("Enter the quantity: ", 0, 999999999, &quantity)) {
                    isRunning = false;
                    break;
                }
                inv_add(&inv, name, price, quantity);
                break;
            case 2:
                inv_print(&inv);
                break;
            case 3:
                if (!readInt("Enter the id: ", 1, 999999999, &id)){
                    isRunning = false;
                    break;
                };
                Product *p = inv_find(&inv, id);
                if (p != NULL){
                    prod_print(p);
                } else {
                    printf("Not found, try again\n");
                }
                break;
            case 4:
                if (!readInt("Enter the id to delete: ", 1, 999999999, &id)){
                    isRunning = false;
                    break;
                };
                if(inv_remove(&inv, id)){
                    printf("Successfuly deleted\n");
                } else {
                    printf("An error occured\n");
                };
                break;
            case 5:
                isRunning = false;
                break;
        }
    }

    inv_free(&inv);
    printf("Goodbye!\n");
    
    return 0;
}



void inv_print(const Inventory *inv){
    int price_dollars = 0;
    int price_cents = 0;
    Product *prods = inv->items;

    for (size_t i = 0; i < inv->count; i++){
        price_dollars = prods[i].price_cents / 100;
        price_cents = prods[i].price_cents % 100;
        printf("\nProduct #%d   ", prods[i].id);
        printf("Name: %s   ", prods[i].name);
        printf("Price: $%d.%02d   ", price_dollars, price_cents);
        printf("Quantity: %d", prods[i].quantity);
    }
}

void prod_print(const Product *p){
    int price_dollars = 0;
    int price_cents = 0;

    price_dollars = p->price_cents / 100;
    price_cents = p->price_cents % 100;
    printf("\nProduct #%d   ", p->id);
    printf("Name: %s   ", p->name);
    printf("Price: $%d.%02d   ", price_dollars, price_cents);
    printf("Quantity: %d\n", p->quantity);
}