#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    struct node *link;
}node;

node *top=NULL;
int length;

void push();
void pop();
void peek();
void print();
void isempty();

int main(){
    int choice,n,i;
    while(1){
        printf("Give your choice\n 1 for push\n 2 for pop\n 3 for peek\n 4 for check empty\n 5 for exit: ");
        scanf("%d",&choice);
        if(choice==5) break;
        else if(choice==1){
            printf("How many node: ");
            scanf("%d",&n);
            for(i=0;i<n;i++) push();
            printf("stack elements are: ");
            print(top);
            printf("\n");
        }
        else if(choice==2){
            printf("How many node: ");
            scanf("%d",&n);
            for(i=0;i<n;i++) pop();
            printf("stack elements are: ");
            print(top);
            printf("\n");
        }
        else if(choice==3){
            peek();
        }
        else if(choice==4){
            isempty();
        }
        else{
            printf("Invalid choice, try again\n");
        }
    }
    printf("stack elements are: ");
    print(top);
    return 0;
}

void push(){
    node *temp=(node*) malloc(sizeof(node));
    int data;
    printf("Give value: ");
    scanf("%d",&data);
    temp->data=data;
    temp->link=top;
    top=temp;
    length++;
}
void pop(){
    node *temp=top;
    top=temp->link;
    free(temp);
    length--;
}
void peek(){
    if(top==NULL) printf("Empty stack\n");
    else printf("Elements in top: %d\n",top->data);
}
void print(node *temp){
    if(top==NULL){
        printf("Empty stack");
        return;
    }
    else{
        if(temp==NULL) return;
        print(temp->link);
        printf("%d ",temp->data);
    }
}
void isempty(){
    if(top==NULL) printf("Empty\n");
    else printf("Non-empty\n");
}
