#include <stdio.h>
#include <string.h>

int main(){
    printf("Hello world\n");

    char numbers[30];
    printf("type some text-o: ");
    fgets(numbers, sizeof(numbers), stdin);

    char *p = numbers;

    // printf("%c\n", p[7]);
    // p[7] = *(p + 7);

    while (*p) {
        while (*p == ' ') p++;
        printf("%c\n", p[0]);
    }
    

    printf("%d\n", strcspn(numbers, "\n"));
    return 0;
}