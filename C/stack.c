#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *push(Node *top, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed in push()\n");
        return top;
    }
    newNode->data = value;
    newNode->next = top;
    return newNode;
}

Node *pop(Node *top)
{
    if (top != NULL)
    {
        Node *temp = top->next;
        free(top);
        return temp;
    }
    return NULL;
}

int peek(Node *top)
{
    if (top == NULL)
    {
        printf("Error: Stack is empty. Cannot peek.\n");
        return -1;
    }
    return top->data;
}

int isEmpty(Node *top)
{
    return (top == NULL) ? 1 : 0;
}

int main()
{
    Node *top = NULL;
    
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    
    while (!isEmpty(top))
    {
        printf("%d ", peek(top));
        top = pop(top);
    }
    printf("\n");

    return 0;
}