#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
// #include <unistd.h>

int randomNum(int min, int max);
bool randomWord(int num, char *word, size_t size, const char *path);


int main(void){
    int min = 1;
    int max = 5;
    int tries = 5;
    char word[50] = "";
    int num = 0;
    char path[] = "words.txt";
    bool isRunning = true;
    char availableLetters[] = "qwertyuiopasdfghjklzxcvbnm";
    char choice = '\0';
    bool isPartOf = false;
    

    srand(time(NULL));
    
    num = randomNum(min, max);
    if (!randomWord(num, word, sizeof(word), path)) {
        printf("Smth went wrong...\n");
        break;
    };
    size_t len = strlen(word);

    // answer secret _____
    char secret[len + 1];
    memset(secret, '_', len);
    secret[len] = '\0';

    printf("*** HANGMAN GAME ***\n");

    while (isRunning) {
        printf("\nSecret word: %s\n", secret);
        printf("Remaining Attempts: %d\n", tries);
        printf("\navailable letters: %s\n", availableLetters);
        printf("Enter a letter: ");
        scanf(" %c", &choice);

        if (strchr(availableLetters, tolower(choice)) == NULL){
            printf("This letter has been already used!\n");
            continue;
        }
        
        for (size_t i = 0; i < len; i++){
            if (tolower(choice) == word[i]) {
                secret[i] = tolower(choice);
                isPartOf = true;
            }
            
        }

        if (!isPartOf) {
            tries--;
            printf("Wrong guess!\n");
        }

        if (tries == 0) {
            printf("\nGame over, you lost((\n");
            break;
        } else if (strcmp(secret, word) == 0){
            printf("\nYou won, congrats!\n");
            printf("The word was, %s\n", word);
            break;
        }

        char *ptr = strchr(availableLetters, choice);

        if (ptr != NULL) {
            memmove(ptr, ptr+1, strlen(ptr));
        }
        isPartOf = false;

    }

    return 0;
}

int randomNum(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

bool randomWord(int num, char *word, size_t size, const char *path) {

    FILE *f = fopen(path, "r");
    if (f == NULL) {
        return false;
    }

    char line[1024] = {0};
    char temp[5][50] = {0};


    if (fgets(line, sizeof(line), f) != NULL) {
        line[strcspn(line, "\r\n")] = 0;

        int read_count = sscanf(line, "%49[^|]|%49[^|]|%49[^|]|%49[^|]|%49[^|]",
            temp[0], temp[1], temp[2], temp[3], temp[4]);

        if (read_count == 5 && num >= 1 && num <= 5) {
            snprintf(word, size, "%s", temp[num-1]);
            fclose(f);
            return true;
        }   
    }
    fclose(f);
    return false;
}
