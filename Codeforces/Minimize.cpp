#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        int a, b;
        cin >> a >> b;
        if(a>b) return -1;
        int c = a, min = 999;
        while(c<=b){
            if(min > (c-a)+(b-c)){
                min = (c-a)+(b-c);
            }
            c++;
        }
        cout << min << endl;
    }
}