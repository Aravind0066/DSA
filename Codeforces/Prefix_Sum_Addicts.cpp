#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    for(int i=0; i<t; i++){
        long long n, k;
        cin >> n >> k;

        vector<long long> arr(k);
        
        for(int j=0; j<k; j++){
            cin >> arr[j];
        }
        
        bool flag = false; 

        if(k==1){
            cout << "YES" << endl;
            continue;  
        }
        
        for(int j=0; j<k-2; j++){
            if(arr[j+1] - arr[j] > arr[j+2] - arr[j+1]){
                cout << "NO" << endl;
                flag = true;
                break;
            }
        }

        if(flag) continue;
        
        long long first = arr[1] - arr[0];
        long long sumbefore_k = arr[0];     // this is sum of n-k+1 st elements 
        long long known_first = n-k + 1;
        
        if (sumbefore_k > known_first * first) {   /// kinda like the employees before you cant get more than you so technically their salary sum should not be greater than the sum till your amount 
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
}
