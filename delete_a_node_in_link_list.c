#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    struct node *next;
}node;

void print();
void insert(int x,int n);
void Delete(int n);

node *head=NULL;

int main(){
    int x,n,i,num;
    printf("How many item: ");
    scanf("%d",&num);
    for(i=0;i<num;i++){
        printf("Give value and position: ");
        scanf("%d %d",&x,&n);
        insert(x,n);
        print();
    }
    printf("Input position what be deleted: ");
    scanf("%d",&n);
    Delete(n);
    print();
    return 0;
}

void insert(int x,int n){
    int i;
    node *temp=(node*) malloc(sizeof(node)),*temp1=head;
    temp->data=x;
    temp->next=NULL;
    if(n==1){
        temp->next=head;
        head=temp;
        return;
    }
    for(i=0;i<n-2;i++){
        temp1=temp1->next;
    }
    temp->next=temp1->next;
    temp1->next=temp;
}

void print(){
    node *temp=head;
    printf("Node data are: ");
    while(temp!=NULL){
        printf(" %d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void Delete(int n){
    int i;
    node *temp=head,*temp1;
    if(n==1){
        head=temp->next;
        free(temp);
        return;
    }
    for(i=0;i<n-2;i++){
        temp=temp->next;
    }
    temp1=temp->next;
    temp->next=temp1->next;
    free(temp1);
}
