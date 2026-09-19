#include <stdio.h>

typedef struct{
    char model[25];
    int year;
    int price;
}Car;

int main(void){

    Car cars[] = {{"BMW", 2019, 89000}, 
                  {"Mercedes", 2025, 120000}, 
                  {"Porsche", 2026, 540000}};
    
    int number = sizeof(cars) / sizeof(cars[0]);

    for (int i = 0; i < number; i++) {
        printf("%s  %d $%d\n", cars[i].model, cars[i].year, cars[i].price);
    }
    return 0;
}