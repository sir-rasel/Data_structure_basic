#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    struct node *next;
}node;

node *head=NULL;

void insert(int x,int n);
void print();
int sum();

int main(){
    int item,i,x,n;
    printf("How many node: ");
    scanf("%d",&item);
    for(i=0;i<item;i++){
        printf("Enter value and position: ");
        scanf("%d %d",&x,&n);
        insert(x,n);
        print();
    }
    printf("Summation of all value : %d",sum());
    return 0;
}

void insert(int x,int n){
    int i;
    node *temp=(node*)malloc(sizeof(node));
    temp->value=x;
    temp->next=NULL;
    if(n==1){
        temp->next=head;
        head=temp;
        return;
    }
    node *temp1=head;
    for(i=0;i<n-2;i++){
        temp1=temp1->next;
    }
    temp->next=temp1->next;
    temp1->next=temp;
}

void print(){
    node *temp=head;
    printf("Item in link list is: ");
    while(temp!=NULL){
        printf(" %d",temp->value);
        temp=temp->next;
    }
    printf("\n");
}

int sum(){
    node *temp=head;
    int total=0;
    while(temp!=NULL){
        total+=temp->value;
        temp=temp->next;
    }
    return total;
}
