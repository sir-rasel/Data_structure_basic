#include <stdio.h>

void shellSort(int a[],int n);

int main(){
    int arr[100],n,i;
    printf("Input number of element : ");
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    shellSort(arr,n);
    printf("Array after sorting: ");
    for(i=0;i<n;i++) printf("%d ",arr[i]);
    return 0;
}

void shellSort(int a[],int n){
    int gap=n,i,position,temp;
    while(gap>0){
        gap/=2;
        for(i=gap;i<n;i++){
            temp=a[i];
            position=i;
            while(position>=gap && a[position-gap]>temp){
                a[position]=a[position-gap];
                position=position-gap;
            }
            a[position]=temp;
        }

    }
}
