#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <locale.h>

struct stack {
	struct stack *next;
	union {
		int data;
		unsigned char digit [sizeof(int)];
	};
};

struct Queue {
	stack *head;
	stack *tail;
};

void FillIncStack(struct stack **head, int n) {
	struct stack *f;
	for (int i = 0; i < n; i++) {
		f = (stack*)malloc(sizeof(struct stack));
		f -> data = i;
		f -> next = *head;
		*head = f;
	}
}

void FillDecStack(struct stack **head, int n) {
	struct stack *f;
	for (int i = 0; i < n; i++) {
		f = (stack*)malloc(sizeof(struct stack));
		f -> data = i;
		f -> next = *head;
		*head = f;
	}
}

void FillRandStack(struct stack **head, int n) {
	srand(time(0));
	struct stack *f;
	for (int i = 0; i < n; i++) {
		f = (stack*)malloc(sizeof(struct stack));
		f -> data = rand() % n;
		f -> next = *head;
		*head = f;
	}
}

void PrintStack(struct stack *head) {
	struct stack *f = head;
	while (f != NULL) {
		printf("%d ",f->data); 
		f = f -> next;
	}
	printf("\n");
}


void DeleteStack(struct stack **head) {
	struct stack *f = *head;
	while(f != NULL) {
		*head = f -> next;
		free(f);
		f = *head;
	}
}

void StackToQueue (struct stack **head, struct stack **tail) {
	(*tail)->next=*head;
	*tail=*head;
	*head=(*head)->next;
	(*tail)->next=NULL;
}

void Hash (int m, stack **head, stack **tail, Queue q[]) {
	int i, j, colis = 0;
	stack *p=*head, *z;
	while (p!=NULL) {
		j=p->data%m;
		z=q[j].head;
		i=0;
		while (z!=NULL) {
			if (z->data==p->data)  i++; 
			z=z->next;
		}
		if (i==0) {
			StackToQueue (&p, &(q[j].tail));
			(q[j].tail)->next=NULL;
		}
		else p=p->next;
	}
	for (i=0; i<m; i++) {
		printf ("%d ", i);
		p=q[i].head;
		int s = 0;
		while (p!=NULL) {
			if(s != 0) colis++;
			printf ("-> %d ", p->data);
			p=p->next;
			s = 1;
		}
		printf ("\n");
	}
	printf("\n „исло коллизий: %d\n",colis);
}

void HashSearch(int m, Queue q[]) {
	int i=0, j, n;
	stack *p;
	printf ("¬ведите ключ поиска: ");
	scanf("%d", &n);
	j=n % m;
	p=q[j].head;
	while (p!=NULL) {
		if (n==p->data) {
			i++;
			break;
		}
		p=p->next;
	}
	if (i) printf ("Chislo %d naydeno v %d ocheredi!", n, j);
	else printf ("Chisla %d net v ocheredyah!", n, j);
}

int main() {
	stack *head, *tail;
	head = NULL;
	tail = (stack*)&head;
	int i, n, m;
	setlocale(LC_ALL, "RUS");
	printf("¬ведите размер очереди: ");
	scanf("%d",&n);
	printf("¬ведите размер таблицы: ");
	scanf("%d",&m);
	FillRandStack(&head, n);
	PrintStack (head);
	Queue q[m];
	for(i = 0; i < m; i++) {
		q[i].head = NULL;
		q[i].tail = (stack*)&q[i].head;
	}
	printf("\n");
	Hash(m, &head, &tail, q);
	HashSearch (m, q);
	return 0;
}
