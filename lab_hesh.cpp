#include <iostream.h>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <conio.h>
     
int collisions_line = 0, collisions_quad = 0;    
const int TABLE_SIZE = 20;

struct Node {
    int key;
    Node* next;
    Node(int k) {
        key = k;
        next = NULL;
    }
};

Node** table1 = new Node*[TABLE_SIZE];
bool* isOccupied = new bool[TABLE_SIZE];
int *table2 = new int[TABLE_SIZE];
int *table3 = new int[TABLE_SIZE];

int hash_int(int key) {
    return key % TABLE_SIZE;
}

int hash_int_mul(int key) {
    double A = 0.618;
    int h = TABLE_SIZE * fmod(key * A, 1);
    return h;
}

void insert1(int key, Node** table1) {
    int index = hash_int(key);
    Node* node = new Node(key);

    if(table1[index] == NULL)
        table1[index] = node;
    else {
        Node* temp = table1[index];
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = node;
    }
}

void insert2(int key, int *table2, bool *isOccupied) {
    int index = hash_int(key);
    if(isOccupied[index]) {
        collisions_line++;
        int i = (index + 1) % TABLE_SIZE;
        while(i != index && isOccupied[i]) {
            i = (i + 1) % TABLE_SIZE;
        }
        if(i == index) {
            cout << "Error: Table is full." << endl;
            return;
        }
        index = i;
    }
    table2[index] = key;
    isOccupied[index] = true;
}

// void insert2(int key, int *table2, bool *isOccupied) {
//     int index = hash_int(key);
//     int d = 1;
//     int index0 = index;
//     while(1) {
//         if (table2[index] == index) {
//             break;
//         }
//         if (table2[index] == 0) {
//             table2[index] = key;
//             break;
//         }
//         if (d >= TABLE_SIZE) {
//             break;
//         }
//         collisions_line++;
//         index = index0 + d;   
//         if (index >= TABLE_SIZE) {
//             index = index - TABLE_SIZE;
//         }
//         d++;
//     }
// }

void insert3(int key, int *table3) {
    int index = hash_int(key);
    int d = 1;
    while(1) {
        if (table3[index] == index) {
            break;
        }
        if (table3[index] == 0) {
            table3[index] = key;
            break;
        }
        if (d >= TABLE_SIZE) {
            break;
        }
        collisions_quad++;
        index = index + d;   
        if (index >= TABLE_SIZE) {
            index = index - TABLE_SIZE;
        }
        d = d + 2;
    }
}

void search(int key, Node **table1) {
    int index = hash_int(key);
    Node* temp = table1[index];

    while(temp != NULL && temp->key != key)
        temp = temp->next;

    if(temp == NULL)
        cout << "Element with key " << key << " not found." << endl;
    else
        cout << "Element with key " << key << " found at slot " << index << "." << endl;
}

void display1(Node **table1) {
    for(int i = 0; i < TABLE_SIZE; i++) {
        cout << i << ": ";
        Node* temp = table1[i];
        while(temp != NULL) {
            cout << temp->key << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void display2(int *table2, bool *isOccupied) {
    for(int i = 0; i < TABLE_SIZE; i++) {
        cout << "| " << i << "\t       ";
        cout << "| " << table2[i] << "\t      |" <<"\n";
    }
}

void display3(int *table3, bool *isOccupied) {
    for(int i = 0; i < TABLE_SIZE; i++) {
        cout << "| " << i << "\t       ";
        cout << "| " << table3[i] << "\t      |" << "\n";
    }
}

int main() {
    srand(time(NULL));

    int rn;

    for (int i = 0; i < TABLE_SIZE; i++) {
        table1[i] = NULL;
        isOccupied[i] = false;
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        rn = rand() % 30;
        insert1(rn, table1);
        insert2(rn, table2, isOccupied);
        insert3(rn, table3);
    }

    cout << "HashTable:" << endl;
    display1(table1);

    search(2, table1);
    search(6, table1);

    cout << "\n###############################################################################\n";

    cout << "\nHash table line\n\n";
    cout << ("-------------------------------\n");
    cout << ("| Cell numbers |    Symbols   |\n");
    cout << ("-------------------------------\n");
    display2(table2, isOccupied);
    cout << ("-------------------------------\n");
    cout << endl;

    cout << "\nHash table quad\n\n";
    cout << ("-------------------------------\n");
    cout << ("| Cell numbers |    Symbols   |\n");
    cout << ("-------------------------------\n");
    display3(table3, isOccupied);
    cout << ("-------------------------------\n");
    cout << endl;

    cout << "\n###############################################################################\n\n";    

    cout << ("-----------------------------------------------------------\n");
    cout << ("| Hash- | Number of  |         Number of collisions       |\n");
    cout << ("| table | original   |-------------------------------------\n");
    cout << ("| size  | characters | Line probs       | Quad probs      |\n");
    cout << ("-----------------------------------------------------------\n");
    cout << "| " << TABLE_SIZE << "   \t| " << TABLE_SIZE << "\t     | " << collisions_line << 
    "    \t        | " << collisions_quad << "\t\t  |\n";
    cout << ("-----------------------------------------------------------\n\n\n\n\n");

    delete[] table1;
    delete[] table2;
    delete[] table3;
    delete[] isOccupied;
getch();
    return 0;

}
