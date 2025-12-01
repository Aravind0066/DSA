#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        
        /* 
        int sum = 0; 
        int a = 1, b = n-1;
        for(int i=1; i<n; i++){
            if(a+b == n) sum++;
            a++; b--;
        } 
        cout << sum << endl;
        */  
       // observing the pattern it exacty runs for n-1 times so the sum would be n-1;
       cout << n-1 << endl;
    }
}