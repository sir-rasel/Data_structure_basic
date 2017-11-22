#include <stdio.h>
void bubble_sort(int a[],int n);
int main(){
    int arr[100],i,n;
    printf("Input the size of array : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    bubble_sort(arr,n);
    printf("Array after sorting : ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
void bubble_sort(int a[],int n){
    int i,j,temp,flag=0;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag++;
            }
        }
        if(flag==0) break;
    }
}
