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

struct PhoneBook
{
    char* Name; // "Jade"
    char* Surname; // "Haltor"
    long PhoneNumber; //13848594827
    char* HomeAdress; // "Saint Peterspurg 18"
    char* FavouriteFood; //Lasagna
};

void get_Number(struct PhoneBook* book, int sizeofbook)
{
    for (int i = 0; i < sizeofbook; i++)
    {
        book[i].PhoneNumber = 835600 + i;

    }
}

void get_Name(struct PhoneBook* book, int sizeofbook)
{
    char namehalf1[5];
    for (int i = 0; i < sizeofbook; i++)
    {
        book[i].Name = (char*)malloc(15*sizeof(char));
        char half1 = (65+i%26); char half2 = (97 + rand()%25);
        char half3 = (97+(i)%26); char half4 = (97+2*(i%11+rand()%3));
        namehalf1[0] = half1; namehalf1[1] = half2;
        namehalf1[2] = half3; namehalf1[3] = half4;
        strcpy(book[i].Name, namehalf1);
    }
}

void free_Name(struct PhoneBook* book, int sizeofbook)
{
    for (int i = 0; i < sizeofbook; i++)
    {
        free(book[i].Name);
    }
}

void get_SurName(struct PhoneBook* book, int sizeofbook)
{
    char namehalf1[10];
    for (int i = 0; i < sizeofbook; i++)
    {
        book[i].Surname = (char*)malloc(20 * sizeof(char));
        char half1 = (65+(i)%26); char half2 = (97 + rand()%26);
        char half3 = (97+(i)%26); char half4 = (97+2*(i%10+rand()%3))%122;
        char half5 = (97+i%11*rand()%3)%122; char half6 = (97 + rand()%20)%122;
        char half7 = (97+(i%26))%122; char half8 = (97+2*(i%12+1))%122;
        namehalf1[0] = half1; namehalf1[1] = half2;
        namehalf1[2] = half3; namehalf1[3] = half4;
        namehalf1[4] = half5; namehalf1[5] = half6;
        namehalf1[6] = half7; namehalf1[7] = half8;
        strcpy(book[i].Surname, namehalf1);
    }
}
void free_SurName(struct PhoneBook* book, int sizeofbook)
{
    for (int i = 0; i < sizeofbook; i++)
    {
        free(book[i].Surname);
    }
}

void get_FavFood(struct PhoneBook* book, int sizeofbook)
{
    char namehalf1[10];
    for (int i = 0; i < sizeofbook; i++)
    {
        book[i].FavouriteFood = (char*)malloc(20 * sizeof(char));
        char half1 = (65+(i)%26); char half2 = (97 + rand()%26);
        char half3 = (97+(i)%26); char half4 = (97+2*(i%10+rand()%3))%122;
        char half5 = (97+i%11*rand()%3)%122; char half6 = (97 + rand()%20)%122;
        char half7 = (97+(i%26))%122; char half8 = (97+2*(i%12+1))%122;
        namehalf1[0] = half1; namehalf1[2] = half2;
        namehalf1[3] = half3; namehalf1[1] = half4;
        namehalf1[4] = half5; namehalf1[6] = half6;
        namehalf1[7] = half7; namehalf1[5] = half8;
        strcpy(book[i].FavouriteFood, namehalf1);
    }
}
void free_FavFood(struct PhoneBook* book, int sizeofbook)
{
    for (int i = 0; i < sizeofbook; i++)
    {
        free(book[i].FavouriteFood);
    }
}

void get_Adress(struct PhoneBook* book, int sizeofbook)
{
    char namehalf1[12];
    for (int i = 0; i < sizeofbook; i++)
    {
        book[i].HomeAdress = (char*)malloc(20 * sizeof(char));
        char half1 = (65+(i)%26); char half2 = (97 + rand()%26);
        char half3 = (97+(i)%26); char half4 = (97+2*(i%10+rand()%3))%122;
        char half5 = (97+i%11*rand()%3)%122; char half6 = (97 + rand()%20)%122;
        char half7 = (97+(i%26))%122; char half8 = (97+2*(i%12+1))%122;
        itoa((i + 1) * (1+rand()%10), namehalf1, 10);
        namehalf1[1] = ' ';
        namehalf1[2] = half1; namehalf1[3] = half2;
        namehalf1[4] = half3; namehalf1[5] = half4;
        namehalf1[6] = half5; namehalf1[7] = half6;
        namehalf1[8] = half7; namehalf1[9] = half8;
        strcpy(book[i].HomeAdress, namehalf1);
    }
}
void free_Adress(struct PhoneBook* book, int sizeofbook)
{
    for (int i = 0; i < sizeofbook; i++)
    {
        free(book[i].HomeAdress);
    }
}

int ShellSortIncNum(struct PhoneBook* A, int n, int* Incind)
{
    long t;
    int j;
    int k = 1;
    for (int i = 1; i < log(n) - 1; i++) {
		k = 2 * k + 1;
	}
    for (k; k > 0; k = (k - 1) / 2)
    {
        for (int i = k; i < n; i++)
        {
            t = A[Incind[i]].PhoneNumber;
            for (j = i; j >= k && A[Incind[j - k]].PhoneNumber > t; j -= k)
            {
                Incind[j] = Incind[j - k];
            }
            A[j].PhoneNumber = t;
        }
    }
    return 0;
}

int ShellSortIncName(struct PhoneBook* A, int n, int* Incind)
{
    char t;
    int j;
    int k = 1;
    int ML = 0;
    for (int i = 1; i < log(n) - 1; i++) {
		k = 2 * k + 1;
	}
    for (k; k > 0; k = (k - 1) / 2)
    {
        for (int i = k; i < n; i++)
        {
            t = A[Incind[i]].Name[ML];
            for (j = i; j >= k && A[Incind[j - k]].Name[ML] > t; j -= k)
            {
                if (A[Incind[j - k]].Name[ML] == t)
                {
                    ML++;
                }
                Incind[j] = Incind[j - k];
            }
            A[j].Name[ML] = t;
        }
    }
    return 0;
}

int BSearch2_PN(long key, struct PhoneBook* A, int n, int* Incr)
{
    int L = 0;
    int R = n - 1;
    int found = 0;
    while (L < R)
    {
        int m = floor((L + R) / 2);
        C++;
        if (A[Incr[m]].PhoneNumber < key)
        {
            L = m + 1;
        }
        else
        {
            R = m;
        }
    }
    if (key == A[Incr[R]].PhoneNumber)
    {
        printf("Found number: %i\n", A[Incr[R]].PhoneNumber);
    }
    else
    {
        printf("Last Num: %i\n", A[Incr[R]].PhoneNumber);
    }
}

int BSearch2_Name(char* key, struct PhoneBook* A, int n, int* Incr)
{
    int L = 0;
    int R = n - 1;
    int found = 0;
    while (L < R)
    {
        int m = floor((L + R) / 2);
        C++;
        if (strcmp(A[Incr[m]].Name, key) < 0)
        {
            L = m + 1;
        }
        else
        {
            R = m;
        }
    }
    if (strcmp(A[Incr[R]].Name, key) == 0)
    {
        printf("Found Name: %s\n", A[Incr[R]].Name);
    }
    else
    {
        printf("Last Name: %s\n", A[Incr[R]].Name);
    }
}
int main()
{
    srand(time(NULL));
    int* Dec;
    int* Inc;
    struct PhoneBook* phonebook;
    int sizeof_book = 5;
    phonebook = (struct PhoneBook*)malloc(sizeof_book * sizeof(struct PhoneBook));
    Dec = (int*)malloc(sizeof_book * sizeof(int));
    Inc = (int*)malloc(sizeof_book * sizeof(int));
    for (int i = 0; i < sizeof_book; i++)
    {
        Dec[i] = i;
        Inc[i] = i;
    }
    //ENTER Struct Data
    get_Number(phonebook, sizeof_book);
    get_Name(phonebook, sizeof_book);
    get_SurName(phonebook, sizeof_book);
    get_FavFood(phonebook, sizeof_book);
    get_Adress(phonebook, sizeof_book);
    //Sort To Phone Number
    ShellSortIncNum(phonebook, sizeof_book, Inc);
    //INC TO DEC
    for (int i = sizeof_book - 1; i >= 0; i--)
    {
        Dec[sizeof_book - i - 1] = Inc[i];
    }
    printf("PHONEKEY:\n\n");
    printf("Decreasing:\n\n");
    for (int i = 0; i < sizeof_book; i++)
    {
        printf("Phone Number: %ld\nName: %s\nSurname: %s\nAdress: %s\nFavFood: %s\n", phonebook[Dec[i]].PhoneNumber, 
        phonebook[Dec[i]].Name, phonebook[Dec[i]].Surname, phonebook[Dec[i]].HomeAdress, 
        phonebook[Dec[i]].FavouriteFood);
    }
    printf("\nIncreasing:\n\n");
    for (int i = 0; i < sizeof_book; i++)
    {
        printf("Phone Number: %ld\nName: %s\nSurname: %s\nAdress: %s\nFavFood: %s\n", phonebook[Inc[i]].PhoneNumber, 
        phonebook[Inc[i]].Name, phonebook[Inc[i]].Surname, phonebook[Inc[i]].HomeAdress, 
        phonebook[Inc[i]].FavouriteFood);
    }
    //INC N DEC = i;
    for (int i = 0; i < sizeof_book; i++)
    {
        Dec[i] = i;
        Inc[i] = i;
    }
    //INC TO DEC
    printf("\nNAMEKEY\n\n");
    ShellSortIncName(phonebook, sizeof_book, Inc);
    for (int i = sizeof_book - 1; i >= 0; i--)
    {
        Dec[sizeof_book - i - 1] = Inc[i];
    }
    printf("Decreasing:\n\n");
    for (int i = 0; i < sizeof_book; i++)
    {
        printf("Phone Number: %ld\nName: %s\nSurname: %s\nAdress: %s\nFavFood: %s\n", phonebook[Dec[i]].PhoneNumber, 
        phonebook[Dec[i]].Name, phonebook[Dec[i]].Surname, phonebook[Dec[i]].HomeAdress, 
        phonebook[Dec[i]].FavouriteFood);
    }
    printf("\nIncreasing:\n\n");
    for (int i = 0; i < sizeof_book; i++)
    {
        printf("Phone Number: %ld\nName: %s\nSurname: %s\nAdress: %s\nFavFood: %s\n", phonebook[Inc[i]].PhoneNumber, 
        phonebook[Inc[i]].Name, phonebook[Inc[i]].Surname, phonebook[Inc[i]].HomeAdress, 
        phonebook[Inc[i]].FavouriteFood);
    }
    //BinSearch
    BSearch2_PN(835600, phonebook, sizeof_book, Inc);
    char keyz[5] = "Dqdi";
    BSearch2_Name(keyz, phonebook, sizeof_book, Inc);
    //Free Memory
    free_Name(phonebook, sizeof_book);
    free_SurName(phonebook, sizeof_book);
    free_FavFood(phonebook, sizeof_book);
    free_Adress(phonebook, sizeof_book);
    free(Dec);
    free(Inc);
    free(phonebook);
    return 0;
}