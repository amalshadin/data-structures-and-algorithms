#include <stdio.h>

void insertionSort(int *arr, int n){
    int key,j;
    
    for(int i=1;i<n;i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

int main(){
    int n,A[10];

    printf("Enter the array size: ");
    scanf("%d",&n);
    printf("Enter array elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    insertionSort(A,n);
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }

    return 0;
}