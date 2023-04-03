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
int ShellSort(int* A, int n);
int BSearch1(int key, int* A, int n);
int BSearch2(int key, int* A, int n);
int main()
{
    srand(time(NULL));
	int K1, K, Sh, I;
    int n;
    int key;
    printf("Enter key:");
    scanf("%i", &key);
	printf("___________________________________________\n");
	printf("|___________________LAB7__________________|\n");
	printf("|__n__|___Bin Search1___|___Bin Search2___|\n");
	for (n = 100; n <= 1000; n += 100) {
		int* A;
		A = (int*)malloc(n * sizeof(int));
		if (A == NULL) {
			printf("can't memory reserved");
			return 1;
		}
        fillrand(A,n);
        ShellSort(A, n);
        I = BSearch1(key, A, n);
        Sh = BSearch2(key, A, n);
		if (n == 100) printf("| %d |        %d       |       %d         |\n", n, I, Sh);
		if (n == 200) printf("| %d |        %d       |       %d         |\n", n, I, Sh);
		if (n == 300) printf("| %d |        %d       |       %d         |\n", n, I, Sh);
		if (n == 400) printf("| %d |        %d       |       %d         |\n", n,  I, Sh);
		if (n == 500) printf("| %d |        %d       |       %d         |\n", n, I, Sh);
        if (n == 600) printf("| %d |        %d       |       %d        |\n", n, I, Sh);
		if (n == 700) printf("| %d |        %d       |       %d        |\n", n, I, Sh);
		if (n == 800) printf("| %d |        %d       |       %d        |\n", n, I, Sh);
		if (n == 900) printf("| %d |        %d       |       %d        |\n", n,  I, Sh);
		if (n == 1000) printf("| %d|        %d       |       %d        |\n", n, I, Sh);
		free(A);
		A = NULL;
	}
	printf("|_____|_________________|_________________|\n");
    printf("__________________________________________________ \n");
	/*printf("|_____________________LAB6+______________________|\n");
	printf("|__n__|KSort|__SHELL SORT__|KSortO|__SHELL SORT__|\n");
	for (n = 100; n <= 500; n += 100) {
		int* A;
		A = (int*)malloc(n * sizeof(int));
		if (A == NULL) {
			printf("can't memory reserved");
			return 1;
		}
		if (n == 100) printf("| %d |  %d  |     %d     |   %d  |     %d     |\n", n, K, I, K1, Sh);
		if (n == 200) printf("| %d |  %d  |     %d     |   %d  |     %d     |\n", n,  K, I, K1, Sh);
		if (n == 300) printf("| %d |  %d  |     %d     |   %d  |     %d     |\n", n, K, I, K1, Sh);
		if (n == 400) printf("| %d |  %d  |     %d     |   %d  |     %d    |\n", n, K, I, K1, Sh);
		if (n == 500) printf("| %d |  %d  |     %d    |   %d  |     %d    |\n", n, K, I, K1, Sh);
		free(A);
		A = NULL;
	}
	printf("|_____|_____|______________|______|______________|\n");*/
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

int BSearch1(int key, int* A, int n)
{
    C = 0;
    int L = 0;
    int R = n - 1;
    int found = 0;
    while (L <= R)
    {
        int m = round((L + R) / 2);
        C++;
        if (A[m] == key)
        {
            //printf("Found: %i\n", A[m]);
            return C;
        }
        C++;
        if (A[m] < key)
        {
            L = m + 1;
        }
        else
        {
            R = m - 1;
        }
    }
    return C;
}

int BSearch2(int key, int* A, int n)
{
    C = 0;
    int L = 0;
    int R = n - 1;
    int found = 0;
    while (L < R)
    {
        int m = round((L + R) / 2);
        C++;
        if (A[m] < key)
        {
            L = m + 1;
        }
        else
        {
            R = m;
        }
    }
    if (key == A[R])
    {
        //printf("Found number: %i\n", A[R]);
    }
    else
    {
        //printf("Last Num: %i\n", A[R]);
    }
    return C;
}