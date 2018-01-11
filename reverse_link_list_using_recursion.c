#include <stdio.h>
#include <stdlib.h>

void insert(int x);
void print();

typedef struct{
    int data;
    struct node *next;
}node;

void reverse(node *p);
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
    reverse(head);
    printf("Link list after reverse: \n");
    print();
    return 0;
}

void print(){
    node *temp=head;
    printf("Data in the link list: ");
    while(temp!=NULL || head!=NULL){
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

void reverse(node *p){
    if(head==NULL) return;
    if(p->next==NULL){
        head=p;
        return;
    }
    reverse(p->next);
    node *q=p->next;
    q->next=p;
    p->next=NULL;
}
