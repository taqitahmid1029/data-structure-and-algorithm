#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

struct List
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
            cout << temp->data << " -> [back to head: " << temp->next->data << "]" << endl;
        }
    }

    void insertBegin(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        if (head == NULL)
        {
            newNode->next = newNode;
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            tail->next = newNode;
            head = newNode;
        }
        nodes++;
    }

    void insertEnd(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        if (head == NULL)
        {
            newNode->next = newNode;
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
        nodes++;
    }

    void insertMiddle(int position, int value)
    {
        if (1 > position || position > nodes + 1)
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
        else if (head == tail)
        {
            delete head;
            head = tail = NULL;
            nodes--;
        }
        else
        {
            Node *temp = head;
            tail->next = head->next;
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
        else if (head == tail)
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
            delete tail;
            tail = temp;
            tail->next = head;
            nodes--;
        }
    }

    void deleteMiddle(int position)
    {
        if (1 > position || position > nodes)
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
        if (head == NULL)
        {
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = NULL;
            nodes = 0;
        }
        else
        {
            Node *temp = head->next;
            while (temp != tail)
            {
                Node *del = temp;
                temp = temp->next;
                delete del;
            }
            delete temp;
            delete head;
            head = tail = NULL;
            nodes = 0;
        }
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
    myList.deleteMiddle(3);
    myList.printList();

    myList.deleteList();
    myList.printList();
    return 0;
}