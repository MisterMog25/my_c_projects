#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "inventory.h"
#include "input.h"



void inv_print(const Inventory *inv);


int main(void){
    Inventory inv;
    inv_init(&inv); 

    int choice = 0;
    char name[PRODUCT_NAME_LEN] = "";
    int price = 0;
    int quantity = 0;
    bool isRunning = true;

    printf("*** INVENTORY V2 ***\n1 - ADD PRODUCT\n2 - EXIT\n");

    while (isRunning){
        if (!readInt("Enter the number: ", 1, 2, &choice)) break;
        switch (choice) {
            case 1:
                readString("Enter the name of the product: ", name, PRODUCT_NAME_LEN);
                readInt("Enter the price in cents: ", 1, 999999999, &price);
                readInt("Enter the quantity: ", 1, 999999999, &quantity);

                inv_add(&inv, name, price, quantity);
                break;
            case 2:
                inv_free(&inv);
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
        printf("Product #%d\n", prods[i].id);
        printf("Name: %s\n", prods[i].name);
        printf("Price: $%d.%02d\n", price_dollars, price_cents);
        printf("Quantity: %d\n", prods[i].quantity);
    }
}