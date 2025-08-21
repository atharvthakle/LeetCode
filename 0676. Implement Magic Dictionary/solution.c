#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char **words;   // store dictionary words
    int size;       // number of words
} MagicDictionary;

// Create dictionary
MagicDictionary* magicDictionaryCreate() {
    MagicDictionary* obj = (MagicDictionary*)malloc(sizeof(MagicDictionary));
    obj->words = NULL;
    obj->size = 0;
    return obj;
}

// Build dictionary
void magicDictionaryBuildDict(MagicDictionary* obj, char** dictionary, int dictionarySize) {
    obj->size = dictionarySize;
    obj->words = (char**)malloc(sizeof(char*) * dictionarySize);
    for (int i = 0; i < dictionarySize; i++) {
        obj->words[i] = strdup(dictionary[i]);  // copy word
    }
}

// Search word
bool magicDictionarySearch(MagicDictionary* obj, char* searchWord) {
    for (int i = 0; i < obj->size; i++) {
        char* word = obj->words[i];
        if (strlen(word) != strlen(searchWord)) 
            continue;  // must be same length
        int diff = 0;
        for (int j = 0; word[j] && searchWord[j]; j++) {
            if (word[j] != searchWord[j]) diff++;
            if (diff > 1) break;  // no need to continue
        }
        if (diff == 1) return true;
    }
    return false;
}

// Free memory
void magicDictionaryFree(MagicDictionary* obj) {
    if (!obj) return;
    for (int i = 0; i < obj->size; i++) {
        free(obj->words[i]);
    }
    free(obj->words);
    free(obj);
}

/**
 * Example usage:
 * MagicDictionary* obj = magicDictionaryCreate();
 * char* dict[] = {"hello", "leetcode"};
 * magicDictionaryBuildDict(obj, dict, 2);
 * printf("%d\n", magicDictionarySearch(obj, "hello"));    // 0 (false)
 * printf("%d\n", magicDictionarySearch(obj, "hhllo"));    // 1 (true)
 * printf("%d\n", magicDictionarySearch(obj, "hell"));     // 0 (false)
 * printf("%d\n", magicDictionarySearch(obj, "leetcoded"));// 0 (false)
 * magicDictionaryFree(obj);
 */
