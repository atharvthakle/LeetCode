#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q1, q2; // main queue (q1) and helper queue (q2)
    
public:
    MyStack() {
    }
    
    void push(int x) {
        q2.push(x); // push new element into q2
        
        // move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // swap q1 and q2 — now q1 has the new top at front
        swap(q1, q2);
    }
    
    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};
