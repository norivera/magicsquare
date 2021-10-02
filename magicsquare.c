#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

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

bool checkMagicSquare(int array[][3]) {
    if (sumColumn(array) == 15 && sumRow(array) == 15 && sumDiagonalOne(array) == 15 && sumDiagonalTwo(array) == 15) {
        return true;
    } else {
        return false;
    }
}

int fisherYates() {
    int staticArray[] = {1,2,3,4,5,6,7,8,9};
    int array[3][3];
    int x, temp;
    int attempt = 0;

    do {
        int index = 0;
        for (int i = 0; i < 9; i++) {
            x = (rand() % 9) + 1;

            temp = staticArray[i];
            staticArray[i] = staticArray[x];
            staticArray[x] = temp;
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0;j < 3; j++) {
                array[i][j] = staticArray[index];
                index++;

                printf("%d", array[i][j]);
            }
            printf("\n");
        }
        attempt++;
        printf("\nAttempt %d:\n", attempt);
    } while(!checkMagicSquare(array));




}



int main() {
    time_t t;
    srand((unsigned) time(&t));

    int array[3][3] = { {4, 9, 2} , {3, 5, 7} , {8, 1, 6} };

    //printf("%d", sumRow(array));
    //printf("\n%d", sumColumn(array));
    //printf("\n%d", sumDiagonalTwo(array));
    //checkMagicSquare(array);
    fisherYates();

}