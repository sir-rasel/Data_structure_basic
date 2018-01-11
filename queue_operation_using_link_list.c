#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    struct node *next;
}node;

node *front=NULL,*rear=NULL;

void enqueue(int x);
void peek();
void dequeue();
void isempty();
void print();

int main(){
    int n,i,item;
    printf("How many item be inserted: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Give value: ");
        scanf("%d",&item);
        enqueue(item);
    }
    print();
    printf("How many item be deleted: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        dequeue();
    }
    print();
    isempty();
    peek();
    return 0;
}

void enqueue(int x){
    node *temp=(node*)malloc(sizeof(node));
    temp->data=x;
    temp->next=NULL;
    if(front==NULL & rear==NULL) {
        front=temp;
        rear=temp;
        return;
    }
    rear->next=temp;
    rear=temp;
}
void peek(){
    if(front==NULL) printf("Empty\n");
    else printf("Front value is: %d\n",front->data);
}
void dequeue(){
    node *temp=front;
    if(front==NULL) {
        printf("Empty\n");
        return;
    }
    if(front==rear) rear=front=NULL;
    else front=front->next;
    free(temp);
}
void isempty(){
    if(front==NULL) printf("Empty\n");
    else printf("Non-empty\n");
}
void print(){
    node *temp=front;
    printf("Data are: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
