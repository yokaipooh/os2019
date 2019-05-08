#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>


#define BUFFER_SIZE 10

int pid =0;

typedef struct product
{
	char type;
	int amount;
	char unit;
} item;
item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;
void initBeef(item *smt) 
{
	smt->type = 1;
	smt->amount = 1;
	smt->unit = 1;
}
void initBurger(item *smt)
{
	smt->type =0;
	smt->amount=0;
	smt->amount=0;
}
void produce(item *i)
{
	while ((first + 1) % BUFFER_SIZE == last)
	{
		printf("No buffer item!!!!!\n");
		return;
	}
	memcpy(&buffer[first], i, sizeof(item));
	first = (first + 1) % BUFFER_SIZE;
	printf("First = %d\n", first);
}
item *consume()
{
	item *i = malloc(sizeof(item));
	while (first == last)
	{
		printf("Nothing to consume!\n");
	}
	memcpy(i, &buffer[last], sizeof(item));
	last = (last + 1) % BUFFER_SIZE;
	printf("Last = %d\n", last);
	return;
}
void *produThread(void* param)
{
	item *Beef, gram;
	Beef = &gram;
	printf("3 Grams of beef please !!!\n");
	initBeef(Beef);
	produce(Beef);
	produce(Beef);
	produce(Beef);
	pthread_exit(NULL);
}
void *consuThread(void* param)
{
	printf("Selling 2 grams of beef\n");
	consume();
	consume();
	pthread_exit(NULL);
}
int main()
{
	pthread_t tid;
	printf("WELCOME TO THE BEEF-HOUSE !!\n");
	printf("HOPE YOU ENJOY IT\n");
	pthread_create(&tid,NULL,produThread,NULL);
	pthread_join(tid,NULL);
	printf("2 customers are coming to buy beef");
	pthread_create(&tid,NULL,consuThread,NULL);
	pthread_exit(NULL);
}

























