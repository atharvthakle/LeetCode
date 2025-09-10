#include <stdbool.h>
#include <stdlib.h>

int minimumTeachings(int n, int** languages, int languagesSize, int* languagesColSize,
                     int** friendships, int friendshipsSize, int* friendshipsColSize) {
    // Step 1: build a matrix userLanguage[user][language] = true if user knows language
    bool userLanguage[languagesSize + 1][n + 1];
    for (int i = 1; i <= languagesSize; i++) {
        for (int j = 1; j <= n; j++) {
            userLanguage[i][j] = false;
        }
    }
    for (int i = 0; i < languagesSize; i++) {
        for (int j = 0; j < languagesColSize[i]; j++) {
            int lang = languages[i][j];
            userLanguage[i + 1][lang] = true; // user index is 1-based
        }
    }

    // Step 2: mark problematic users
    bool problematic[languagesSize + 1];
    for (int i = 1; i <= languagesSize; i++) {
        problematic[i] = false;
    }

    for (int i = 0; i < friendshipsSize; i++) {
        int u = friendships[i][0];
        int v = friendships[i][1];

        bool canCommunicate = false;
        for (int l = 1; l <= n; l++) {
            if (userLanguage[u][l] && userLanguage[v][l]) {
                canCommunicate = true;
                break;
            }
        }

        if (!canCommunicate) {
            problematic[u] = true;
            problematic[v] = true;
        }
    }

    // Step 3: try teaching each language
    int result = languagesSize; // upper bound
    for (int l = 1; l <= n; l++) {
        int count = 0;
        for (int u = 1; u <= languagesSize; u++) {
            if (problematic[u] && !userLanguage[u][l]) {
                count++;
            }
        }
        if (count < result) result = count;
    }

    return result;
}
