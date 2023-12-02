#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 1 - Rock
// 2 - Paper
// 3 - Scissors

void clearBuffer(){
    while(getchar() != '\n');
}

int getGameWinner(int *userChoice, int *computerChoice, int *score){
    // return 0 = player wins
    // return 1 = tie
    // return 2 = computer wins
    if (*userChoice == 1 && *computerChoice == 3){
        score[0]++;
        return 0;
    } else if (*userChoice == 2 && *computerChoice == 1){
        score[0]++;
        return 0;
    } else if (*userChoice == 3 && *computerChoice == 2){
        score[0]++;
        return 0;
    } else if (*userChoice == *computerChoice){
        score[1]++;
        return 1;
    } else {
        score[2]++;
        return 2;
    }
}

int getUserInput(int *score){
    int userChoice;
    while (1){
        printf("Score: %d-%d-%d\n\n", score[0], score[1], score[2]);
        printf("1 - Rock\n2 - Paper\n3 - Scissors\n");
        printf("Enter your choice: ");
        if (scanf("%d", &userChoice) != 1 || userChoice < 1 || userChoice > 3){
            system("clear");
            printf("Invalid input.\n\n");
            clearBuffer();
            continue;
        }
        break;
    }
    return userChoice;
}

char* getChoiceName(int *choice){
    switch (*choice){
        case 1:
            return "Rock";
            break;
        case 2:
            return "Paper";
            break;
        case 3:
            return "Scissors";
            break;
    }
}

int getComputerChoice(){
    srand(time(NULL));
    return (rand() % 3) + 1;
}

void main(){
    int score[] = {0, 0, 0};

    while(1){
        system("clear");

        // get user input
        int userChoice = getUserInput(score);
        clearBuffer();
        char *userChoiceName = getChoiceName(&userChoice);

        // get computer choice
        int computerChoice = getComputerChoice();
        char *computerChoiceName = getChoiceName(&computerChoice);

        // get winner
        int winner = getGameWinner(&userChoice, &computerChoice, score);
        
        // print winner
        system("clear");
        printf("Score: %d-%d-%d\n\n", score[0], score[1], score[2]);
        printf("Player Choice = %s\nComputer Choice = %s\n\n", userChoiceName, computerChoiceName);
        switch (winner){
            case 0:
                printf("YOU WIN.\n\n");
                break;
            case 1:
                printf("TIE.\n\n");
                break;
            case 2:
                printf("YOU LOST.\n\n");
                break;
        }
        printf("Press ENTER to continue...");
        while(getchar() != '\n');       // wait for key press and clear buffer hack
    }
}