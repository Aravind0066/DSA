#include <iostream>
using namespace std;

int search(int arr[], int n, int t){
    int low = 0, high = n-1 , mid;  
    while(low <= high){
        mid = low+(high-low)/2;
        if (t==arr[mid]) return mid;
        if(t > arr[mid]) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int target;
    cin >> target;
    int index = search(arr,n,target);
    if(index==-1) cout << "Element not found in the array.";
    else cout <<"output: " << index;
    return 0;
}
