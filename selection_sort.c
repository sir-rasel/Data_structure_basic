#include <stdio.h>
void selection_sort(int a[],int n);

int main(){
    int arr[100],n,i;
    printf("Input the number of element : ");
    scanf("%d",&n);
    printf("Input the element : ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    selection_sort(arr,n);
    printf("Array after sorting : ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

void selection_sort(int arr[],int n){
    int i,j,position,temp;
    for(i=0;i<n-2;i++){
        position=i;
        for(j=i+1;j<n-1;j++){
            if(arr[j]<arr[position]){
                position=j;
            }
        }
        if(position!=i){
            temp=arr[i];
            arr[i]=arr[position];
            arr[position]=temp;
        }
    }
}
