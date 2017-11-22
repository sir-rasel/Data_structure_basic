#include <stdio.h>
void insertion_sort(int a[],int n);
int main(){
    int i,n,arr[100];
    printf("Please input the size of array : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    insertion_sort(arr,n);
    printf("Arrau after sorting : ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
void insertion_sort(int a[],int n){
    int i,temp,position;
    for(i=1;i<n;i++){
        temp=a[i];
        position=i;
        while(position>0 && a[position-1]>temp){
            a[position]=a[position-1];
            position--;
        }
        a[position]=temp;
    }
}
