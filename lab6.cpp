#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
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

int InsertSort(int* A, int size);
int keysorts(int size);
int ShellSort(int* A, int n);
int keysorts1(int size);
int ShellSort1(int* A, int n);
int main()
{
    srand(time(NULL));
	int K1, K, Sh, I;
    int n;
	printf("___________________________________________\n");
	printf("|___________________LAB6__________________|\n");
	printf("|__n__|KSort|__INSERTSORT__|__SHELL SORT__|\n");
	for (n = 100; n <= 500; n += 100) {
		int* A;
		A = (int*)malloc(n * sizeof(int));
		if (A == NULL) {
			printf("can't memory reserved");
			return 1;
		}
		fillrand(A, n);
		I = InsertSort(A, n);
        fillrand(A, n);
        K = keysorts(n);
        Sh = ShellSort(A, n);
		if (n == 100) printf("| %d |  %d  |     %d     |     %d     |\n", n, K, I, Sh);
		if (n == 200) printf("| %d |  %d  |     %d    |     %d     |\n", n,  K, I, Sh);
		if (n == 300) printf("| %d |  %d  |     %d    |     %d     |\n", n, K, I, Sh);
		if (n == 400) printf("| %d |  %d  |     %d    |     %d     |\n", n, K, I, Sh);
		if (n == 500) printf("| %d |  %d  |     %d   |     %d    |\n", n, K, I, Sh);
		free(A);
		A = NULL;
	}
	printf("|_____|_____|______________|______________|\n");
    //lab6 ++
    printf("__________________________________________________ \n");
	printf("|_____________________LAB6+______________________|\n");
	printf("|__n__|KSort|__SHELL SORT__|KSortO|__SHELL SORT__|\n");
	for (n = 100; n <= 500; n += 100) {
		int* A;
		A = (int*)malloc(n * sizeof(int));
		if (A == NULL) {
			printf("can't memory reserved");
			return 1;
		}
		fillrand(A, n);
		I = ShellSort(A, n);
        K = keysorts(n);
        fillrand(A, n);
        Sh = ShellSort1(A, n);
        K1 = keysorts1(n);
		if (n == 100) printf("| %d |  %d  |     %d     |   %d  |     %d     |\n", n, K, I, K1, Sh);
		if (n == 200) printf("| %d |  %d  |     %d     |   %d  |     %d     |\n", n,  K, I, K1, Sh);
		if (n == 300) printf("| %d |  %d  |     %d     |   %d  |     %d     |\n", n, K, I, K1, Sh);
		if (n == 400) printf("| %d |  %d  |     %d     |   %d  |     %d    |\n", n, K, I, K1, Sh);
		if (n == 500) printf("| %d |  %d  |     %d    |   %d  |     %d    |\n", n, K, I, K1, Sh);
		free(A);
		A = NULL;
	}
	printf("|_____|_____|______________|______|______________|\n");
}

int InsertSort(int* A, int size)
{
    C = 0;
    M = 0;
    for (int i = 1; i < size; i++)
    {
        int t = A[i];
        int j = i - 1;
        C++;
        while (j >= 0 && t < A[j])
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

int keysorts(int size)
{
    int k = 1, num_ofkeys = 0;
	for (int i = 1; i < log(size) - 1; i++) {
		k = 2 * k + 1;
		num_ofkeys++;
	}
	return num_ofkeys;
}

int keysorts1(int size)
{
    int k = 1, num_ofkeys = 0;
	for (int i = 1; i < log(size) - 1; i++) {
		k = 10 * k + 1;
		num_ofkeys++;
	}
	return num_ofkeys;
}
int ShellSort(int* A, int n)
{
    C = 0, M = 0;
    int t, j;
    int k = 1;
    for (int i = 1; i < log(n) - 1; i++) {
		k = 2 * k + 1;
	}
    for (k; k > 0; k = (k - 1) / 2)
    {
        for (int i = k; i < n; i++)
        {
            t = A[i];
            C++;
            for (j = i; j >= k && A[j - k] > t; j -= k)
            {
                C++;
                A[j] = A[j - k];
                M++;
            }
            A[j] = t;
            M++;
        }
    }
    return C + M;
}

int ShellSort1(int* A, int n)
{
    C = 0, M = 0;
    int t, j;
    int k = 1;
    for (int i = 1; i < log(n) - 1; i++) {
		k = 10 * k + 1;
	}
    for (k; k > 0; k = (k - 1) / 10)
    {
        for (int i = k; i < n; i++)
        {
            t = A[i];
            C++;
            for (j = i; j >= k && A[j - k] > t; j -= k)
            {
                C++;
                A[j] = A[j - k];
                M++;
            }
            A[j] = t;
            M++;
        }
    }
    return C + M;
}