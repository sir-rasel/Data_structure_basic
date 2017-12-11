#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    struct node *next;
}node;

node *head=NULL;

void insert(int x);
void print();
int sum();

int main(){
    int item,i,x;
    printf("How many node: ");
    scanf("%d",&item);
    for(i=0;i<item;i++){
        printf("Enter value : ");
        scanf("%d",&x);
        insert(x);
        print();
    }
    printf("Summation of all value : %d",sum());
    return 0;
}

void insert(int x){
    node *temp=(node*)malloc(sizeof(node));
    temp->value=x;
    temp->next=head;
    head=temp;
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
