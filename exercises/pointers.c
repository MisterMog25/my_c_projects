#include <stdio.h>
#include <stdlib.h>

// void birthday(int* age);

void mallocs(void);
void callocs(void);
void reallocs(void);

int main(void){

    // int age = 25;
    // int *pAge = &age;
    // int **anotherPointer = &pAge;

    // birthday(pAge);

    // printf("%d\n", age);
    // printf("Адреса age:             %p\n", pAge);
    // printf("Адреса pAge:            %p\n", anotherPointer);
    // printf("Адреса anotherPointer:  %p\n", &anotherPointer);

    
    // printf("%d\n", **anotherPointer);

    // FILE *pFile = fopen("output.txt", "w");

    // char text[] = "BOOTY BOOTY BOOTY\nROCKIN' EVERYWHERE!";

    // if(pFile == NULL){
    //     printf("Error opening file\n");
    //     return 1;
    // }

    // fprintf(pFile, "%s", text);

    // printf("File was successfuly written!");

    // fclose(pFile);

    // FILE *pFile = fopen("output.txt", "r");
    // char buffer[1024] = {0};

    // if (pFile == NULL){
    //     printf("Could not open file\n");
    //     return 1;
    // }

    // while(fgets(buffer, sizeof(buffer), pFile) != NULL){
    //     printf("%s", buffer);
    // }

    // fclose(pFile);

    mallocs();
    // callocs();
    // reallocs();

    return 0;
}

// void birthday(int* age){
//     (*age)++;
// }

// void mallocs(){
//     int number = 0;
//     printf("Enter the number of grades: ");
//     scanf("%d", &number);

//     char *grades = malloc(number * sizeof(char));

//     if (grades == NULL){
//         printf("Memory allocation failed!\n");
//         return;
//     }

//     for(int i = 0; i < number; i++){
//         printf("Enter grade #%d: ", i + 1);
//         scanf(" %c", &grades[i]);
//     }

//     for (int i = 0; i < number; i++){
//         printf("%c ", grades[i]);
//     }
//     printf("\n");
    

//     free(grades); // returning the "rented" space back to the OS
//     grades = NULL; // avoids dangling pointers
// }

// void callocs(){
//     int number = 0;
//     printf("Enter the number of players: ");
//     scanf("%d", &number);

//     int *scores = calloc(number, sizeof(int));

//     if(scores == NULL){
//         printf("Memory allocation failed!");
//         return;

//     }

//     for (int i = 0; i < number; i++){
//         printf("Enter score #%d: ", i + 1);
//         scanf("%d", &scores[i]);
//     }

//     for(int i = 0; i < number; i++){
//         printf("%d ", scores[i]);
//     }


//     printf("\n");

//     free(scores);
//     scores = NULL;
// }

// void reallocs(){

//     int number = 0;
//     printf("Enter the number of prices: ");
//     scanf("%d", &number);

//     float *prices = calloc(number, sizeof(float));

//     if (prices == NULL){
//         printf("Error, can't be zero");
//         return;
//     }

//     for (int i = 0; i < number; i++){
//         printf("Enter the #%d price: ", i+1);
//         scanf("%f", &prices[i]);
//     }

//     for (int i = 0; i < number; i++){
//         printf("$%.2f ", prices[i]);
//     }
//     printf("\n");

// }

void mallocs(void) {
    int number = 0;
    printf("Enter the amount of numbers you want to insert: ");
    scanf("%d", &number);

    // float prices[40] = {0};

    float *prices = malloc(number * sizeof(float));

    if (prices == NULL){
        printf("Invalid memory allocation!\n");
        return;
    }

    for (int i = 0; i < number; i++){
        printf("Enter the #%d number: ", i+1);
        scanf("%f", &prices[i]);
    }

    int newNumber = 0;
    printf("Enter a new number of prices: ");
    scanf("%d", &newNumber);

    float *temp = realloc(prices, newNumber*sizeof(float));

    if (temp == NULL){
        printf("Could not reallocate memory\n");
    }
    else{
        prices = temp;
        temp = NULL;

        for (int i = number; i < newNumber; i++){
            printf("Enter the #%d number: ", i+1);
            scanf("%f", &prices[i]);
        }

        for (int i = 0; i < newNumber; i++){
            printf("$%.2f ", prices[i]);
        }
    }


    printf("\n");

    free(prices);
    prices = NULL;
}



//newshit
// #include <stdio.h>
// #include <stdlib.h>

// void countdown(int n, int *results) {
//     printf("--> Entering countdown(%d)\n", n);

//     results[n - 1] = n;   // write into the shared heap array

//     if (n > 1) {
//         countdown(n - 1, results);   // recursive call
//     }

//     printf("<-- Leaving countdown(%d)\n", n);
//     return;
// }
 
// int main(void) {
//     int total = 3;
//     int *results = malloc(total * sizeof(int));  // ONE heap block

//     if (results == NULL) return 1;

//     countdown(total, results);

//     for (int i = 0; i < total; i++) {
//         printf("%d ", results[i]);
//     }
//     printf("\n");

//     free(results);
//     results = NULL;
//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// void arrgen(int number, int* array){

//     array[number - 1] = number;
//     printf("-->Getting inside #%d\n", number);

//     if (number > 1){
//         arrgen(number - 1, array);
//     }

//     printf("<--Leaving out #%d\n", number);
//     return;
// }

// int main(void){
//     int number = 5;

//     int *rArray = malloc(number * sizeof(rArray));

//     arrgen(number, rArray);

//     for(int i = 0; i < number; i++){
//         printf("%d ", rArray[i]);
//     }
//     printf("\n");

//     free(rArray);
//     rArray = NULL;


//     return 0;
// }

