#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
int C, M = 0;
int recurse = 0;
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
        A[i] = rand()%100;
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

int QuickSort1(int* A, int L, int R)
{
    int x = A[L];
    int i = L;
    int j = R;
    while (i <= j)
    {
        C++;
        while (A[i] < x)
        {
            C++;
            i++;
        }
        C++;
        while (A[j] > x)
        {
            C++;
            j--;
        }
        if (i <= j)
        {
            M += 3;
            swapArrElem(&A[i], &A[j]);
            i++;
            j--;
        }
    }
     
    if (L < j)
    {
        QuickSort1(A, L, j);
    }

    if (i < R)
    {
        QuickSort1(A, i, R);
    }

    return C + M;
}



int med(int* A, int L, int R)
{
    if (A[L] > A[(L + R) / 2])
    {
        if (A[R] > A[L])
        {
            return A[L];
        }
        return (A[(L + R)/ 2] > A[R]) ? A[(L + R) / 2] : A[R];
    }
    if (A[R] > A[(L + R) / 2])
    {
        return A[(L + R) / 2];
    }
    return (A[L] > A[R]) ? A[L] : A[R]; 

}

int QuickSort1med(int* A, int L, int R)
{
    int x = med(A, L, R);
    int i = L;
    int j = R;
    while (i <= j)
    {
        C++;
        while (A[i] < x)
        {
            C++;
            i++;
        }
        C++;
        while (A[j] > x)
        {
            C++;
            j--;
        }
        if (i <= j)
        {
            M += 3;
            swapArrElem(&A[i], &A[j]);
            i++;
            j--;
        }
    }
     
    if (L < j)
    {
        QuickSort1med(A, L, j);
    }

    if (i < R)
    {
        QuickSort1med(A, i, R);
    }

    return C + M;
}

int QuickSort1medt(int* A, int L, int R)
{
    static int max = 0;
    int x = med(A, L, R);
    int i = L;
    int j = R;
    if (recurse > max)
    {
        max = recurse;
    }
    while (i <= j)
    {
        C++;
        while (A[i] < x)
        {
            C++;
            i++;
        }
        C++;
        while (A[j] > x)
        {
            C++;
            j--;
        }
        if (i <= j)
        {
            M += 3;
            swapArrElem(&A[i], &A[j]);
            i++;
            j--;
        }
    }
    if (L < j)
    {
        recurse++;
        QuickSort1medt(A, L, j);
    }

    if (i < R)
    {
        recurse++;
        QuickSort1medt(A, i, R);
    }
    recurse++;
    if (recurse > max)
    {
        max = recurse;
    }
    recurse--;
    return max;
}

int QuickSort2(int* A, int L, int R)
{
    static int max = 0;
    if (recurse > max)
    {
        max = recurse;
    }
    while (L < R)
    {
        int x = med(A, L, R);
        int i = L;
        int j = R;
        while (i <= j)
        {
            C++;
            while (A[i] < x)
            {
                C++;
                i++;
            }
            C++;
            while (A[j] > x)
            {
                C++;
                j--;
            }
            if (i <= j)
            {
                M += 3;
                swapArrElem(&A[i], &A[j]);
                i++;
                j--;
            }
        }
        if (j - L > R - i)
        {
            recurse++;
            QuickSort2(A, L, j);
            L = i;
            recurse--;
        }
        else
        {
            recurse++;
            QuickSort2(A, i, R);
            recurse--;
            R = j;
        }
    }
    return max;
}

int main()
{
    srand(time(NULL));
    int n;
    int Inc; int Dec; int Rand;
    int* A = (int*)malloc(n * sizeof(int));
    printf("_______________________________________\n");
    printf("|___n___|____QUICK__SORTA[0](M+C)_____|\n");
    printf("|_______|___Dec___|___Inc___|___Rnd___|\n");
    for (n = 100; n <= 500; n += 100)
    {
        A = (int*)realloc(A, n * sizeof(int));
        if (A == NULL)
        {
            printf("Wrong shift\n");
        }
        fillinc(A, n);
        Inc = QuickSort1(A, 0, n - 1);
        C = 0;
        M = 0;
        filldec(A, n);
        Dec = QuickSort1(A, 0, n - 1);
        C = 0;
        M = 0;
        fillrand(A, n);
        Rand = QuickSort1(A, 0, n - 1);
        C = 0;
        M = 0;
        printf("| %5d | %7d | %7d | %7d |\n", n, Inc, Dec, Rand);
    }
    printf("|_______|_________|_________|_________|\n");

    printf("_______________________________________\n");
    printf("|___n___|____QUICK__SORTAMED(M+C)_____|\n");
    printf("|_______|___Dec___|___Inc___|___Rnd___|\n");
    for (n = 100; n <= 500; n += 100)
    {
        A = (int*)realloc(A, n * sizeof(int));
        if (A == NULL)
        {
            printf("Wrong shift\n");
        }
        fillinc(A, n);
        Inc = QuickSort1med(A, 0, n - 1);
        C = 0;
        M = 0;
        filldec(A, n);
        Dec = QuickSort1med(A, 0, n - 1);
        C = 0;
        M = 0;
        fillrand(A, n);
        Rand = QuickSort1med(A, 0, n - 1);
        C = 0;
        M = 0;
        printf("| %5d | %7d | %7d | %7d |\n", n, Inc, Dec, Rand);
    }
    printf("|_______|_________|_________|_________|\n");
    //
    int Dec1, Inc1, Rand1;
    printf("_____________________________________________________________________\n");
    printf("|___n___|____QUICK__SORT1_(M + C)_____|____QUICK__SORT2_(M + C)_____|\n");
    printf("|_______|___Dec___|___Inc___|___Rnd___|___Dec___|___Inc___|___Rnd___|\n");
    for (n = 100; n <= 500; n += 100)
    {
        A = (int*)realloc(A, n * sizeof(int));
        if (A == NULL)
        {
            printf("Wrong shift\n");
        }
        fillinc(A, n);
        Inc = QuickSort1medt(A, 0, n - 1);
        recurse = 0;
        filldec(A, n);
        Dec = QuickSort1medt(A, 0, n - 1);
        recurse = 0;
        fillrand(A, n);
        Rand = QuickSort1medt(A, 0, n - 1);
        recurse = 0;
        Inc1 = QuickSort2(A, 0, n - 1);
        recurse = 0;
        filldec(A, n);
        Dec1 = QuickSort2(A, 0, n - 1);
        recurse = 0;
        fillrand(A, n);
        Rand1 = QuickSort2(A, 0, n - 1);
        recurse = 0;
        printf("| %5d | %7d | %7d | %7d | %7d | %7d | %7d |\n", n, Inc, Dec, Rand, Inc1, Dec1, Rand1);
    }
    printf("|_______|_________|_________|_________|_________|_________|_________|");
    free(A);
    return 0;
}