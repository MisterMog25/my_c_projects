#include <stdio.h>
#include <stdbool.h>
#include <string.h>
// #include <math.h>
#include <stdlib.h>
#include <time.h>
// #include <unistd.h>

int randomNum(int min, int max);
bool randomWord(int num, char *word, size_t size, const char *path);
#define MAX_WORDS 100

int main(){
    int min = 1;
    int max = 5;
    int tries = 6;
    char word[50] = "";
    int num = 0;
    char path[] = "words.txt";
    bool isRunning = true;
    

    srand(time(NULL));
    
    num = randomNum(min, max);
    if (!randomWord(num, word, sizeof(word), path)) {
        printf("Smth went wrong...\n");
        return 0;
    };
    size_t len = strlen(word);

    char secret[len + 1];
    memset(secret, '_', len);
    secret[len] = '\0';

    printf("%s\n", secret);


    printf("*** HANGMAN GAME ***\n");

    // while (isRunning) {

    // }

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
