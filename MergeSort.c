#include <stdio.h>

void merge(int arr[], int low, int mid, int high){
    int left = mid - low + 1;
    int right = high - mid;

    int leftarr[left], rightarr[right];

    for(int i=0; i<left; i++) leftarr[i] = arr[low + i];
    for(int i=0; i<right; i++) rightarr[i] = arr[mid + 1 + i];

    int l=0, r=0, index = low;
    while(l<left && r<right){
        if(leftarr[l]<=rightarr[r]) arr[index++] = leftarr[l++];
        else arr[index++] = rightarr[r++];
    }

    while(l<left) arr[index++] = leftarr[l++];
    while(r<right) arr[index++] = rightarr[r++];
}

void mergeSort(int arr[], int low, int high){
    if(low>=high) return;
    int mid = low + (high-low)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    mergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }

    return 0;
}