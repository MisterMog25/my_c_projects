#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void print_grid(int g[][4], int rows) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < 4; c++) printf("%d ", g[r][c]);
        printf("\n");
    }
    
}

bool erase_middle(int *nums, int *size, int num) {
    for (int i = 0; i < *size; i++) {
        if (num == nums[i]) {
            memmove(&nums[i], &nums[i + 1], (*size - (i + 1)) * sizeof(int));
            (*size)--;
            return true;
        }
    }
    return false;

}
// {1, 2, 3, 4, 5}

int main(void) {
    // int grid[3][4] = {0};
    // grid[1][2] = 9;
    // print_grid(grid, 3);


    // int numbers[] = {1, 2, 3, 4, 5};
    // int size = sizeof(numbers) / sizeof(numbers[0]);

    // if (erase_middle(numbers, &size, 4)) {
    //     printf("cool vas\n");
    //     for (int i = 0; i < size; i++) printf("%d ", numbers[i]);
    // }


    char dst[16] = "Hello, ";
    snprintf(dst + strlen(dst), sizeof dst - strlen(dst), "%s", "!!");
    printf("%s\n", dst);
    return 0;
    
}

