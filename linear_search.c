#include <stdio.h>
int main(){
    int arr[100],i,n,item,flag=0;
    printf("Please input the number of element : ");
    scanf("%d",&n);
    printf("Input the element of array : ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Please input the number to be found : ");
    scanf("%d",&item);
    for(i=0;i<n;i++){
        if(arr[i]==item){
            flag++;
            break;
        }
    }
    if(flag==0) printf("Item not found.");
    else printf("Item found");
}
