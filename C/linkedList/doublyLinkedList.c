#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

void printList(struct Node **head)
{
    if (*head == NULL)
    {
        printf("empty list\n");
    }
    else
    {
        struct Node *temp = *head;
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int numberOfNodes(struct Node **head)
{
    if (*head == NULL)
    {
        return 0;
    }
    else
    {
        struct Node *temp = *head;
        int nodes = 0;
        while (temp != NULL)
        {
            nodes++;
            temp = temp->next;
        }
        return nodes;
    }
}

void insertBegin(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->prev = NULL;
    newNode->data = value;
    if (*head == NULL)
    {
        newNode->next = NULL;
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertEnd(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insertMiddle(struct Node **head, int position, int value)
{
    int nodes = numberOfNodes(head);
    if (position < 1 || position > nodes + 1)
    {
        printf("Error: Insert middle in position: %d. But list has %d nodes\n", position, nodes);
    }
    else if (position == 1)
    {
        insertBegin(head, value);
    }
    else if (position == nodes + 1)
    {
        insertEnd(head, value);
    }
    else
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        struct Node *temp = *head;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}

void deleteBegin(struct Node **head)
{
    if (*head == NULL)
    {
        return;
    }
    else if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        struct Node *temp = *head;
        *head = temp->next;
        (*head)->prev = NULL;
        free(temp);
    }
}

void deleteEnd(struct Node **head)
{
    if (*head == NULL)
    {
        return;
    }
    else if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void deleteMiddle(struct Node **head, int position)
{
    int nodes = numberOfNodes(head);
    if (position < 1 || position > nodes)
    {
        printf("Error: Delete middle in position: %d. But list has %d nodes\n", position, nodes);
    }
    else if (position == 1)
    {
        deleteBegin(head);
    }
    else if (position == nodes)
    {
        deleteEnd(head);
    }
    else
    {
        struct Node *temp = *head;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        struct Node *del = temp->next;
        temp->next = del->next;
        del->next->prev = temp;
        free(del);
    }
}

void deleteList(struct Node **head)
{
    while (*head != NULL)
    {
        struct Node *temp = *head;
        *head = temp->next;
        free(temp);
    }
    *head = NULL;
}

int main()
{
    struct Node *head = NULL;
    printList(&head);

    insertBegin(&head, 8);
    insertBegin(&head, 6);
    insertEnd(&head, 12);
    insertEnd(&head, 14);
    insertMiddle(&head, 3, 9);
    printList(&head);

    deleteMiddle(&head, 3);
    deleteBegin(&head);
    deleteEnd(&head);
    printList(&head);

    deleteList(&head);
    printList(&head);
    return 0;
}