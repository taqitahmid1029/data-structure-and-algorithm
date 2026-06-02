#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int numberOfNodes(struct Node *head)
{
    if (head == NULL)
        return 0;
    else
    {
        int nodes = 1;
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
            nodes++;
        }
        return nodes;
    }
}

void printList(struct Node *head)
{
    if (head == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

struct Node *insertBegin(struct Node *head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("node allocation failed in insertMiddle()\n");
        return head;
    }
    newNode->data = value;
    if (head == NULL)
        newNode->next = NULL;
    else
        newNode->next = head;
    return newNode;
}

void insertMiddle(struct Node *head, int position, int value)
{
    int nodes = numberOfNodes(head);
    if (position < 1 || position > nodes + 1)
    {
        printf("Error: Insert middle in position: %d. But list has %d nodes\n", position, nodes);
    }
    else if (position == 1)
    {
        printf("Try calling insertBegin() for data %d\n", value);
    }
    else if (position == nodes + 1)
    {
        printf("Try calling insertEnd() for data %d\n", value);
    }
    else
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL)
        {
            printf("node allocation failed in insertMiddle()\n");
            return;
        }
        newNode->data = value;
        struct Node *temp = head;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertEnd(struct Node *head, int value)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("node allocation failed in insertMiddle()\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

struct Node *deleteBegin(struct Node *head)
{
    if (head != NULL)
    {
        struct Node *temp = head->next;
        free(head);
        return temp;
    }
}

void deleteMiddle(struct Node *head, int position)
{
    int nodes = numberOfNodes(head);
    if (position < 1 || position > nodes)
    {
        printf("Error: Delete middle in position: %d. But list has %d nodes\n", position, nodes);
    }
    else if (position == 1)
    {
        printf("Try calling deleteBegin()\n");
    }
    else if (position == nodes)
    {
        printf("Try calling deleteEnd()\n");
    }
    else
    {
        struct Node *temp = head;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        struct Node *del = temp->next;
        temp->next = del->next;
        free(del);
    }
}

void deleteEnd(struct Node *head)
{
    if (head == NULL)
    {
        return;
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void deleteList(struct Node *head)
{
    while (head != NULL)
    {
        struct Node *temp = head;
        head = temp->next;
        free(temp);
    }
}

int main()
{
    struct Node *head = NULL;
    printList(head);

    head = insertBegin(head, 12);
    head = insertBegin(head, 9);
    head = insertBegin(head, 8);
    insertMiddle(head, 3, 10);
    insertMiddle(head, 4, 11);
    insertEnd(head, 13);
    insertEnd(head, 14);
    printList(head);

    head = deleteBegin(head);
    deleteMiddle(head, 3);
    deleteEnd(head);
    printList(head);

    deleteList(head);
    head = NULL;
    printList(head);
    return 0;
}