#include <stdio.h>
#include <stdlib.h>

void insert(int x);
void print();
void reverse();

typedef struct{
    int data;
    struct node *next;
}node;

node *head=NULL;

int main(){
    int x,i,n;
    printf("How many item ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
       printf("Input link list data: ");
        scanf("%d",&x);
        insert(x);
    }
    print();
    reverse();
    printf("Link list after reverse: \n");
    print();
    return 0;
}

void print(){
    node *temp=head;
    printf("Data in the link list: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void insert(int x){
    node *temp=(node*) malloc(sizeof(node));
    temp->data=x;
    temp->next=head;
    head=temp;
}

void reverse(){
    node *prev=NULL,*cur=head,*next;
    while(cur!=NULL){
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;

    }
    head=prev;
}
