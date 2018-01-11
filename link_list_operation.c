#include <stdio.h>
#include <stdlib.h>

void insert(int x);
void print();
void del(int n);
void update(int pos,int x);

typedef struct {
    int data;
    struct node *next;
}node;

int length;
node *head=NULL;

int main(){
    int i,n,pos,choice,item;
    while(1){
        printf("Press your choice \n 1 for insert\n 2 for delete\n 3 for update\n 4 for length\n 5 for exit: ");
        scanf("%d",&choice);
        if(choice==5) break;
        else if(choice==1){
            printf("How many node: ");
            scanf("%d",&item);
            for(i=0;i<item;i++){
                printf("Input the position you want to insert: ");
                scanf("%d",&pos);
                insert(pos);
            }
        }
        else if(choice==2){
            printf("Input the position you want to delete: ");
            scanf("%d",&pos);
            del(pos);
        }
        else if(choice==3){
            printf("Input the position you want to update: ");
            scanf("%d",&pos);
            printf("Input the updated value: ");
            scanf("%d",&item);
            update(pos,item);
        }
        else if(choice==4){
            printf("Length of the link list is: %d\n",length);
        }
        else {
            printf("Invalid choice try again\n");
        }
        printf("Link list after work : ");
        print();
    }
    printf("Link list after all work : ");
    print();
    return 0;
}

void insert(int x){
    if(x>length+1 || x<=0){
        printf("Invalid position:\n");
    }
    else{
        int item,i;
        node *temp = (node*)malloc(sizeof(node));
        node *temp1=head;
        printf("Input the value: ");
        scanf("%d",&item);
        temp->data=item;
        temp->next=NULL;
        if(temp1==NULL) head=temp;
        else{
            if(x==1){
                temp->next=head;
                head=temp;
            }
            else {
                for(i=0;i<x-2;i++){
                    temp1=temp1->next;
                }
                temp->next=temp1->next;
                temp1->next=temp;
            }
        }
    }
    length++;
}
void print(){
    int count=0;
    node *temp=head;
    while(temp!=NULL){
        printf("%d",temp->data);
        count++;
        if(count!=length) printf(" -> ");
        temp=temp->next;
    }
    printf("\n");
}
void del(int n){
    node *temp=head;
    int i;
    if(n>length+1 || n<=0 || length==0){
        printf("Invalid position:\n");
    }
    else if(n==1){
        head=temp->next;
        free(temp);
        length--;
    }
    else{
        for(i=0;i<n-2;i++){
            temp=temp->next;
        }
        node *temp2=temp->next;
        temp->next=temp2->next;
        free(temp2);
        length--;
    }
}
void update(int pos,int x){
    node *temp=head;
    int i;
    if(pos>length+1 || pos<=0){
        printf("Invalid position:\n");
    }
    else{
       for(i=0;i<pos-1;i++){
            temp=temp->next;
       }
       temp->data=x;
    }
}
