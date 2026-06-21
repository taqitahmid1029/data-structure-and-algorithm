#include <stdio.h>
#include <stdlib.h>

struct Node
{
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
        while (temp->next != *head)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("%d -> [back to head: %d]\n", temp->data, temp->next->data);
    }
}

int numberOfNodes(struct Node **head)
{
    if (*head == NULL)
    {
        return 0;
    }
    else if ((*head)->next == *head)
    {
        return 1;
    }
    else
    {
        int nodes = 1;
        struct Node *temp = (*head)->next;
        while (temp != *head)
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
    if (newNode == NULL)
    {
        printf("node allocation failed in insertBegin()\n");
        return;
    }
    newNode->data = value;
    if (*head == NULL)
    {
        newNode->next = newNode;
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        struct Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        *head = newNode;
    }
}

void insertEnd(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("node allocation failed in insertEnd()\n");
        return;
    }
    newNode->data = value;
    if (*head == NULL)
    {
        newNode->next = newNode;
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        struct Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertMiddle(struct Node **head, int position, int value)
{
    int nodes = numberOfNodes(head);
    if (1 > position || position > nodes + 1)
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
        if (newNode == NULL)
        {
            printf("node allocation failed in insertMiddle()\n");
            return;
        }
        newNode->data = value;
        struct Node *temp = *head;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteBegin(struct Node **head)
{
    if (*head == NULL)
    {
        return;
    }
    else if ((*head)->next == *head)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        *head = (*head)->next;
        free(temp->next);
        temp->next = *head;
    }
}

void deleteEnd(struct Node **head)
{
    if (*head == NULL)
    {
        return;
    }
    else if ((*head)->next == *head)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next->next != *head)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = *head;
    }
}

void deleteMiddle(struct Node **head, int position)
{
    int nodes = numberOfNodes(head);
    if (1 > position || position > nodes)
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
        free(del);
    }
}

void deleteList(struct Node **head)
{
    if (*head == NULL)
    {
        return;
    }
    else if ((*head)->next == *head)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        struct Node *temp = (*head)->next;
        while (temp->next != *head)
        {
            struct Node *del = temp;
            temp = temp->next;
            free(del);
        }
        free(temp);
        free(*head);
        *head = NULL;
    }
}

int main()
{
    struct Node *head = NULL;
    printList(&head);

    insertBegin(&head, 9);
    insertBegin(&head, 7);
    insertEnd(&head, 13);
    insertEnd(&head, 15);
    insertMiddle(&head, 3, 10);
    printList(&head);

    deleteBegin(&head);
    deleteEnd(&head);
    deleteMiddle(&head, 2);
    printList(&head);

    deleteList(&head);
    printList(&head);
    return 0;
}