#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct List
{
    Node *head = NULL, *tail = NULL;

    int numberOfNodes()
    {
        if (head == NULL)
            return 0;
        else
        {
            int nodes = 1;
            struct Node *temp = head;
            while (temp != tail)
            {
                temp = temp->next;
                nodes++;
            }
            return nodes;
        }
    }

    void printList()
    {
        if (head == NULL)
        {
            cout << "empty list" << endl;
        }
        else
        {
            struct Node *temp = head;
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
    }

    void insertMiddle(int position, int value)
    {
        int nodes = numberOfNodes();
        if (position < 1 || position > nodes + 1)
        {
            printf("Error: Insert middle in position: %d. But list has %d nodes\n", position, nodes);
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
        }
    }

    void deleteBegin()
    {
        if (head != NULL)
        {
            Node *temp = head;
            head = head->next;
            free(temp);
        }
    }

    void deleteEnd()
    {
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        free(tail);
        tail = temp;
    }

    void deleteMiddle(int position)
    {
        int nodes = numberOfNodes();
        if (position < 1 || position > nodes)
        {
            printf("Error: Delete middle in position: %d. But list has %d nodes\n", position, nodes);
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
            free(del);
        }
    }

    void deleteList()
    {
        while (head != NULL)
        {
            Node *temp = head;
            head = temp->next;
            free(temp);
        }
        head = tail = NULL;
    }
};

int main()
{
    struct List myList;
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