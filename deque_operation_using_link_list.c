#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    struct node *next;
    struct node *prev;
}node;

void enqueue_left();
void enqueue_right();
void peek_left();
void peek_right();
void dequeue_left();
void dequeue_right();
void is_empty();
void clear();
void print();

node *front=NULL,*rear=NULL;
int counter;

int main(){
    int i,n,choice;
    while(1){
        printf("Give your choice:\n 1 for push left\n 2 for push right\n 3 for pop left\n 4 for pop right\n 5 for print: ");
        scanf("%d",&choice);
        if(choice==1){
            printf("How many element: ");
            scanf("%d",&n);
            for(i=0;i<n;i++) enqueue_left();
        }
        else if (choice==2){
            printf("How many element: ");
            scanf("%d",&n);
            for(i=0;i<n;i++) enqueue_right();
        }
        else if (choice==3){
            dequeue_left();
        }
        else if (choice==4){
            dequeue_right();
        }
        else if (choice==5){
            print();
        }
        else {
            printf("Invalid Choice\n");
            break;
        }
    }
    printf("Total element enter: %d\n",counter);
    print();
    peek_left();
    peek_right();
    is_empty();
    clear();
    print();
    return 0;
}

void enqueue_left(){
    int x;
    node *temp=(node*)malloc(sizeof(node));
    printf("Give value: ");
    scanf("%d",&x);
    temp->data=x;
    temp->next=NULL;
    temp->prev=NULL;
    if(front==NULL && rear==NULL){
        front=temp;
        rear=temp;
    }
    else{
        temp->next=front;
        front->prev=temp;
        front=temp;
    }
    counter++;
}
void enqueue_right(){
    int x;
    node *temp=(node*)malloc(sizeof(node));
    printf("Give value: ");
    scanf("%d",&x);
    temp->data=x;
    temp->next=NULL;
    temp->prev=NULL;
    if(front==NULL && rear==NULL){
        front=temp;
        rear=temp;
    }
    else{
        temp->prev=rear;
        rear->next=temp;
        rear=temp;
    }
    counter++;
}
void peek_left(){
    if(front==NULL && rear==NULL){
        printf("Empty\n");
    }
    else{
        printf("Left element is: %d\n",front->data);
    }
}
void peek_right(){
    if(front==NULL && rear==NULL){
        printf("Empty\n");
    }
    else{
        printf("Right element is: %d\n",rear->data);
    }
}
void dequeue_left(){
    if(front==NULL && rear==NULL){
        printf("Empty\n");
        return;
    }
    else if(front==rear){
        front=NULL;
        rear=NULL;
        counter--;
        return;
    }
    node *temp=front;
    front=front->next;
    free(temp);
    counter--;
}
void dequeue_right(){
    if(front==NULL && rear==NULL){
        printf("Empty\n");
        return;
    }
    else if(front==rear){
        front=NULL;
        rear=NULL;
        counter--;
        return;
    }
    node *temp=rear;
    rear=rear->prev;
    rear->next=NULL;
    free(temp);
    counter--;
}
void is_empty(){
    if(front==NULL && rear==NULL){
        printf("Empty\n");
    }
    else printf("Non-empty\n");
}
void clear(){
    printf("Cleared\n");
    front=NULL;
    rear=NULL;
}
void print(){
    if(front==NULL && rear==NULL){
        printf("Empty\n");
    }
    else{
        printf("Elements are: ");
        node *temp=front;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
