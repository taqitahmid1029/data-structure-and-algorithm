#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

void printList(struct Node *head)
{
    if (head == NULL)
    {
        printf("empty list\n");
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

int numberOfNodes(struct Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        struct Node *temp = head;
        int nodes = 0;
        while (temp != NULL)
        {
            nodes++;
            temp = temp->next;
        }
        return nodes;
    }
}

struct Node *insertBegin(struct Node *head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->prev = NULL;
    newNode->data = value;
    if (head == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
    }
    return newNode;
}

struct Node *insertEnd(struct Node *head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
    {
        newNode->prev = NULL;
        return newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        return head;
    }
}

struct Node *insertMiddle(struct Node *head, int position, int value)
{
    int nodes = numberOfNodes(head);
    if (position < 1 || position > nodes + 1)
    {
        printf("Error: Insert middle in position: %d. But list has %d nodes\n", position, nodes);
        return head;
    }
    else if (position == 1)
    {
        return insertBegin(head, value);
    }
    else if (position == nodes + 1)
    {
        return insertEnd(head, value);
    }
    else
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        struct Node *temp = head;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        return head;
    }
}

struct Node *deleteBegin(struct Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    else if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    else
    {
        struct Node *temp = head->next;
        temp->prev = NULL;
        free(head);
        return temp;
    }
}

struct Node *deleteEnd(struct Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    else if (head->next == NULL)
    {
        free(head);
        return NULL;
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
        return head;
    }
}

struct Node *deleteMiddle(struct Node *head, int position)
{
    int nodes = numberOfNodes(head);
    if (position < 1 || position > nodes)
    {
        printf("Error: Delete middle in position: %d. But list has %d nodes\n", position, nodes);
        return head;
    }
    else if (position == 1)
    {
        return deleteBegin(head);
    }
    else if (position == nodes)
    {
        return deleteEnd(head);
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
        del->next->prev = temp;
        free(del);
        return head;
    }
}

struct Node *deleteList(struct Node *head)
{
    while (head != NULL)
    {
        struct Node *temp = head;
        head = temp->next;
        free(temp);
    }
    return NULL;
}

int main()
{
    struct Node *head = NULL;
    printList(head);

    head = insertBegin(head, 12);
    head = insertBegin(head, 9);
    head = insertBegin(head, 8);
    head = insertMiddle(head, 3, 10);
    head = insertMiddle(head, 4, 11);
    head = insertEnd(head, 13);
    head = insertEnd(head, 14);
    printList(head);

    head = deleteBegin(head);
    head = deleteMiddle(head, 3);
    head = deleteEnd(head);
    printList(head);

    head = deleteList(head);
    printList(head);
    return 0;
}