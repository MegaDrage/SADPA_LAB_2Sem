#include <stdio.h>
#include <stdlib.h>

struct spis
{
    spis *next;
    int data;
};

spis *Spis_inc_queue(int n)
{
    spis *p = NULL, *head = NULL, *tail = NULL;
    int i, S;
    for (i = 0; i < n; i++)
    {
        S = i;
        p = new spis;
        p->data = S;
        p->next = NULL;
        if (head != NULL)
            tail->next = p;
        else
        {
            head = p;
        }
        tail = p;
    }
    return head;
}

spis *Spis_dec_queue(int n)
{
    spis *p = NULL, *head = NULL, *tail = NULL;
    int i, S;
    for (i = 0; i < n; i++)
    {
        S = n - i;
        p = new spis;
        p->data = S;
        p->next = NULL;
        if (head != NULL)
            tail->next = p;
        else
        {
            head = p;
        }
        tail = p;
    }
    return head;
}

spis *Spis_rand_queue(int n)
{
    spis *p = NULL, *head = NULL, *tail = NULL;
    int i, S;
    for (i = 0; i < n; i++)
    {
        S = rand() % 100;
        p = new spis;
        p->data = S;
        p->next = NULL;
        if (head != NULL)
            tail->next = p;
        else
        {
            head = p;
        }
        tail = p;
    }
    return head;
}

spis *Spis_inc_stack(int n)
{
    spis *p = NULL, *head = NULL;
    int i, S;
    for (i = 0; i < n; i++)
    {
        S = n - i;
        p = new spis;
        p->data = S;    // выделение памяти по адресу p
        p->next = head; // добавление элемента
        head = p;       // в начало стека
    }
    return head;
}

spis *Spis_dec_stack(int n)
{
    spis *p = NULL, *head = NULL;
    int i, S;
    for (i = 0; i < n; i++)
    {
        S = i;
        p = new spis;
        p->data = S;
        p->next = head;
        head = p;
    }
    return head;
}

spis *Spis_rand_stack(int n)
{
    spis *p = NULL, *head = NULL;
    int i, S;
    for (i = 0; i < n; i++)
    {
        S = rand() % 100;
        p = new spis;
        p->data = S;
        p->next = head;
        head = p;
    }
    return head;
}

void PrintSpis(spis *head)
{
    spis *p;
    printf("\n");
    for (p = head; p; p = p->next)
        printf("%d ", p->data);
    printf("\n");
}

int Sum(spis *head)
{
    int S = 0;
    spis *p;
    for (p = head; p; p = p->next)
        S += p->data;
    return S;
}

int Seriya(spis *head)
{
    int S = 0;
    spis *p;
    if (head == NULL)
        return 0;
    for (p = head; p->next; p = p->next)
        if (p->data > p->next->data)
            S++;
    return S + 1;
}

spis *delit_Spis(spis *head)
{
    spis *p;
    if (head != NULL)
    {
        for (p = head; p; p = p->next)
        {
            head = p->next;
            delete p;
        }
    }
    return head;
}

int main()
{
    struct spis *i;
    struct spis *d;
    struct spis *r;
    printf("Enter n: ");
    int n;
    scanf("%d", &n);
    printf("Inc");
    i = Spis_inc_stack(n);
    PrintSpis(i);
    printf("sum: %d | series: %d\n", Sum(i), Seriya(i));

    printf("Dec");
    d = Spis_dec_stack(n);
    PrintSpis(d);
    printf("sum: %d | series: %d\n", Sum(d), Seriya(d));

    printf("rand");
    r = Spis_rand_stack(n);
    PrintSpis(r);
    printf("sum: %d | series: %d\n", Sum(r), Seriya(r));

    printf("\nQueue");
    i = Spis_inc_queue(n);
    PrintSpis(i);
    printf("sum: %d | series: %d\n", Sum(i), Seriya(i));

    printf("Dec");
    d = Spis_dec_queue(n);
    PrintSpis(d);
    printf("sum: %d | series: %d\n", Sum(d), Seriya(d));

    printf("rand");
    r = Spis_rand_queue(n);
    PrintSpis(r);
    printf("sum: %d | series: %d\n", Sum(r), Seriya(r));
    r = delit_Spis(r);
    printf("Deleted spis");
    PrintSpis(r);
}
