/**
 * Randomly hits lowercase letters until the given string is produced.
 * If a monkey types for long enough, it will eventually produce Shakespeare, right?
 * @author Winston Cheaz
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

/**
 * Produces the string given by args randomly. Good Luck!
 * arg has to be in all lowercase, and has to be a letter from a-z
*/
int main (int argc, char* argv[]){
    if (argc == 1 || argc > 3){
        printf("Program expects 1 argument\n");
        exit(EXIT_FAILURE);
    }
    char* wantedString = argv[1];
    int stringLength = strlen(wantedString);
    char* output = malloc(sizeof(char) * (stringLength + 1));
    output[stringLength] = '\0';
    long long loops = 0;
    long long expected = pow(26, stringLength);
    clock_t time = clock();
    int ch = 0;
    printf("Your string of <%s> has an expected number of attempts at: %lld\n", wantedString, expected);
    srand(time);
    while (strcmp(output, wantedString) != 0){
        loops++;
        for (int i = 0; i < stringLength; i++){
            ch = (rand() % 26) + 97;
            output[i] = ch;
        }
    }
    time = clock() - time;
    printf("%s\nTook %lld loops\nRuntime: %f seconds.\n", output, loops, (float)time / CLOCKS_PER_SEC);
    if (loops > expected){
        printf("That took longer than expected!\n");
    }
    else if (loops < expected){
        printf("That was shorter than expected!\n");
    }
    else{
        printf("You somehow got exactly as many tries as expected!\n");
    }
    free(output);
    return EXIT_SUCCESS;
}
