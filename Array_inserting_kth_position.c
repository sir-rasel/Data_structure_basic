#include <stdio.h>
int main(){
    int i,j,k,n,m;
    int arr[100];
    printf("Please input the size of the array : ");
    scanf("%d",&n);
    printf("Please input the element of the array: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Please input the position of insert element of the array : ");
    scanf("%d",&k);
    for(i=n-1;i>=k;i--){
        arr[i+1]=arr[i];
    }
    printf("Please input the insert element : ");
    scanf("%d",&m);
    arr[k]=m;
    printf("Array after insertion : ");
    for(i=0;i<=n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
