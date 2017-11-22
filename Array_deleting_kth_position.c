#include <stdio.h>
int main(){
    int i,j,k,n;
    int arr[100];
    printf("Please input the size of the array : ");
    scanf("%d",&n);
    printf("Please input the element of the array: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Please input the position of insert element of the array : ");
    scanf("%d",&k);
    for(i=k;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    printf("Array after insertion : ");
    for(i=0;i<n-1;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
