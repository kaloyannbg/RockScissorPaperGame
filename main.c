#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RAND 3
#define ONE 1
#define CLEAR_SCREEN system("clear");
#define PAUSE_SCREEN system("pause");

enum EWin
{
    pcWin = -1,
    noOneWin,
    userWin
};

enum ERockScissorPaper
{
    Quit,
    Rock,
    Sci,
    Paper
};

typedef enum EWin win_t;

typedef enum ERockScissorPaper rsp_t;

typedef int num;

int isWin(rsp_t userChoice, rsp_t pcChoice)
{
    if (userChoice == Rock && pcChoice == Sci)
    {
        return userWin; // User wins
    }
    else if (userChoice == Rock && pcChoice == Paper)
    {
        return pcWin; // PC wins
    }
    else if (userChoice == Rock && pcChoice == Rock)
    {
        return noOneWin; // No one win, equality
    }

    if (userChoice == Sci && pcChoice == Sci)
    {
        return noOneWin; // Equality, no one wins
    }
    else if (userChoice == Sci && pcChoice == Rock)
    {
        return pcWin; // PC wins
    }
    else if (userChoice == Sci && pcChoice == Paper)
    {
        return userWin; // User Win
    }

    if (userChoice == Paper && pcChoice == Paper)
    {
        return noOneWin;
    }
    else if (userChoice == Paper && pcChoice == Sci)
    {
        return pcWin;
    }
    else if (userChoice == Paper && pcChoice == Rock)
    {
        return userWin;
    }
}

void printWinnerAndSavePoints(win_t winner, rsp_t userChoice, rsp_t pcChoice, num *userPoints, num *pcPoints, num *equality)
{
    printf(" -- User Choice: ");
    if (userChoice == Rock)
    {
        printf("Rock");
    }
    else if (userChoice == Sci)
    {
        printf("Scissor");
    }
    else if (userChoice == Paper)
    {
        printf("Paper");
    }

    printf(" <-> PC Choice: ");

    if (pcChoice == Rock)
    {
        printf("Rock");
    }
    else if (pcChoice == Sci)
    {
        printf("Scissor");
    }
    else if (pcChoice == Paper)
    {
        printf("Paper");
    }

    printf(" -- \n\n");

    if (winner == pcWin)
    {
        printf(" **PC Win!** ");
        ++(*pcPoints);
    }
    else if (winner == userWin)
    {
        printf(" **User Win!** ");
        ++(*userPoints);
    }
    else if (winner == noOneWin)
    {
        printf(" **No one win!** ");
        ++(*equality);
    }
}

int main(int argc, char const *argv[])
{

    srand(time(NULL));

    num iUserChoice = -1, iUserPoints = 0, iPcPoints = 0, iEquality = 0;

    while (iUserChoice != Quit)
    {
        CLEAR_SCREEN;
        printf("\n -- 1 - Rock, 2 - Scissor, 3 - Paper -- 0 Quit -- \n\n");
        printf(" -- User Points: %-5d | PC Points %-5d | Equality: %-5d \n\n", iUserPoints, iPcPoints, iEquality);
        printf(" -- Bro, please enter your choice: \n");
        scanf("%d", &iUserChoice);
        if (iUserChoice == Quit)
        {
            printf(" \n -- Bye -- \n");
            break;
        }
        num pcChoice = (rand() % MAX_RAND)+ONE;
        num iWinner = isWin(iUserChoice, pcChoice);
        printWinnerAndSavePoints(iWinner, iUserChoice, pcChoice, &iUserPoints, &iPcPoints, &iEquality);
        printf("\n");
        PAUSE_SCREEN;
        printf("\n\n");
    }

    return 0;
}
