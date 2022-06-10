#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    char start;
    while (start != 's') {
        printf("Press s to start\n");
        scanf("%c", &start);
    }
    int t_start = clock();
    int i = 0;
    while (i < 10) {
        int num1, num2, answer;
        srand(time(0));
        num1 = rand() % 11;
        num2 = rand() % 11;
        printf("%i + %i = ? \n", num1, num2);
        scanf("%i", &answer);
        if (num1 + num2 == answer) {
           i++; 
        } else {
            printf("Game Over");
            return;
        }

    }
    int t_end = clock();
    int t_total = (t_end - t_start);
    printf("Game Finished. Your time was %i", t_total);
}