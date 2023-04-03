#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
int C, M = 0;
void fillinc(int* A, int n)
{
    for (int i = 0; i < n; i++)
    {
        A[i] = i+1; 
    }
}
void filldec(int* A, int n)
{
    for (int i = 0; i < n; i++)
    {
        A[i] = n - 1 - i+1;
    }
}

void fillrand(int* A, int n)
{
    for (int i = 0; i < n; i++)
    {
        A[i] = rand()%10000;
    }
}
int checksum(int* A, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
    }
    return sum;
}
int runnumber(int* A, int n)
{
    int seria = 0;
    int lenght = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] > A[i+1])
        {
            seria++;
        }
 
    }
    return seria+1;
}
void printmas(int* A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%i ", A[i]);
    }
    printf("\n");
}
void swapArrElem(int* A, int* B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
}

int HeapMake(int* A, int n, int left)
{
    int c = 0; 
    int m = 0;
    int x = A[left];
    m++;
    int i = left;
    while(1)
    {
        int j = 2 * i;
        if (j > n)
        {
            break;
        }
        c++;
        if ((j < n - 1) && (A[j + 1] >= A[j]))
        {
            j++;
        }
        c++;
        if (x >= A[j])
        {
            break;
        }
        m++;
        A[i] = A[j];
        i = j;
    }
    m++;
    A[i] = x;
    return c + m;
}

int HeapSort(int* A, int n)
{
    C, M = 0;
    int K = 0;
    int L = floor(n / 2);
    while (L >= 0)
    {
        K += HeapMake(A, n, L);
        L--;
    }
    int R = n - 1;
    while(R > 1)
    {
        M += 3;
        swapArrElem(&A[0], &A[R]);
        R--;
        K += HeapMake(A, R, 0);
    }
    return C + M + K;
}

int main()
{
    srand(time(NULL));
    int n;
    int Inc; int Dec; int Rand;
    int* A = (int*)malloc(n * sizeof(int));
    printf("_________________________________\n");
    printf("|___n___|____HEAP_SORT_(M+C)____|\n");
    printf("|_______|__Dec__|__Inc__|__Rnd__|\n");
    for (n = 100; n <= 500; n += 100)
    {
        A = (int*)realloc(A, n * sizeof(int));
        if (A == NULL)
        {
            printf("Wrong shift\n");
        }
        fillinc(A, n);
        Inc = HeapSort(A, n);
        filldec(A, n);
        Dec = HeapSort(A, n);
        fillrand(A, n);
        Rand = HeapSort(A, n);
        printf("| %5d | %5d | %5d | %5d |\n", n, Inc, Dec, Rand);
    }
    printf("|_______|_______|_______|_______|");
    free(A);
    return 0;
}