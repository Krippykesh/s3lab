
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;
struct Node *front = NULL, *rear = NULL;


bool stack_empty()
{
    return top == NULL;
}


void stack_push(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (top)
        newNode->next = top;
    top = newNode;
}


int stack_pop()
{
    if (stack_empty())
        return -1;
    int del = top->data;
    struct Node *temp = top;
    top = top->next;
    free(temp);

    return del;
}

void displayS()
{
    if (stack_empty())
    {
        printf("Empty\n");
        return;
    }
    for (struct Node *ptr = top; ptr; ptr = ptr->next)
        printf("%d ", ptr->data);
}

bool qEmpty()
{
    return front == NULL && rear == NULL;
}


void push(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (rear == NULL)
        front = newNode;
    else
        rear->next = newNode;
    rear = newNode;
}


int pop()
{
    if (qEmpty())
        return -1;

    int deleted = front->data;
    struct Node *temp = front;
    if (front == rear)
        front = rear = NULL;
    else
        front = front->next;

    free(temp);
    return deleted;
}


void displayq()
{
    if (qEmpty())
    {
        printf("Empty\n");
        return;
    }
    for (struct Node *curr = front; curr; curr = curr->next)
        printf("%d ", curr->data);
}

int main()
{
    int chS,chQ,op;
    do
    {
        printf("\n\nEnter choice\n");
        printf("1.Stack");
        printf("\n2.Queue\n");
        scanf("%d", &op);
        if(op==1)
        {
     do
     {
        printf("\n\nEnter choice\n");
        printf("1.Push");
        printf("\n2.Pop");
        printf("\n3.Display Stack\n");
        printf("4.Exit\n");
        scanf("%d", &chS);
        int dataS, delS;
        switch (chS)
        {
        case 1:

            printf("\nEnter data to insert\n");
            scanf("%d", &dataS);
            stack_push(dataS);
            break;
        case 2:
            delS = stack_pop();
            if (delS == -1)
                printf("\nStack Empty");
            else
                printf("\nPopped: %d", delS);
            break;
        case 3:
            printf("\nStack: ");
            displayS();
            break;
        case 4: exit(0);
        }
    }while (chS< 4);
}
    else if(op==2)
    {
        do
      {
        printf("\n\nEnter choice\n");
        printf("1.Push");
        printf("\n2.Pop");
        printf("\n3.Display Queue\n");
        printf("4.Exit\n");
        scanf("%d", &chQ);
        int dataQ, delQ;
        switch (chQ)
        {
        case 1:

            printf("\nEnter data to insert\n");
            scanf("%d", &dataQ);
            push(dataQ);
            break;
        case 2:
            delQ = pop();
            if (delQ == -1)
                printf("\nQueue Empty");
            else
                printf("\nDeleted: %d", delQ);
            break;
        case 3:
            printf("\nQueue: ");
            displayq();
            break;
        case 4: exit(0);
        }
    }while(chQ<4);
    }
    } while (op < 2);
    return 0;
}



