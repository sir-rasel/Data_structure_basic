#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    struct node *next;
} node;

node *head=NULL;

void print();
void insert(int x);
int sum();

int main(){
    int item,i,x;
    printf("How many node : ");
    scanf("%d",&item);
    for(i=0;i<item;i++){
        printf("Insert value: ");
        scanf("%d",&x);
        insert(x);
        print();
    }
    printf("Summation of all value : %d",sum());
    return 0;
}

void insert(int x){
    node *temp=(node*)malloc(sizeof(node)),*temp1=head;
    temp->value=x;
    temp->next=NULL;
    if(head==NULL) head=temp;
    else{
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=temp;
    }
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
