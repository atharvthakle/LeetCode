#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> s1, s2;  // s1 for input, s2 for output

public:
    MyQueue() { }

    // Push element to the back of queue
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from the front of queue and returns it
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }

    // Get the front element
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    // Returns whether the queue is empty
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
