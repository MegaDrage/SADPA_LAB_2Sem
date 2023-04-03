#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
        A[i] = rand();
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

int BubbleSort(int* A, int size);
int SelectSort(int* A, int size);
int InsertSort(int* A, int size);
int ShakerSort(int* A, int size);
int main()
{
	int Se, B, Sh, I;
    int n;
	printf(" _________________________________________ \n");
	printf("|___________________LAB5__________________|\n");
	printf("|__n__|_Select_|_BubleS_|_Shaker_|_Insert_|\n");
	for (n = 100; n <= 500; n += 100) {
		int* A;
		A = (int*)malloc(n * sizeof(int));
		if (A == NULL) {
			printf("can't memory reserved");
			return 1;
		}
		fillrand(A, n);
		Se = SelectSort(A, n);
		fillrand(A, n);
		B = BubbleSort(A, n);
		fillrand(A, n);
		Sh = ShakerSort(A, n);
		fillrand(A, n);
		I = InsertSort(A, n);
		if (n == 100) printf("| %d |   %d |  %d |  %d |   %d |\n", n, Se, B, Sh, I);
		if (n == 200) printf("| %d |  %d |  %d |  %d |  %d |\n", n, Se, B, Sh, I);
		if (n == 300) printf("| %d |  %d | %d |  %d |  %d |\n", n, Se, B, Sh, I);
		if (n == 400) printf("| %d |  %d | %d | %d |  %d |\n", n, Se, B, Sh, I);
		if (n == 500) printf("| %d | %d | %d | %d | %d |\n", n, Se, B, Sh, I);
		free(A);
		A = NULL;
	}
	printf("|_____|________|________|________|________|\n");
}

int SelectSort(int* A, int size)
{
    int k = 0;
    int i = 0;
    int j = 0;
    C = 0;
    M = 0;
    for (i = 0; i < size; i++)
    {
        k = i;
        for (j = i+1; j < size; j++)
        {
        	C++;
            if (A[k] > A[j])
            {
                k = j;
            }
        }
        C++;
        if (i != k)
        {
	        swapArrElem(&A[i], &A[k]);
	        M += 3;
    	}
    }
    return C + M;
}

int BubbleSort(int* A, int size)
{
    C = 0;
    M = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = size - 1; j > 0; j--)
        {
            C++;
            if(A[j] < A[j - 1])
            {
                swapArrElem(&A[j], &A[j - 1]);
                M+=3;
            }
        }
    }
    return C + M;
}

int ShakerSort(int* A, int size)
{
    C = 0;
    M = 0;
    int L = 0;
    int R = size - 1;
    int k = size - 1;
    do
    {
        for (int j = R; j > L; j--)
        {
            C++;
            if (A[j] < A[j - 1])
            {
                swapArrElem(&A[j], &A[j - 1]);
                M += 3;
                k = j;
            }
        }
        L = k;
        for (int j = L; j < R; j++)
        {
            C++;
            if (A[j] > A[j + 1])
            {
                swapArrElem(&A[j], &A[j + 1]);
                M += 3;
                k = j;   
            }
        }
        R = k;
    } while(L < R);
    
    return C + M;
}

int InsertSort(int* A, int size)
{
    C = 0;
    M = 0;
    for (int i = 0; i < size; i++)
    {
        int t = A[i];
        int j = i - 1;
        C++;
        while (j > 0 && t < A[j])
        {
            C++;
            A[j + 1] = A[j];
            M++;
            j = j - 1;
        }
        A[j + 1] = t;
        M++;
    }
    return C + M;
}