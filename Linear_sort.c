#include <stdio.h>

void linear_sort(int a[],int n);

int main(){
    int i,n,arr[100];
    printf("Input the number of element of array : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    linear_sort(arr,n);
    printf("Array after sorting : ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

void linear_sort(int a[],int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(a[i]>a[j]){
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }
}
