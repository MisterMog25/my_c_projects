#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
// #include <unistd.h>

bool load_random_word(const char *path, char *out, size_t size);


int main(void){
    int tries = 5;
    char word[50] = "";
    const char *path = "words.txt";
    char availableLetters[] = "qwertyuiopasdfghjklzxcvbnm";
    char choice = '\0';

    srand(time(NULL));
    
    if (!randomWord(path, word, sizeof(word))) {
        fprintf(stderr, "Could not load a word from %s\n", path);
        return 1;
    };

    size_t len = strlen(word);

    // answer secret _____
    char secret[len + 1];
    memset(secret, '_', len);
    secret[len] = '\0';

    printf("*** HANGMAN GAME ***\n");

    while (true) {
        printf("\nSecret word: %s\n", secret);
        printf("Remaining Attempts: %d\n", tries);
        printf("\navailable letters: %s\n", availableLetters);
        printf("Enter a letter: ");
        scanf(" %c", &choice);
        choice = tolower((unsigned char)choice);

        char *ptr = strchr(availableLetters, choice);

        if (ptr == NULL) {
            printf("Invalid or already used!\n");
            continue;
        }
        memmove(ptr, ptr + 1, strlen(ptr)); 

        // switcher if letter is in the word
        bool hit = false;

        for (size_t i = 0; i < len; i++){
            if (word[i] == choice) {
                secret[i] = choice;
                hit = true;
            }
            
        }

        if (!hit) {
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
    }

    return 0;
}

bool load_random_word(const char *path, char *out, size_t size) {

    FILE *f = fopen(path, "r");
    if (f == NULL) {
        return false;
    }

    int count = 0;
    char temp[256];

    while (fgets(temp, sizeof(temp), f) != NULL){

        temp[strcspn(temp, "\r\n")] = '\0';
        if (temp[0] == '\0') continue;
        count++;
    }

    if (count == 0){
        fclose(f);
        return false;
    }

    rewind(f);

    int targetIndex = rand() % count;

    for (int i = 0; i <= targetIndex; i++) {
        if (fgets(temp, sizeof(temp), f) == NULL) {
            fclose(f);
            return false;
        }
        snprintf(out, size, "%s", temp);
    }

    out[strcspn(out, "\r\n")] = '\0';
    for (size_t i = 0; out[i]; i++) out[i] = tolower((unsigned char)out[i]);

    fclosef(f);
    return true;
}
