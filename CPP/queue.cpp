#include <iostream>
#include <list>
using namespace std;

class Queue
{
private:
    list<int> myQueue;

public:
    void push(int value)
    {
        myQueue.push_back(value);
    }

    void pop()
    {
        myQueue.pop_front();
    }

    int top()
    {
        return myQueue.front();
    }

    bool isEmpty()
    {
        return myQueue.empty();
    }
};

int main()
{
    Queue heroQueue;
    heroQueue.push(1);
    heroQueue.push(2);
    heroQueue.push(3);
    
    while (!heroQueue.isEmpty())
    {
        cout << heroQueue.top() << " ";
        heroQueue.pop();
    }
    cout << endl;
    
    return 0;
}