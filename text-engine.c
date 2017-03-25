#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"
#include "levenshtein.h"

#define WORD_LENGTH 50

void printPage(int numLines);
int main(int argc, char *argv[])
{
    FILE *dictionary = NULL;
    char userWord[WORD_LENGTH];
    char compareWord[WORD_LENGTH];
    char minWord[WORD_LENGTH];
    char page;
    int minDistance;
    int currDistance;
    int done;

    dictionary = fopen(argv[1], "r");
    printf("What word should I check? \n");
    fgets(userWord, WORD_LENGTH, stdin);
    //removing the newline character
    userWord[strlen(userWord) - 1] = '\0';
    minDistance = strlen(userWord)+1;

    while(fgets(compareWord, WORD_LENGTH, dictionary) != NULL)
    {
        currDistance = levenshtein(userWord, compareWord);
        if (currDistance < 5) 
        {
            if (currDistance < minDistance) 
            {
                minDistance = currDistance;
                strcpy(minWord, compareWord);
            }
            insert(compareWord);
        }
    }
    fclose(dictionary);
    printf("Did you mean... %s\n", minWord);
    printf("There are %d other similar words, would you like to see them (y/n)? ", size());
    page = getchar();
    printf("This function is not working from here on.");
    /*
    printf("%d", putchar(page));
    if (page == 'y') {
        done = 0;
        printf("\n");
        printf("ALALALALALALLA");
        while (done != 1) 
        {
            page = getchar();
            printf("hahahaha");
            if (page == '\r')
            {
                printf("Do we get here");
                if (size() >= 10)
                {
                    printPage(10);
                }
                else if (size() > 0)
                {
                    printPage(size());
                }
                else {
                    done = 1;
                }
            }
            else if (page == 'q')
            {
                page = getchar();
                if (page == '\r')
                {
                    done = 1;
                }
            }
        }

    }*/

}

void printPage(int numLines) 
{
    int count = 0;
    char currentWord[WORD_LENGTH];
    strcpy(currentWord, firstItem());
    while (count < numLines) {
        printf("%s\n", currentWord);
        strcpy(currentWord, nextItem());
        count++;
    }
}