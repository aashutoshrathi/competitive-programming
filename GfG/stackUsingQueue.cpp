#include <iostream>
#include <queue>
using namespace std;

class QueueStack {
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};


void QueueStack :: push(int x)
{
    q1.push(x);
}


int QueueStack :: pop()
{
    if(q1.empty())
        return -1;
    int x;
    while(q1.size() != 1) {
        q2.push(q1.front());
        q1.pop();
    }
    x = q1.front();
    q1.pop();
    queue<int> q = q2;
    q2 = q1;
    q1 = q;
    return x;
}
