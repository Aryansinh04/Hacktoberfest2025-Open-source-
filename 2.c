#include <stdio.h>
#include <stdlib.h>

// Function to get the minimum distance from border
int minDistance(int i, int j, int n) {
    int len = n * 2 - 1;
    int top = i;
    int left = j;
    int right = len - j - 1;
    int bottom = len - i - 1;

    int min = top;
    if (left < min) min = left;
    if (right < min) min = right;
    if (bottom < min) min = bottom;

    return min;
}

int main(void) {
    int n;

    printf("Enter the range of the pattern you want to print: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int size = n * 2 - 1;

    printf("\nThe pattern that will be displayed is:\n\n");

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int layer = minDistance(i, j, n);
            printf("%d ", n - layer);
        }
        printf("\n");
    }

    return 0;
}
