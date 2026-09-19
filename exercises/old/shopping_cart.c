#include <stdio.h>
#include <stdbool.h>
#include "math_utils.h"
#include <string.h>

int main(void) {
    // char name[30] = "";
    // float price = 0.0f;
    // float total = 0.0f;
    // int amount = 0;
    
    // printf("What item would you like to buy sir?: ");
    // fgets(name, sizeof(name), stdin);
    // name[strlen(name) - 1] = '\0';

    // printf("What is the price for each?: ");
    // scanf("%f", &price);

    // printf("How many would you like?: ");
    // scanf("%d", &amount);

    // total = multi(price, amount);

    // printf("You have bought %d %s/s\n", amount, name);
    // printf("The total is: $%.2f\n", total);

    float num1 = 5.3;
    int num2 = 3;
    float num = 0.0f;
    
    num = num1 / num2;

    printf("%f\n", num);
    return 0;

}