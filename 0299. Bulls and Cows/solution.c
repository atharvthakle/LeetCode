#include <string.h>
#include <stdlib.h>

char* getHint(char* secret, char* guess) {
    int bulls = 0, cows = 0;
    int countSecret[10] = {0}, countGuess[10] = {0};
    int n = strlen(secret);

    for (int i = 0; i < n; i++) {
        if (secret[i] == guess[i]) {
            bulls++;
        } else {
            countSecret[secret[i] - '0']++;
            countGuess[guess[i] - '0']++;
        }
    }

    for (int i = 0; i < 10; i++) {
        cows += (countSecret[i] < countGuess[i]) ? countSecret[i] : countGuess[i];
    }

    char* result = (char*)malloc(10 * sizeof(char)); // enough for "1000A1000B"
    sprintf(result, "%dA%dB", bulls, cows);
    return result;
}
