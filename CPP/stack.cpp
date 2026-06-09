#include <iostream>
#include <list>
using namespace std;

class Stack
{
private:
    list<int> myStack;

public:
    void push(int value)
    {
        myStack.push_front(value);
    }

    void pop()
    {
        myStack.pop_front();
    }

    int peek()
    {
        return myStack.front();
    }

    bool empty()
    {
        return myStack.empty();
    }
};

int main()
{
    Stack heroStack;
    heroStack.push(1);
    heroStack.push(2);
    heroStack.push(3);

    while (!heroStack.empty())
    {
        cout << heroStack.peek() << " ";
        heroStack.pop();
    }
    cout << endl;
    return 0;
}