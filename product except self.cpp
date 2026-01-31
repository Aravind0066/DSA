#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int output[n];
    output[0] = 1;
    for(int i=1; i<n; i++){
        output[i] = output[i-1]*arr[i-1];
    }

    int right = 1;
    for(int i=n-1; i>=0; i--){
        output[i] *= right;
        right *= arr[i];
    }

    for(int i=0; i<n; i++){
        cout << output[i];
    }

    return 0;
}