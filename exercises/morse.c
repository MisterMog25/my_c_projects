#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void code(char *word);
void decode(char *word);

const char *latin = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *morse_letters[] = {
    ".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",  "....", "..",   // A-I
    ".---", "-.-",  ".-..", "--",   "-.",   "---",  ".--.", "--.-", ".-.",  // J-R
    "...",  "-",    "..-",  "...-", ".--",  "-..-", "-.--", "--.."          // S-Z
};
const char *numbers = "123456789";
const char *morse_numbers[] = {
    "-----", // 0
    ".----", // 1
    "..---", // 2
    "...--", // 3
    "....-", // 4
    ".....", // 5
    "-....", // 6
    "--...", // 7
    "---..", // 8
    "----."  // 9
};

int main(void){

    char word[100] = "";
    int choice = 0;

    while (true) {
        printf("Choose the option: 1 - code 2 - decode 3 - exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Please, enter the word: ");
                getchar();
                fgets(word, sizeof(word), stdin);
                word[strlen(word) - 1] = '\0';

                code(word);
                break;
            case 2:
                printf("Please, enter the morse - code: ");
                getchar();
                fgets(word, sizeof(word), stdin);
                word[strlen(word) - 1] = '\0';

                decode(word);
                break;
            case 3:
                printf("bye!\n");
                return 0;
        }
    }



    return 0;
}

void code(char *word) {

    for (int i = 0; word[i] != '\0'; i++){
        char c = toupper(word[i]);

        if (c >= 'A' && c <= 'Z') {
            int index = c - 'A';
            printf("%s ", morse_letters[index]);
        } else if (c == ' ') {
            printf("/ ");
        } else if (isdigit(c)) {
            int num = c - '0';
            printf("%s ", morse_numbers[num]);
        }
    }
    printf("\n");
}

void print_decoded_token(const char *buf) {
    if (buf[0] == '\0') return;

    for (int j = 0; j < 26; j++) {
        if (strcmp(buf, morse_letters[j]) == 0) {
            printf("%c", latin[j]);
            return;
        }
    }

    for (int j = 0; j < 10; j++) {
        if (strcmp(buf, morse_numbers[j]) == 0) {
            printf("%d", j);
            return;
        }
    }
}

void decode(char *word) {
    char buf[16] = "";
    int buf_len = 0;

    for (int i = 0; word[i] != '\0'; i++) {
        char c = word[i];
        if (c == ' ') {
            print_decoded_token(buf);
            buf[0] = '\0';
            buf_len = 0;
        } else {
            if (buf_len < sizeof(buf) - 1) {
                buf[buf_len++] = c;
                buf[buf_len] = '\0';
            }
        }
        
    }
    print_decoded_token(buf);
    printf("\n");
}