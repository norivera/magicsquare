#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool checkMagicSquare(int array[][3]) 
{

    int sumD1 = 0;
    int sumD2 = 0;
    for (int i = 0; i < 3; i++)
    {
        sumD1 += array[i][i];
    }
    for (int i = 2; i >= 0; i--)
    {
        sumD2 += array[i][i];
        printf("\n%d",sumD2);
    }
    if (sumD1 != sumD2)
    {
        return false;
    }


    for (int i = 0; i < 3; i++)
    {
        int rowSum = 0;
        int columnSum = 0;

        for (int j = 0; j < 3; j++)
        {
            rowSum += array[i][j];
            columnSum += array[j][i];
        }

        if (rowSum != columnSum || columnSum != sumD1)
        {
            return false;
        }
    }


    return true;


}

int fisherYates()
{
    int staticArray[] = {1,2,3,4,5,6,7,8,9};
    int array[3][3] = {0};
    int x, temp;
    int attempt = 1;

    do {
        printf("\nAttempt %d:\n", attempt);
        int index = 0;
        for (int i = 0; i < 9; i++)
        {
            x = (rand() % 9) + 1;

            temp = staticArray[i];
            staticArray[i] = staticArray[x];
            staticArray[x] = temp;
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0;j < 3; j++)
            {
                array[i][j] = staticArray[index];
                index++;
                printf("%d", array[i][j]);
            }
            printf("\n");
        }
        attempt++;
        printf("\n%d",checkMagicSquare(array));

    }  
    while (!checkMagicSquare(array));
        printf("\n");
}



int main()
 {
    time_t t;
    srand((unsigned) time(&t));

    int array[3][3] = { {4, 9, 2} , {3, 5, 7} , {8, 1, 6} };

    printf("%d",checkMagicSquare(array));
    fisherYates();

}