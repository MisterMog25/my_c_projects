#include <stdio.h>
#include <stdbool.h>
// #include "math_utils.h"
#include <string.h>
// #include <math.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <time.h>

// int result = 0; // GLOBAL VARS

// void hello(char name[], int age);
// bool ageCheck(int age);

typedef struct {
    char name[50];
    int age;
    float gpa;
    bool isFullTime;
}Student;

void printStudent(Student student);

int main(void){

    Student student1 = {"Bastard", 24, 2.5, true};
    Student student2 = {0};

    strcpy(student2.name, "Sandy");
    student2.age = 12;
    student2.gpa = 3.4;
    student2.isFullTime = false;

    printStudent(student2);


//     hello("SpongeBob", 14);

//     if (ageCheck(14)){
//         printf("You are old enougth to work at the crusty Krab\n");

//     }
//     else{
//         printf("You must be 16+ to work there\n");
//     }

    return 0;
}

void printStudent(Student student){
    printf("%s\n", student.name);
    printf("%d\n", student.age);
    printf("%.2f\n", student.gpa);
    printf("%s\n", student.isFullTime ? "Is full time" : "Is part time");
    printf("\n");
}

// void hello(char name[], int age){
//     printf("Hello %s\n", name);
//     printf("You are %d years old\n", age);
// }

// bool ageCheck(int age) {
//     return age >= 16;
// }

// int getComputerChoice();
// int getUserChoice();
// void checkWinner(int userChoice, int computerChoice);


// int main(){

    // int number= 5;

    // while(number <= 0){
    //     printf("enter a number greater than 0: ");
    //     scanf("%d",  &number);
    // }

    
    // do{
    //     printf("enter a number greater than 0: ");
    //     scanf("%d",  &number);
    // }while(number <= 0);

    // char name[50] = "";


    // do{
    //     printf("Enter your name: ");
    //     fgets(name, sizeof(name), stdin);
    //     name[strlen(name) - 1] = '\0';
    // }  while(strlen(name) == 0);
    
    // printf("%s\n", name);

    // bool isRunning = true;
    // char response = '\0';

    // while (isRunning){
    //     printf("You are playing a game\n");
    //     printf("Would you like to continue? (Y = yes, N = no): ");
    //     scanf(" %c", &response); 

    //     if (response != 'Y' && response != 'y') {
    //         isRunning = false;
    //     }
    // }
    // printf("You exit the game!\n");

    // FOR LOOPS: 
    // for(INITIALIZATION; CONDITION; UPDATE)

    // for(int i = 10; i >= 0; i--) {
    //     printf("%d\n", i);
    //     sleep(1);
    // }

    // printf("HAPPY NEW YEAR!!!\n");

    // for(int i = 1; i <= 10; i++){

    //     if (i == 4) {
    //         continue;
    //     }

    //     printf("%d\n", i);
    // }

    // for (int i = 1; i <= 10; i++) {
    //     for (int j = 1; j<= 10; j++){
    //         printf("%3d ", j*i);
    //     }
    //     printf("\n");
    // }

    // int rows = 0;
    // int columns = 0;
    // char symb = '\0';

    // printf("How many rows you want: ");
    // scanf("%d", &rows);

    // printf("How many columns you want: ");
    // scanf("%d", &columns);

    // printf("Symbol: ");
    // scanf(" %c", &symb);

    // for (int i = 1; i <= rows; i++){
    //     for (int j = 1; j <= columns; j++){
    //         printf("%c", symb);
    //     }
    //     printf("\n");
    // }

    // srand(time(NULL));

    // int min = 50;
    // int max = 100;

    // int randomNum1 = (rand() % (max - min + 1)) + min;
    // int randomNum2 = (rand() % (max - min + 1)) + min;
    // int randomNum3 = (rand() % (max - min + 1)) + min;

    // printf("%d %d %d\n", randomNum1, randomNum2, randomNum3);

    // printf("Welcome to the number guessing game!\n");
    // int choice = 0;
    // srand(time(NULL));

    // int min = 0;
    // int max = 100;

    // int randomNum = (rand() % (max - min + 1)) + min;

    // while (true) {
    //     printf("Guess a number between 1 - 100: ");
    //     scanf("%d", &choice);

    //     if (choice < 0 || choice > 100) {
    //         printf("incorrect input, try again\n");
    //         continue;
    //     } 
    //     else if (choice < randomNum) {
    //         printf("TOO LOW!\n");
    //     }
    //     else if (choice > randomNum) {
    //         printf("TOO HIGH!\n");
    //     } else{
    //         printf("Correct! ");
    //         printf("The answer is %d\n", randomNum);
    //         break;
    //     }
    // }

    // printf("*** ROCK PAPER SCISSORS ***\n");
    // int userChoice = getUserChoice();
    // int computerChoice = getComputerChoice();

    // if (userChoice == 1) {
    //     printf("You chose ROCK!\n");
    // } else if (userChoice == 2) {
    //     printf("You chose PAPER!\n");
    // } else{
    //     printf("You chose SCISSORS!\n");
    // }

    // if (computerChoice == 1) {
    //     printf("computer chose ROCK!\n");
    // } else if (computerChoice == 2) {
    //     printf("computer chose PAPER!\n");
    // } else{
    //     printf("computer chose SCISSORS!\n");
    // }

    // checkWinner(userChoice, computerChoice);




//     return 0;
// }

// int getUserChoice(void){
//     printf("Choose an option\n1. ROCK\n2. PAPER\n3. SCISSORS\n");
//     int choice = 0;
//     printf("Enter your choice: ");
//     scanf("%d", &choice);

//     return choice;
// }

// int getComputerChoice(void){
//     int min = 1;
//     int max = 3;

//     srand(time(NULL));
//     int randomNum = (rand() % (max - min + 1)) + min;

//     return randomNum;
// }

// void checkWinner(int userChoice, int computerChoice) {
//     if ((userChoice == 1 && computerChoice == 2) || (userChoice == 2 && computerChoice == 3) || (userChoice == 3 && computerChoice == 1)) {
//         printf("You LOSE!!!\n");
//     } else  if (userChoice == computerChoice){
//         printf("draw bruh\n");
//     } else{
//         printf("You WIN!!!!\n");
//     }
// }
