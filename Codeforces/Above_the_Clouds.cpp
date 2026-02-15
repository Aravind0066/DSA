#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    for(int i=0; i<t; i++){
        map <char,int> mpp;
        int n;
        string s;
        cin >> n;
        cin >> s;
        
        for(int i=0; i<s.size(); i++){
            mpp[s[i]]++;
        }
        
        bool flag = false;
        
        for(int i=1; i<s.size()-1; i++){
            if(mpp[s[i]]>1){
                flag = true;
                break;
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}