#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <string.h>
struct spis
{
    int data;
    struct spis* next;
};


void fillinc(struct spis* A, struct spis* head)
{
    int i = 0;
    for (A = head -> next; A; A = A -> next, i++)
    {
        A -> data = 1 + i;
    }
}
void filldec(struct spis* A, struct spis* head, int size)
{
    int flag = 0;
    for (A = head -> next; flag < size, A; flag++, A = A -> next)
    {
        A -> data = size - 1 - flag + 1;
    }
}

void fillrand(struct spis* A, struct spis* head)
{
    for (A = head -> next; A; A = A -> next)
    {
        A -> data = rand()%100;
    }
}
int checksum(struct spis* A, struct spis* head)
{
    int sum = 0;
    for (A = head -> next; A; A = A -> next)
    {
        sum += A -> data;
    }
    return sum;
}
int runnumber(struct spis* A, struct spis* head)
{
    int seria = 0;
    for (A = head -> next; A -> next; A = A -> next)
    {
        if (A -> data > A -> next -> data)
        {
            seria++;
        }
 
    }
    return seria+1;
}
void printspis(struct spis* A, struct spis* head)
{
    int flag = 0;
    for (A = head -> next; A; A = A -> next, flag++)
    {
        printf("%i ", A -> data);
    }
    printf("\n");
}

void deletespis(struct spis* A, struct spis* head, struct spis* pp)
{
    for (A = head; A; A = pp)
    {
        pp = A -> next;
        delete(A);
    }
}

void create_stack(struct spis* A, struct spis* head, int size)
{
    int i = 0;
    do
    {
        A = new spis;
        A -> next = head -> next;
        head -> next = A;
        i++;
    } while (i < size);
}

void create_order(struct spis* A, struct spis* head, int size, struct spis* tail)
{
    int i = 0;
    for (A = head -> next; i < size; i++, A = A -> next)
    {
        A = new spis;
        tail -> next = A;
        tail = A;
    }
    tail -> next = NULL;
}

int main()
{
    srand(time(NULL));
    struct spis *head,*p, *tail, *pp;
    head = tail = new spis;
    int n = 10;
    //Order
    create_order(p, head, n, tail);
    fillinc(p, head);    
    printspis(p, head);
    filldec(p, head, n);
    printspis(p , head);
    fillrand(p, head);
    printspis(p, head);
    printf("Control Sum: %i\n", checksum(p, head));
    printf("Seria: %i\n", runnumber(p, head));
    deletespis(p, head, pp);
    //Stack
    /*create_stack(p, head, n);
    fillinc(p, head);    
    printspis(p, head);
    filldec(p, head, n);
    printspis(p , head);
    fillrand(p, head);
    printspis(p, head);
    printf("Control Sum: %i\n", checksum(p, head));
    printf("Seria: %i\n", runnumber(p, head));
    deletespis(p, head, pp);*/
    return 0;
}