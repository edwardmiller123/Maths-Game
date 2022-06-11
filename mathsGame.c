#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char start;
    int difficulty, maxNum;
    while (difficulty != 1 && difficulty != 2 && difficulty != 3)
    {
        printf("Choose difficulty:\n 1: Easy\n 2: Medium\n 3: hard\n");
        scanf("%i", &difficulty);
    }
    while (start != 's')
    {
        printf("Press s to start\n");
        scanf("%c", &start);
    }

    switch (difficulty)
    {
    case 1:
        maxNum = 6;
        break;
    case 2:
        maxNum = 11;
        break;
    case 3:
        maxNum = 21;
        break;
    }
    int t_start = clock();
    int i = 0;
    while (i < 10)
    {
        int num1, num2, answer;
        srand(time(0));
        num1 = rand() % maxNum;
        num2 = rand() % maxNum;
        printf("%i + %i = ? \n", num1, num2);
        scanf("%i", &answer);
        if (num1 + num2 == answer)
        {
            i++;
        }
        else
        {
            printf("Game Over");
            return;
        }
    }
    int t_end = clock();
    int t_total = (t_end - t_start);
    printf("Game Finished.\n Your time was %i", t_total);
}