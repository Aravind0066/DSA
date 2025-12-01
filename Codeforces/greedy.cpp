#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    for(int i=0; i<t; i++){
        int n,m;
        cin >> n >> m;
        if(n == 1 || m == 1) cout << "NO" << endl;   // only one route...
        else if(n == 2 && m == 2) cout << "NO" << endl;   // similarly only one route which i missed...
        else cout << "YES" << endl;   //// there are multiple routes, so yeah can trick it by puting larger in the later parts.
    }
}