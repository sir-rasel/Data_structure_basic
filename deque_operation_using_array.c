#include <stdio.h>
#define max 10

void enqueue_left();
void enqueue_right();
void dequeue_left();
void dequeue_right();
void peek_left();
void peek_right();
void isempty();
void isfull();
void clear();
void print();

int deque[max],front=-1,rear=-1,counter;

int main(){
    int i,n,choice,item;
    while(1){
        printf("Give Your Choice:\n 1 for insert left,\n 2 for insert right,\n 3 for delete left,\n 4 for delete right\n 5 for print element: ");
        scanf("%d",&choice);
        if(choice==1){
            printf("How many item: ");
            scanf("%d",&n);
            for(i=0;i<n;i++){
                enqueue_left(item);
            }
        }
        else if(choice==2){
            printf("How many item: ");
            scanf("%d",&n);
            for(i=0;i<n;i++){
                enqueue_right(item);
            }
        }
        else if(choice==3){
            dequeue_left();
        }
        else if(choice==4){
            dequeue_right();
        }
        else if(choice==5){
            print();
        }
        else{
            printf("Invalid Choice\n");
            break;
        }
    }
    printf("%d Elements inserted\n",counter);
    print();
    peek_left();
    peek_right();
    isempty();
    isfull();
    clear();
    print();
    return 0;
}

void enqueue_left(){
    if(front==-1 && rear==-1){
        front=rear=0;
    }
    else if(counter==max || ((front+max-1)%max==rear)){
        printf("Queue is full\n");
        return;
    }
    else{
        front=(front+max-1)%max;
    }
    int x;
    printf("Give value: ");
    scanf("%d",&x);
    deque[front]=x;
    counter++;
}
void enqueue_right(int x){
    if(front==-1 && rear==-1){
        front=rear=0;
    }
    else if(counter==max || ((rear+1)%max==front)){
        printf("Queue is full\n");
        return;
    }
    else{
        rear=(rear+1)%max;
    }
    printf("Give value: ");
    scanf("%d",&x);
    deque[rear]=x;
    counter++;
}
void dequeue_left(){
    if(front==-1 && rear==-1){
        printf("Empty\n");
        return;
    }
    if((front+1)%max==rear) {
        front=rear=-1;
    }
    else front++;
    counter--;
}
void dequeue_right(){
    if(front==-1 && rear==-1){
        printf("Empty\n");
        return;
    }
    if((rear+max-1)%max==front) {
        front=rear=-1;
    }
    else rear--;
    counter--;
}
void peek_left(){
    if(front==-1 && rear==-1) printf("Empty\n");
    else printf("Peek left is : %d\n",deque[front]);
}
void peek_right(){
    if(front==-1 && rear==-1) printf("Empty\n");
    else printf("Peek right is : %d\n",deque[rear]);
}
void isempty(){
    if(counter<=0 || (front==-1 && rear==-1)){
        printf("Empty queue\n");
    }
    else printf("Non-empty\n");
}
void isfull(){
    if(counter==max || ((front+max-1)%max==rear || (rear+1)%max==front)) printf("Full\n");
    else printf("Not-full\n");
}
void clear(){
    printf("Cleared queue\n");
    rear=front=-1;
}
void print(){
    int i;
    if(front==-1 && rear==-1){
        printf("Empty\n");
        return;
    }
    printf("Elements are: ");
    for(i=front;i!=1;i=(i+1)%max){
        printf("%d ",deque[i]);
    }
    for(i=rear;i!=0;i=(i+max-1)%max){
        printf("%d ",deque[i]);
    }
    printf("\n");
}
