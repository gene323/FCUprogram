// Randomly generate numbers between 1 and 1000 for user to guess.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guessGame(void);                  // function prototype
void ascii(void);                      // function prototype
int isCorrect(int, int, int *, int *); // function prototype

int main(void)
{
    srand(time(0)); // seed random number generator
    guessGame();
} // end main

// guessGame generates numbers between 1 and 1000
// and checks user's guess
void guessGame(void)
{
    int answer;    // randomly generated number
    int response;  // 1 or 2 response to continue game
    int times = 1; //sum up how many times computer guess
    int L = 1;
    int R = 1000;
    int M = (L + R) / 2;

    // loop until user types 2 to quit game
    do
    {
        // generate random number between 1 and 1000
        // 1 is shift, 1000 is scaling factor
        answer = 1 + rand() % 1000;
        L = 1;
        R = 1000;
        M = (L + R) / 2;
        times = 1;

        // prompt for guess
        printf("I have a number between 1 and 1000.\n"
               "Can you guess my number?\n"
               "Please type your first guess.");
        printf("%s", "? ");

        // There are three type of how to guess answer
        if (answer % 3 == 0)
        {
            printf("%d\n", M);
            while (1)
            {
                if (isCorrect(M, answer, &L, &R) == 2)
                {
                    printf("The answer is %d\n", M);
                    break;
                }

                M = (L + R) / 2;
                printf("%d\n", M);
                times++;
            }
        }
        else if (answer % 3 == 1)
        {
            printf("1\n");
            if (answer > 1)
            {
                printf("Too low. Try again.? ");
                times++;
            }
            else if (answer == 1)
            {
                printf("The answer is %d\n", answer);
                break;
            }
            for (int i = 2; i <= 1000; i++)
            {
                printf("%d\n", i);

                if (i == answer)
                {
                    printf("The answer is %d\n", i);
                    break;
                }
                else if (i < answer)
                {
                    printf("Too low. Try again.? ");
                }
                else
                {
                    printf("Too high. Try again.? ");
                }
                times++;
            }
        }
        else if (answer % 3 == 2)
        {
            printf("1000\n");
            if (answer < 1000)
            {
                printf("Too high. Try again.? ");
                times++;
            }
            else if (answer == 1000)
            {
                printf("The answer is %d\n", answer);
                break;
            }

            for (int i = 999; i > 0; i--)
            {
                printf("%d\n", i);

                if (i == answer)
                {
                    printf("The answer is %d\n", i);
                    break;
                }
                else if (i < answer)
                {
                    printf("Too low. Try again.? ");
                }
                else
                {
                    printf("Too high. Try again.? ");
                }
                times++;
            }
        }

        // prompt for another game
        ascii();
        printf("\nExcellent! You guessed the number!\nYou have tried %d times\n"
               "Would you like to play again?\n",
               times);
        printf("%s", "Please type ( 1=yes, 2=no )? ");
        scanf("%d", &response);

        puts("");

    } while (response == 1);
} // end function guessGame

// isCorrect returns true if g equals a
// if g does not equal a, displays hint
int isCorrect(int M, int a, int *L, int *R)
{
    // guess is correct
    if (M == a)
        return 2;

    // guess is incorrect; display hint
    else if (M < a)
    {
        printf("Too low. Try again.? ");
        *L = M + 1;
        return 1;
    }

    else if (M > a)
    {
        printf("Too high. Try again.? ");
        *R = M - 1;
        return 1;
    }

} // end function isCorrect

void ascii(void)
{
    puts("    ,o888888o.    8 888888888o.   8 8888888888            .8.          8888888 8888888888");
    puts("   8888     `88.  8 8888    `88.  8 8888                 .888.               8 8888");
    puts(",8 8888       `8. 8 8888     `88  8 8888                :88888.              8 8888");
    puts("88 8888           8 8888     ,88  8 8888               . `88888.             8 8888");
    puts("88 8888           8 8888.   ,88'  8 888888888888      .8. `88888.            8 8888");
    puts("88 8888           8 888888888P'   8 8888             .8`8. `88888.           8 8888");
    puts("88 8888   8888888 8 8888`8b       8 8888            .8' `8. `88888.          8 8888");
    puts("`8 8888       .8' 8 8888 `8b.     8 8888           .8'   `8. `88888.         8 8888");
    puts("   8888     ,88'  8 8888   `8b.   8 8888          .888888888. `88888.        8 8888");
    puts("    `8888888P'    8 8888     `88. 8 888888888888 .8'       `8. `88888.       8 8888");
}