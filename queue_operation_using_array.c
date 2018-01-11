#include <stdio.h>
#define max 10

int que[max],front=0,rear=-1,counter;

void enqueue(int x);
void dequeue();
int isempty();
int peek();
int isfull();

int main(){
    int n,i,item;
    printf("How many item of queue be inserted: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Give value: ");
        scanf("%d",&item);
        enqueue(item);
    }
    printf("Queue elements are: ");
    for(i=front;i<=rear;i++){
        printf("%d ",que[i]);
    }
    printf("\n");
    printf("How many item of queue be deleted: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        dequeue(item);
    }
    printf("Queue elements are: ");
    for(i=front;i<=rear;i++){
        printf("%d ",que[i]);
    }
    printf("\n");
    printf("Number of elements in queue: %d\n",counter);
    return 0;
}

void enqueue(int x){
    if(rear==max){
        printf("Overflow\n");
        return;
    }
    que[++rear]=x;
    counter++;
}
void dequeue(){
    if(front==rear) {
        printf("Underflow\n");
        return;
    }
    front++;
    counter--;
}
int isempty(){
    if(counter<=0) return 1;
    else return 0;
}
int peek(){
    return que[front];
}
int isfull(){
    if(counter==max) return 1;
    else return 0;
}
