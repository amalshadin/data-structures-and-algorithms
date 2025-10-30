#include <stdio.h>

void selectionSort(int *A, int n){
    int minIndex;
    for(int i=0;i<n-1;i++){
        minIndex=i;
        for(int j=i+1;j<n;j++){
            if(A[j]<A[minIndex]){
                minIndex=j;
            }
        }
        if (i!=minIndex){
            int temp=A[i];
            A[i]=A[minIndex];
            A[minIndex]=temp;
        }
    }
}

int main(){
    int n,arr[10];

    printf("Array Size = ");
    scanf("%d",&n);

    printf("Enter array elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    selectionSort(arr,n);

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}