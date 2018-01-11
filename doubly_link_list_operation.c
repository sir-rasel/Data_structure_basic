#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    struct node *next;
    struct node *prev;
}node;

node *head=NULL;
int length;

void insert(int x);
void del(int n);
void update(int x,int data);
void printfront();
void printback();

int main(){
    int n,i,pos,choice,value;
    while(1){
        printf("Give your choice:\n 1 for insert\n 2 for delete\n 3 for update\n 4 for length\n 5 for exit: ");
        scanf("%d",&choice);
        if (choice==5) break;
        else if(choice==1){
            printf("How many node: ");
            scanf("%d",&n);
            for(i=0;i<n;i++){
                printf("Give position: ");
                scanf("%d",&pos);
                insert(pos);
                printfront();
                printback();
            }
        }
        else if(choice==2){
            printf("Give delete position: ");
            scanf("%d",&n);
            del(n);
            printfront();
            printback();
        }
        else if(choice==3){
            printf("Give update position and data: ");
            scanf("%d %d",&n,&value);
            update(n,value);
            printfront();
            printback();
        }
        else if(choice==4){
            printf("Length of current link list : %d\n",length);
        }
        else{
            printf("Invalid choice, try again\n");
        }
    }
    printf("Front print after operation: ");
    printfront();
    printf("Reverse print after operation: ");
    printback();
    return 0;
}

void insert(int x){
    node *temp=(node*) malloc(sizeof(node));
    int value;
    if((x!=1 && length==0) || x>length+1 ){
        printf("Invalid\n");
        return;
    }
    printf("Input value: ");
    scanf("%d",&value);
    temp->data=value;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL) head=temp;
    else if(x==1){
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    else if (x==length+1) {
        node *temp1=head;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=temp;
        temp->prev=temp1;
    }
    else{
        node *temp1=head;
        int i;
        for(i=0;i<x-2;i++){
            temp1=temp1->next;
        }
        temp->next=temp1->next;
        temp1->next=temp;
        temp->prev=temp1;
        node *temp2=temp->next;
        temp2->prev=temp;
    }
    length++;
}

void del(int n){
    node *temp=head;
    int i;
    if(n>length+1 || n<=0 || length==0){
        printf("Invalid position:\n");
        return;
    }
    if(n==1){
        head=temp->next;
        head->prev=NULL;
        free(temp);
        length--;
    }
    else{
        for(i=0;i<n-2;i++){
            temp=temp->next;
        }
        node *temp2=temp->next;
        temp->next=temp2->next;
        node *temp3=temp2->next;
        temp3->prev=temp;
        free(temp2);
        length--;
    }
}

void update(int x,int data){
    if(x<1 || x>length) {
        printf("Invalid position\n");
        return;
    }
    node *temp=head;
    int i;
    for(i=0;i<x-1;i++){
        temp=temp->next;
    }
    temp->data=data;
}

void printfront(){
    int count=0;
    if(head==NULL){
        printf("Empty\n");
        return;
    }
    node *temp=head;
    while(temp!=NULL){
        printf("%d",temp->data);
        count++;
        if(count!=length) printf(" -> ");
        temp=temp->next;
    }
    printf("\n");
}

void printback(){
    int count=0;
    if(head==NULL){
        printf("Empty\n");
        return;
    }
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    node *temp1=temp;
    while(temp1!=NULL){
        printf("%d",temp1->data);
        count++;
        if(count!=length) printf(" -> ");
        temp1=temp1->prev;
    }
    printf("\n");
}
