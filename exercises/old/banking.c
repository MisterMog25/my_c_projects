#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>
#include "math_utils.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>

void checkBalance(float balance);
float deposit();
float withdraw(float balance);


int main() {

    int choice = 0;
    float balance = 0.0f;

    printf("*** WELCOME TO THE BANK ***");

    do{
        printf("\nSelect an option:\n1. Check Balance\n2. Deposit\n3. Withdraw Money\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance += deposit();
                break;
            case 3:
                balance -= withdraw(balance);
                break;
            case 4:
                printf("\nThank you for using the bank!\n");
                break;
            default:
                printf("\n Invalid option! Please select 1-4\n");
        }       

    } while(choice != 4); 



    return 0;

}

void checkBalance(float balance){
    printf("\nYour balance is: $%.2f", balance);
}

float deposit(){
    float amount = 0.0f;

    printf("How many $ do you want to deposit?: ");
    scanf("%f", &amount);

    if (amount < 0) {
        printf("Invalid amount\n");
        return 0.0f;
    }
    else {
        printf("Successfully deposited $%.2f!\n", amount);
    }
    return amount;
}

float withdraw(float balance) {
    float amount = 0.0f;
    printf("How many $ do you want to withdraw?: ");
    scanf("%f", &amount);

    if (amount > balance) {
        printf("Amount can't be higher than current balance!\n");
        return 0.0f;
    } else{
        printf("Successfully withdrawn $%.2f!", amount);
    }
    return amount;

}