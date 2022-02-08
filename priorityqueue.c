#include <stdio.h>
#include <stdlib.h>

struct item
{
    int value;
    int priority;
};

struct item pq[100];
int rear = -1;
int front = -1;

void push(int current_value, int current_priority)
{
    if (rear == -1)
        front = rear = 0;

    int pos = front;
    while (pos < rear && current_priority < pq[pos].priority)
        pos++;

    for (int k = rear + 1; k > pos; k--)
        pq[k] = pq[k - 1];

    pq[pos].value = current_value;
    pq[pos].priority = current_priority;

    rear++;
}

int pop()
{
    if (front == -1)
        return -1;

    int del = pq[front].value;
    if (front == rear - 1)
        front = rear = -1;
    else
        front++;
    return del;
}


void displayQ()
{
    if (front == -1)
    {
        printf("Queue empty\n");
        return;
    }
    printf("\nValue   |    Priority\n");
    for (int i = front; i < rear; i++)
        printf("   %d         %d   \n", pq[i].value, pq[i].priority);
}

int main()
{
    int ch, val, priority, del, p;
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display");
        printf("\n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter value to insert\n");
            scanf("%d", &val);
            printf("\nEnter priority\n");
            scanf("%d", &priority);
            push(val, priority);
            break;
        case 2:
            del = pop();
            if (del == -1)
                printf("\nQueue empty");
            else
                printf("\nRemoved from queue: %d", del);
            break;
        case 3:
            displayQ();
        }
    } while (ch < 4);

    return 0;
}
