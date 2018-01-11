#include <stdio.h>
#define max 100

int sta[max],top=-1;

void push(int x);
void pop();
void peek();
void isempty();
void print();

int main(){
    int choice,i,n,item;
    while(1){
        printf("Give your choice\n 1 for push\n 2 for pop\n 3 for peek\n 4 for check empty\n 5 for exit: ");
        scanf("%d",&choice);
        if(choice==5) break;
        else if(choice==1){
            printf("How many item: ");
            scanf("%d",&n);
            for(i=0;i<n;i++){
                printf("Give value: ");
                scanf("%d",&item);
                push(item);
            }
            print();
        }
        else if(choice==2){
            printf("How many item: ");
            scanf("%d",&n);
            for(i=0;i<n;i++){
                pop();
            }
            print();
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
    print();
    return 0;
}
void push(int x){
    if(top>=max) {
        printf("Overflow\n");
        return;
    }
    top++;
    sta[top]=x;
}
void pop(){
    if(top<0){
        printf("Underflow\n");
        return;
    }
    top--;
}
void peek(){
    if(top<0){
        printf("No element\n");
        return;
    }
    printf("Element is: %d\n",sta[top]);
}
void isempty(){
    if(top<0) printf("Stack is empty\n");
    else printf("Stack is not empty\n");
}
void print(){
    int i;
    if(top<0){
        printf("Empty stack\n");
        return;
    }
    printf("Stack elements are: ");
    for(i=0;i<=top;i++){
        printf("%d ",sta[i]);
    }
    printf("\n");
}
