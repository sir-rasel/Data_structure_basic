#include <stdio.h>
#include <string.h>
#define max 100

char sta[max];
int top=-1;

int isclose(char a,char b);
int isbalanced(char str[],int n);
void push(char a);
void pop();
char peek();

int main(){
    int n,i;
    char str[100];
    printf("Give the equation: ");
    gets(str);
    n=strlen(str);
    i=isbalanced(str,n);
    if(i==0) printf("Imbalanced\n");
    else printf("Balanced\n");
    return 0;
}

int isclose(char a,char b){
    if(a=='(' && b==')') return 1;
    else if(a=='{' && b=='}') return 1;
    else if(a=='[' && b==']') return 1;
    else return 0;
}
int isbalanced(char str[],int n){
    int i;
    for(i=0;i<n;i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='[') push(str[i]);
        else if(str[i]==')' || str[i]=='}' || str[i]==']'){
            if(top<0 || isclose(peek(),str[i])==0) return 0;
            else pop();
        }
    }
    if(top<0) return 1;
    else return 0;
}
void push(char a){
    top++;
    sta[top]=a;
}
void pop(){
    top--;
}
char peek(){
    return sta[top];
}
