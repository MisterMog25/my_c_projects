#include <stdio.h>
#include <stdbool.h>
#include "math_utils.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>



// void happyBirthday(){
//     printf("Hello markus barkus!!!\n");
// }

// typedef int Number;
// typedef char String[50];
// typedef char Initials[3];

// typedef enum{
//     SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
// }Day;

enum Status {
    SUCCESS, FAILURE, PENDING
};
void connectStatus(enum Status status);

int main(void) {
    // Day today = MONDAY;

    // if(today == SUNDAY || today == SATURDAY) {
    //     printf("It's the weekend\n");
    // } else{
    //     printf("It's the weekday\n");
    // }
    enum Status status = FAILURE;

    connectStatus(status);




    // this is my first program!!

    /*
    this is
    also
    as
    comment
    */

    // int sum = 10;
    // printf("the count is %d\n", sum);
    // printf("i like pizza!\n");

    // int age = 25;
    // int year = 2026;

    // printf("You are %d\n", age);
    // printf("The year is %d\n", year);

    // float gpa = 2.5;
    // float price = 19.99;
    // printf("Your gpa is %.1f\n", gpa);
    // printf("The price is: %f\n", price);

    // double pi = 3.14159265358979;
    // printf("The value of pi is %.15lf\n", pi);

    // char grade = 'A';
    // char symbol = '!';
    // printf("Your grade is: %c\n", grade);
    // printf("your favorite symbol is: %c\n", symbol);

    // char name[] = "Markus Barkus";
    // char food[] = "pizza";
    // printf("Hello %s\n", name);
    // printf("Your favorite food is %s\n", food);

    // bool isOnline = 0;

    // if (isOnline) {
    //     printf("You are online\n");
    // } else {
    //     printf("Offline\n");
    // }

    // format specifiers

    // int age = 25;
    // float price = 19.99;
    // double pi = 3.1415926535;
    // char currency = '$';
    // char name[] = "Bro Code";

    // printf("%d\n", age);
    // printf("%f\n", price);
    // printf("%lf\n", pi);
    // printf("%c\n", currency);
    // printf("%s\n", name);

    // int num1 = 1;
    // int num2 = 10;
    // int num3 = -100;

    // printf("%+04d\n", num1);
    // printf("%+04d\n", num2);
    // printf("%+04d\n", num3);

    // float price1 = 19.99;
    // float price2 = 1.50;
    // float price3 = -100.00;

    // printf("%7.2f\n", price1);
    // printf("%7.2f\n", price2);
    // printf("%7.2f\n", price3);

    // int x = 7;
    // // float y = 3;
    // // float z = 0;
    // int y = 10;
    // int z = 0;

    // z = x + y;
    // z = z - y * 2;
    // z = x * y;
    // z = x / y;
    // z = x % y;

    // x *= 2;
    // printf("%d\n", x);

    // int age = 0;
    // float gpa = 0.0f;
    // char grade = '\0'; 
    // char name[30] = "";

    // printf("Enter your age: ");
    // scanf("%d", &age);

    // printf("Enter your gpa: ");
    // scanf("%f", &gpa);

    // printf("Enter your grade: ");
    // scanf(" %c", &grade);

    // getchar();
    // printf("Enter your name: ");
    // fgets(name, sizeof(name), stdin);
    // name[strlen(name) - 1] = '/0';


    // printf("%s\n", name);
    // printf("%d\n", age);
    // printf("%.2f\n", gpa);
    // printf("%c\n", grade);

    // char adjective1[50] = "";
    // char noun[50] = "";
    // char verb[50] = "";
    // char adjective2[50] = "";
    // char adjective3[50] = "";

    // printf("Enter an adjective (description): ");
    // fgets(adjective1, sizeof(adjective1), stdin);
    // adjective1[strlen(adjective1)-1] = '\0';

    // printf("Enter a noun (animal or person): ");
    // fgets(noun, sizeof(noun), stdin);
    // noun[strlen(noun)-1] = '\0';

    // printf("Enter an adjective (description): ");
    // fgets(adjective2, sizeof(adjective2), stdin);
    // adjective2[strlen(adjective2)-1] = '\0';

    // printf("Enter a verb (ending w/ -ing): ");
    // fgets(verb, sizeof(verb), stdin);
    // verb[strlen(verb)-1] = '\0';

    // printf("Enter an adjective (description): ");
    // fgets(adjective3, sizeof(adjective3), stdin);
    // adjective3[strlen(adjective3)-1] = '\0';

    // printf("\nToday the %s celebrated the first KirkVersary\n", noun);
    // printf("At the party he was %s\n", verb);
    // printf("He looked %s\n", adjective1);
    // printf("After a %s lady proposed him to sit with her, he kindly denied because of fear\n", adjective2);
    // printf("In the end, everyone %s started drinking coke\n", adjective3);

    // char sumer[50] = "";
    // printf("Put smth in here: ");
    // fgets(sumer, sizeof(sumer), stdin);
    // sumer[strlen(sumer) - 1] = '\0';

    // printf("%s\n", sumer);

    // MATH

    // float x = 45;

    // // x = sqrt(x);
    // // x = pow(x, 4);
    // //x = round(x);
    // //x = ceil(x);
    // //x = floor(x);

    // //x = abs(x);
    // //x = log(x);
    // x = sin(x);

    // printf("%f\n", x);

    // double radius = 0.0;
    // double area = 0.0;
    // double surfaceArea = 0.0;
    // double volume = 0.0;
    // const double PI = 3.14159;

    // printf("Enter the radius: ");
    // scanf("%lf", &radius);

    // area = PI * pow(radius, 2);
    // surfaceArea = 4 * PI * pow(radius, 2);
    // volume = (4.0 / 3.0) * PI * pow(radius, 3);

    // printf("Area: %.2lf\n", area);
    // printf("Suface Area: %.2lf\n", surfaceArea);
    // printf("Volume: %.2lf\n", volume);

    // double principal = 0.0;
    // double rate = 0.0;
    // int years = 0;
    // int timesCompounded = 0;
    // double total = 0.0;

    // printf("Enter the principal: ");
    // scanf("%lf", &principal);

    // printf("Enter the rate: ");
    // scanf("%lf", &rate);

    // printf("Enter the years: ");
    // scanf("%d", &years);

    // printf("Enter timesCompounded: ");
    // scanf("%d", &timesCompounded);

    // total = principal * pow((1 + rate / timesCompounded), 1*years);

    // printf("The total is: %.2lf\n", total);

    // int age = 0;

    // printf("Enter your age: ");
    // scanf("%d", &age);

    // if (age >= 18 && age < 65){
    //     printf("You are an adult\n");
    // }
    // else if (age >= 65){
    //     printf("You are a senior\n");
    // }
    // else if (age < 0) {
    //     printf("You haven't been born yet :(\n");
    // }
    // else if (age == 0) {
    //     printf("You are a newborn\n");
    // }
    // else{
    //     printf("You are a child\n");
    // }
    
    // bool isStudent = true;
    // if (isStudent) {
    //     printf("You are a student\n");
    // }
    // else {
    //     printf("You are NOT a student\n");
    // }

    // char name[50] = "";

    // printf("Enter your name: ");
    // fgets(name, sizeof(name), stdin);
    // name[strlen(name) - 1] = '\0';

    // if (strlen(name) == 0) {
    //     printf("You did not enter your name\n");
    // } 
    // else{
    //     printf("Hello %s", name);
    // }

    // int choice = 0;
    // float pounds = 0.0f;
    // float kilograms = 0.0f;

    // printf("Weight Coversion Calculator\n");
    // printf("1. Kilograms to Pounds\n2. Pounds to Kilograms\n");
    // printf("Enter your choice (1 or 2): ");
    // scanf("%d", &choice);

    // if(choice == 1){
    //     printf("Enter the weight in kilos: ");
    //     scanf("%f", &kilograms);
    //     pounds = kilograms * 2.20462;
    //     printf("The %.2f kilos in lbs will be: %.2f lbs\n", kilograms, pounds);
    // }
    // else if (choice == 2){
    //     printf("Enter the weight in pounds: ");
    //     scanf("%f", &pounds);
    //     kilograms = pounds  / 2.20462;
    //     printf("%.2f lbs in kilos will be: %.2f kg\n", pounds, kilograms);
    // }
    // else {
    //     printf("Invalid choice! Please enter 1 or 2\n");
    // }

    // char dayOfWeek = '\0';
    // printf("Please enter the day of the Week: ");
    // scanf("%c", &dayOfWeek);


    // switch(dayOfWeek){
    //     case 'M':
    //         printf("It is Monday\n");
    //         break;
    //     case 'T':
    //         printf("It is Tuesday\n");
    //         break;
    //     default:
    //         printf("Please only enter a number (1-7)\n");
        
    // }

    // float price = 10.00;
    // bool isStudent = true; // 10% discount
    // bool isSenior = false; // 20% discount

    // if (isStudent) {
    //     if(isSenior){
    //         printf("You get a student discount of 10%\n");
    //         printf("You get a senior discount of 20%\n");
    //         price *= 0.7;
    //     }
    //     else {
    //         printf("You get a student discount of 10%\n");
    //         price *= 0.9;
    //     }
    // }
    // else {
    //     if(isSenior){
    //         printf("You get a senior discount of 20%\n");
    //         price *= 0.8;
    //     }
    // }


    // printf("The price of a ticket is: $%.2f\n", price);

    // char operator = '\0';
    // double num1 = 0.0;
    // double num2 = 0.0;
    // double result = 0.0;

    // printf("Enter the first number: ");
    // scanf("%lf", &num1);

    // printf("Enter the operator (+ - * /): ");
    // scanf(" %c", &operator); 

    // printf("Enter the second number: ");
    // scanf("%lf", &num2);

    // switch (operator) {
    //     case '+':
    //         result = num1 + num2;
    //         break;
    //     case '-':
    //         result = num1 - num2;
    //         break;
    //     case '*':
    //         result = num1 * num2;
    //         break;
    //     case '/':
    //         if (num2 != 0) {
    //             result = num1 / num2;
    //         }
    //         else{
    //             printf("You can't divide by zero!");
    //         }
    //         break;
    //     default:
    //         printf("You entered an invalid operator\n");
    //         break;
    // }
    // printf("Result: %.4lf\n", result);

    // int temp = 344;

    // if (temp <= 0 || temp >= 30){
    //     printf("The temperature is bad!\n");
    // } 
    // else{
    //     printf("The temperature is good!\n");
    // }

    // bool isSunny = true;

    // if(!isSunny){
    //     printf("It is CLOUDY outside\n");
    // }
    // else{
    //     printf("It is SUNNY outside\n");
    // }

    // int numbers[] = {10, 20, 30, 40, 50};
    // char grades[] = {'A', 'B', 'C', 'D', 'F'};
    // char name[] = "Markus barkus!";

    // numbers[0] = 100;
    // numbers[2] = 90;
    // numbers[3] = 70;
    // numbers[4] = 60;


    // printf("%d\n", numbers[0]);
    // printf("%d\n", numbers[1]);
    // printf("%d\n", numbers[2]);
    // printf("%d\n", numbers[3]);
    // printf("%d\n", numbers[4]);
    // int num = strlen(name);

    // for (int i = 0; i < num+1; i++){
    //     printf("%c", name[i]);
    // }

    // int size = sizeof(numbers) / sizeof(numbers[0]);

    // for (int i = 0; i < size; i++){
    //     printf("%d ", numbers[i]);
    // }

    // int scores[5] = {0};

    
    
    // for(int i = 0; i < 5; i++){
    //     printf("Enter a score: ");
    //     scanf("%d", &scores[i]);
    // }

    // for(int i = 0; i < 5; i++){
    //     printf("%d ", scores[i]);
    // }
    
    // printf("\n");

    // int numbers[][3] = {{1,2,3}, {4, 5, 6}, {7, 8, 9}};


    // for(int i = 0; i < sizeof(numbers) / 12; i++) {
    //     for(int j = 0; j < sizeof(numbers) / 12; j++){
    //         printf("%d ", numbers[i][j]);
    //     }
    //     printf("\n");
    // }

    // char fruits[][10] = {"Apple", "Bananas", "Coconut", "Pineapple"};
    // int size = sizeof(fruits) / sizeof(fruits[0]);



    // fruits[0][0] = 'e';
    // fruits[0][4] = 'A';

    // for(int i = 0; i < 3; i++){
    //     printf("%s\n", fruits[i]);
    // }

    // char name[3][25] = {0};

    // int size = sizeof(name) / sizeof(name[0]);

    // for(int i = 0; i < size; i++) {
    //     printf("Enter a name: ");
    //     fgets(name[i], sizeof(name[i]), stdin);
    //     name[i][strlen(name[i]) - 1] = '\0';
    // }

    // for (int i = 0; i < sizeof(name) / sizeof(name[0]); i++) {
    //     printf("%s\n", name[i]);
    // }

    // char questions[][100] = {"What year did spain win the WC in?", 
    //                         "Who is the best footballer OAT?",
    //                         "What planet has the most moons?",
    //                         "What object can be awaitable in python asyncio?"};

    // char options[][100] = {"A. 1234\nB. 2345\nC. 2026\nD. 1990",
    //                         "A. Ronaldo\nB. CRisto ronaldo\nC. Niggerus\nD. Mars",
    //                         "A. Earth\nB. Mark\nC. Jupiter\nD. Saturn",
    //                         "A. def functions\nB. Futures\nC. Lambdas\nD. Generators"};

    // char answerKey[] = {'C', 'B', 'D', 'B'};
    // int questionCount = sizeof(questions) / sizeof(questions[0]);

    // char guess = '\0';
    // int score = 0;

    // printf("*** QUIZ GAME ***");
    // for (int i = 0; i < questionCount; i++){
    //     printf("\n%s\n", questions[i]);
    //     printf("\n%s\n", options[i]);

    //     printf("\nEnter your choice: ");
    //     scanf(" %c", &guess);

    //     guess = toupper(guess);

    //     if (guess == answerKey[i]) {
    //         score++;
    //         printf("Correct!\n");
    //     } else {
    //         printf("Wrong!\n");
    //     }
    // }

    // printf("\nGAME FINISHED!\nYour final score is %d/%d!\n", score, questionCount);


    // int hours = 23;
    // int minutes = 3;
    // char *meridiem = (hours < 12) ? "AM" : "PM";

    // printf("%02d:%02d %s\n", hours, minutes, meridiem);

    // Number x = 3;
    // Number y = 4;
    // Number z = x + y;
    // String name = "BroCode";

    // Initials user1 = "BC";
    // Initials user2 = "SS";
    // Initials user3 = "PS";
    // Initials user4 = "ST";

    // printf("%s\n", user1);
    // printf("%s\n", user2);
    // printf("%s\n", user3);
    // printf("%s\n", user4);



    return 0;
}

void connectStatus(enum Status status){
    switch(status){
        case SUCCESS:
            printf("Connection was SUCCESSFUL\n");
            break;
        case FAILURE:
            printf("Connection was FAILED\n");
            break;
        case PENDING:
            printf("Connection IS PENDING\n");
            break;
    }
}


