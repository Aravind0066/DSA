// You are using GCC
#include <stdio.h>

void counting(int arr[], int n){
    int max = arr[0];
    for(int i=0; i<n; i++) if(arr[i]>max) max = arr[i];
    
    int hash[max+1];
    for(int i=0; i<max+1; i++) hash[i]=0;
    
    for(int i=0; i<n; i++){
        hash[arr[i]]++;
    }
    int found = 0;
    for(int i=0; i<=max; i++){
        if(hash[i]>1){
            printf("%d ", i);
            found = 1;
        }
    }
    if(!found) printf("-1");
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    
    counting(arr, n);
    
    return 0;
}
