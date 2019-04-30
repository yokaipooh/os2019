#include<stdio.h>
#define BUFFER_SIZE 10
typedef struct{
char type;
int amount;
char unit;
}item;
item buffer[BUFFER_SIZE];
int first=0; int last=0;
void printPos(){
printf("first = %d \nlast= %d\n",first,last);
return;
}
void produce(item *i){
while ((first +1) % BUFFER_SIZE == last){
printf("NO FREE BUFFER ITEM!!\n");
}
memcpy(&buffer[first],i , sizeof(item));
first = (first +1)% BUFFER_SIZE;
printPos();
}
item *consume(){
iteam* i = malloc(sizeof(item));
while (first == last){
printf("NOTHING TO CONSUME!!!!\n");
}
memcpy(i,&buffer[last],sizeof(item));
last = (last +1) %BUFFER_SIZE;
printPos();
return i;
}
item* inStore(char type, int amount,char unit){
item* i = malloc(sizeof(item));
i->type=type;
i->amount = amount;
i->unit = unit;
return i;
}
int main(){
item* order= inStore('3','1','4');
printf("Position:\nFirst: %d\nLast: %d",first,last);
produce(order);
consume();
return 0;
}
