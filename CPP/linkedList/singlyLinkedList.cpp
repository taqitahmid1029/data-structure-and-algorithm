#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class List
{
private:
    Node *head, *tail;
    int nodes;

public:
    List()
    {
        head = tail = NULL;
        nodes = 0;
    }

    ~List()
    {
        deleteList();
    }

    void printList()
    {
        if (head == NULL)
        {
            cout << "empty list" << endl;
        }
        else
        {
            Node *temp = head;
            while (temp != tail)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << temp->data << endl;
        }
    }

    void insertBegin(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        if (head == NULL)
        {
            newNode->next = NULL;
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        nodes++;
    }

    void insertEnd(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        nodes++;
    }

    void insertMiddle(int position, int value)
    {
        if (position < 1 || position > nodes + 1)
        {
            cout << "Error: Insert middle in position: " << position << ". But list has " << nodes << " nodes" << endl;
        }
        else if (position == 1)
        {
            insertBegin(value);
        }
        else if (position == nodes + 1)
        {
            insertEnd(value);
        }
        else
        {
            Node *newNode = new Node;
            newNode->data = value;
            Node *temp = head;
            for (int i = 1; i < position - 1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            nodes++;
        }
    }

    void deleteBegin()
    {
        if (head == NULL)
        {
            return;
        }
        else if (head->next == NULL)
        {
            delete head;
            head = tail = NULL;
            nodes--;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            nodes--;
        }
    }

    void deleteEnd()
    {
        if (head == NULL)
        {
            return;
        }
        else if (head->next = NULL)
        {
            delete head;
            head = tail = NULL;
            nodes = 0;
        }
        else
        {
            Node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            temp->next = NULL;
            delete tail;
            tail = temp;
            nodes--;
        }
    }

    void deleteMiddle(int position)
    {
        if (position < 1 || position > nodes)
        {
            cout << "Error: Delete middle in position: " << position << ". But list has " << nodes << " nodes" << endl;
        }
        else if (position == 1)
        {
            deleteBegin();
        }
        else if (position == nodes)
        {
            deleteEnd();
        }
        else
        {
            Node *temp = head;
            for (int i = 1; i < position - 1; i++)
            {
                temp = temp->next;
            }
            Node *del = temp->next;
            temp->next = del->next;
            delete del;
            nodes--;
        }
    }

    void deleteList()
    {
        while (head != NULL)
        {
            Node *temp = head;
            head = temp->next;
            delete temp;
        }
        head = tail = NULL;
        nodes = 0;
    }
};

int main()
{
    List myList;
    myList.printList();
    myList.insertBegin(11);
    myList.insertBegin(10);
    myList.insertEnd(14);
    myList.insertEnd(15);
    myList.insertMiddle(3, 12);
    myList.insertMiddle(4, 13);
    myList.printList();

    myList.deleteBegin();
    myList.deleteEnd();
    myList.deleteMiddle(2);
    myList.printList();

    myList.deleteList();
    myList.printList();
    return 0;
}