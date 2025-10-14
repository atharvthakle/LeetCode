#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEnd;
} TrieNode;

typedef struct {
    TrieNode* root;
} WordDictionary;

// Helper function: create a new Trie node
TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEnd = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

WordDictionary* wordDictionaryCreate() {
    WordDictionary* obj = (WordDictionary*)malloc(sizeof(WordDictionary));
    obj->root = createNode();
    return obj;
}

// Add a word to the Trie
void wordDictionaryAddWord(WordDictionary* obj, char* word) {
    TrieNode* curr = obj->root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL) {
            curr->children[index] = createNode();
        }
        curr = curr->children[index];
    }
    curr->isEnd = true;
}

// Helper function for search (recursive)
bool searchHelper(TrieNode* node, char* word, int pos) {
    if (node == NULL) return false;
    if (word[pos] == '\0') return node->isEnd;

    if (word[pos] == '.') {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (node->children[i] && searchHelper(node->children[i], word, pos + 1))
                return true;
        }
        return false;
    } else {
        int index = word[pos] - 'a';
        return searchHelper(node->children[index], word, pos + 1);
    }
}

bool wordDictionarySearch(WordDictionary* obj, char* word) {
    return searchHelper(obj->root, word, 0);
}

// Free all Trie nodes
void freeNode(TrieNode* node) {
    if (!node) return;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) freeNode(node->children[i]);
    }
    free(node);
}

void wordDictionaryFree(WordDictionary* obj) {
    freeNode(obj->root);
    free(obj);
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 * bool param_2 = wordDictionarySearch(obj, word);
 * wordDictionaryFree(obj);
 */
