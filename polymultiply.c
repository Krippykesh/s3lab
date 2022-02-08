#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int power, coeff;
    struct Node *link;
};

struct Node *insertNode(struct Node *, int, int);
struct Node *inputPoly(struct Node *, int);
void display(struct Node *);

struct Node *Multiply(struct Node *poly1, struct Node *poly2)
{
    struct Node *prod = NULL;
    int coeff, power;
    for (struct Node *i = poly1; i != NULL; i = i->link)
        for (struct Node *j = poly2; j != NULL; j = j->link)
        {
            coeff = i->coeff * j->coeff;
            power = i->power + j->power;
            prod = insertNode(prod, coeff, power);
        }
    return prod;
}

struct Node *insertNode(struct Node *prod, int coeff, int power)
{
    struct Node *curr = prod;
    while (curr != NULL)
    {
        if (curr->power == power)
        {
            curr->coeff += coeff;
            return prod;
        }
        curr = curr->link;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->link = NULL;

    if (prod == NULL)
        return newNode;

    curr = prod;
    struct Node *prev = NULL;
    struct Node *next = NULL;
    while (curr != NULL && power < curr->power)
    {
        prev = curr;
        curr = curr->link;
        next = curr;
    }
    if (prev == NULL)
    {
        newNode->link = prod;
        prod = newNode;
    }
    else
    {
        newNode->link = next;
        prev->link = newNode;
    }
    return prod;
}


int main()
{
    struct Node *head1 = NULL, *head2 = NULL, *prod = NULL;
    int size1;
    int size2;

    printf("\nEnter number of terms of first polynomial  ");
    scanf("%d", &size1);
    if (size1 < 1)
    {
        printf("\nInvalid size");
        return 0;
    }
    head1 = inputPoly(head1, size1);

    printf("\nEnter number of terms of second polynomial  ");
    scanf("%d", &size2);
    if (size2 < 1)
    {
        printf("\nInvalid size");
        return 0;
    }
    head2 = inputPoly(head2, size2);

    printf("\nFirst polynomial: ");
    display(head1);
    printf("\nSecond polynomial: ");
    display(head2);

    printf("\nResult of Multiplication: ");
    prod = Multiply(head1, head2);
    display(prod);

    printf("\n");
    return 0;
}

struct Node *inputPoly(struct Node *head, int size)
{
    struct Node *ptr = NULL;
    int power, coeff;
    printf("\nEnter the coeffiecent and power of polynomial");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &coeff);
        scanf("%d", &power);
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->power = power;
        newNode->coeff = coeff;
        newNode->link = NULL;
        if (head == NULL)
            head = newNode;
        else
            ptr->link = newNode;
        ptr = newNode;
    }
    return head;
}

void display(struct Node *ptr)
{
    while (ptr != NULL)
       {
        if(ptr->power != 0 && ptr->coeff !=0)
            printf(" %dx^(%d)", ptr->coeff, ptr->power);
        else{
            if(ptr->coeff !=0)
         printf(" %d", ptr->coeff);
         else
            printf(" ");
        }
        (ptr->link != NULL && ptr->link->coeff > 0) ? printf(" +") : printf("");
        ptr = ptr->link;
    }
}
