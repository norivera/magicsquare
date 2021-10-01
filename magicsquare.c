#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sumRow(int array[][3]) {
    int value = 0;

    for (int i = 0; i < 3; i++) {
        value = 0;

        for (int j = 0; j < 3; j++) {
            value += array[i][j];
        }
    }
    return value;
}

int sumColumn(int array[][3]) {
    int value = 0;

    for (int j = 0; j < 3; j++) {
        value = 0;

        for (int i = 0; i < 3; i++) {
            value += array[i][j];
        }
    }

    return value;
}

int sumDiagonalOne(int array[][3]) {
    int value = 0;

    for (int i = 0; i < 3; i++) {
        value += array[i][i];
    }

    return value;
}

int sumDiagonalTwo(int array[][3]) {
    int value = 0;

    for (int i = 2; i >= 0; i--) {
        value += array[i][i];
    }

    return value;
}

void checkMagicSquare(int array[][3]) {
    if (sumColumn(array) == 15 && sumRow(array) == 15 && sumDiagonalOne(array) == 15 && sumDiagonalTwo(array) == 15) {
        printf("\nThe given array is Lo Shu Magic Square");
    } else {
        printf("\nThe given array is not Lo Shu Magic Sqauare");
    }
}

int main() {
    int array[3][3] = { {4, 9, 2} , {3, 5, 7} , {8, 1, 6} };

    printf("%d", sumRow(array));
    printf("\n%d", sumColumn(array));
    printf("\n%d", sumDiagonalTwo(array));
    checkMagicSquare(array);

    int test[3][3] = {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}};
    printf("\n%d", sumRow(test));
    printf("\n%d", sumColumn(test));
    printf("\n%d", sumDiagonalTwo(test));
    checkMagicSquare(test);

}