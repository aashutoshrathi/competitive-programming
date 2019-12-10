#include <iostream>
#include <stack>
using namespace std;

class StackQueue {
    private:   
        stack<int> s1;
        stack<int> s2;
    public:
        void push(int);
        int pop();
}; 

/* The method push to push element into the queue */
void StackQueue :: push(int x) {
    s1.push(x);
}

/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop() {
    if(s1.empty()) {
        return -1;
    } else {
        // unload s1 into s2
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        int res = s2.top();
        s2.pop();
        
        // unload s2 back to s1
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        
        return res;
    }
}
