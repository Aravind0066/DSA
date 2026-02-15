#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    cin.ignore();

    for(int i=0; i<t; i++){
        string s;
        getline(cin, s);

        cout << s[0];

        for(int j=0; s[j] != '\0'; j++){
            if(s[j] == ' ' && isalpha(s[j+1])){
                cout << s[j+1];
            }
        }
        cout << endl;
    }
}