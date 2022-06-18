#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
        scanf("%c", &start);
        printf("Press s to start\n");
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
            return printf("Incorrect Answer\nGame Over");
        }
    }
    int t_end = clock();
    // Timer depends on processor speed so not quite accurate.
    float t_total = (float)(t_end - t_start) / 1000;
    char *rating;
    if (t_total <= 10.0)
    {
        rating = "Gold";
    }
    else if (t_total <= 20.0)
    {
        rating = "Silver";
    }
    else
    {
        rating = "Bronze";
    }
    printf("Game Finished.\nYour time was %f seconds.\nRating: %s\n", t_total, rating);
    char saveScore[20];
    while (strcmp(saveScore, "yes") != 0 && strcmp(saveScore, "no") != 0)
    {
        printf("Would you like to save your time?\n");
        scanf("%s", saveScore);
    }
    if (strcmp(saveScore, "yes") == 0)
    {
        struct User
        {
            char name[20];
            char *difficultyOut;
            float time;
            char *ratingOut;
        };
        char *difficultyBadge;
        if (maxNum == 6)
        {
            difficultyBadge = "Easy";
        }
        else if (maxNum == 11)
        {
            difficultyBadge = "Medium";
        }
        else if (maxNum == 21)
        {
            difficultyBadge == "Hard";
        }
        printf("Enter your name\n");
        struct User user1 = {scanf("%s"), *difficultyBadge, t_total, *rating};
        FILE *file;
        file = fopen("Scoreboard.txt", "w");
        if (file == NULL)
        {
            fprintf(stderr, "\nError oppening file\n");
            exit(1);
        }
        fwrite(&user1, sizeof(struct User), 1, file);
        fclose(file);
    }
}