#include <stdio.h>
#include <string.h>
#define max 100

char stak[max];
int top=-1;

void push(char a);
void pop();
char peek();
int presidence(char a);

int main(){
    char str[max],postfix[max];
    int i,n,pos=0,p;
    printf("Give Infix expression: ");
    gets(str);
    n=strlen(str);
    for(i=0;i<n;i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='[') push(str[i]);
        else if(str[i]==')' || str[i]=='}' || str[i]==']'){
            while(top>=0 && (peek()!='(' && peek()!='{' && peek()!='[')){
                postfix[pos]=peek();
                pop();
                pos++;
            }
            pop();
        }
        else{
            if( (str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z') || (str[i]>='0' && str[i]<='9') ){
                postfix[pos]=str[i];
                pos++;
            }
            else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='^'){
                if(top<0) push(str[i]);
                else {
                    p=presidence(str[i]);
                    while(top>=0 && (peek()!='(' || peek()!='{' || peek()!='[') && p<=presidence(peek())){
                        postfix[pos]=peek();
                        pos++;
                        pop();
                    }
                    push(str[i]);
                }
            }
        }
    }
    while(top>=0) {
        postfix[pos]=peek();
        pop();
        pos++;
    }
    postfix[pos]='\0';
    printf("Postfix expression is : %s\n",postfix);
    return 0;
}

void push(char a){
    top++;
    stak[top]=a;
}
void pop(){
    top--;
}
char peek(){
    return stak[top];
}
int presidence(char a){
    if(a=='^') return 3;
    else if(a=='*' || a=='/') return 2;
    else if(a=='+' || a=='-') return 1;
    else return 0;
}
