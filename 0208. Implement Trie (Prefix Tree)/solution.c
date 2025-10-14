#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Define Trie Node
typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

// Define Trie
typedef struct {
    TrieNode* root;
} Trie;

// Helper function: create a new TrieNode
TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

// Initialize the Trie
Trie* trieCreate() {
    Trie* trie = (Trie*)malloc(sizeof(Trie));
    trie->root = createNode();
    return trie;
}

// Insert a word into the Trie
void trieInsert(Trie* obj, char* word) {
    TrieNode* curr = obj->root;
    for (int i = 0; word[i]; i++) {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL)
            curr->children[index] = createNode();
        curr = curr->children[index];
    }
    curr->isEndOfWord = true;
}

// Search for a word in the Trie
bool trieSearch(Trie* obj, char* word) {
    TrieNode* curr = obj->root;
    for (int i = 0; word[i]; i++) {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL)
            return false;
        curr = curr->children[index];
    }
    return curr->isEndOfWord;
}

// Check if there exists any word starting with a given prefix
bool trieStartsWith(Trie* obj, char* prefix) {
    TrieNode* curr = obj->root;
    for (int i = 0; prefix[i]; i++) {
        int index = prefix[i] - 'a';
        if (curr->children[index] == NULL)
            return false;
        curr = curr->children[index];
    }
    return true;
}

// Helper function to free Trie recursively
void freeNode(TrieNode* node) {
    if (!node) return;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i])
            freeNode(node->children[i]);
    }
    free(node);
}

// Free the entire Trie
void trieFree(Trie* obj) {
    freeNode(obj->root);
    free(obj);
}

/**
 * Example usage:
 * 
 * Trie* trie = trieCreate();
 * trieInsert(trie, "apple");
 * printf("%d\n", trieSearch(trie, "apple"));   // Output: 1 (true)
 * printf("%d\n", trieSearch(trie, "app"));     // Output: 0 (false)
 * printf("%d\n", trieStartsWith(trie, "app")); // Output: 1 (true)
 * trieInsert(trie, "app");
 * printf("%d\n", trieSearch(trie, "app"));     // Output: 1 (true)
 * trieFree(trie);
 */
