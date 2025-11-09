#include <stdbool.h>
#include <stdlib.h>

/*
 *	struct Iterator {
 *		// Returns true if the iteration has more elements.
 *		bool (*hasNext)();
 *
 * 		// Returns the next element in the iteration.
 *		int (*next)();
 *	};
 */

struct PeekingIterator {
    struct Iterator* iterator;
    bool hasPeeked;
    int peekedValue;
};

struct PeekingIterator* Constructor(struct Iterator* iter) {
    struct PeekingIterator* piter = malloc(sizeof(struct PeekingIterator));
    piter->iterator = iter;
    piter->hasPeeked = false;
    return piter;
}

int peek(struct PeekingIterator* obj) {
    if (!obj->hasPeeked) {
        obj->peekedValue = obj->iterator->next();
        obj->hasPeeked = true;
    }
    return obj->peekedValue;
}

int next(struct PeekingIterator* obj) {
    if (obj->hasPeeked) {
        obj->hasPeeked = false;
        return obj->peekedValue;
    }
    return obj->iterator->next();
}

bool hasNext(struct PeekingIterator* obj) {
    return obj->hasPeeked || obj->iterator->hasNext();
}

void peekingIteratorFree(struct PeekingIterator* obj) {
    free(obj);
}
