#include <iostream>

using namespace std;

void print1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2*n - 1; j++)
        {
            if (j < n-1-i)
            {
                cout << " ";
            }
            else if (j > n+i-1)
            {
                cout << " ";
            }
            else cout<<"*";
        }
        cout << endl;
    }
}
void print2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++) cout<<" ";
        for (int j = 0; j < 2*n - 1 - 2* i; j ++) cout<<"*";
        for (int j = 0; j < i; j++) cout<<" ";
        cout<<endl;
    }
}
void print3(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2*n - 1; j++)
        {
            if (j < n-1-i)
            {
                cout << " ";
            }
            else if (j > n+i-1)
            {
                cout << " ";
            }
            else cout<<"*";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++) cout<<" ";
        for (int j = 0; j < 2*n - 1 - 2* i; j ++) cout<<"*";
        for (int j = 0; j < i; j++) cout<<" ";
        cout<<endl;
    }
}
void print4(int n)
{
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j % 2 == 0) 
            {
                cout << "1 ";
            }
            else cout<<"0 ";
        }
        cout<<endl;
    }
}
void print5(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout<<j+1;
        }
        for (int j = 0; j < 2*n - 2*(i+1); j++)
        {
            cout<<" ";
        }
        for (int j = 0; j <= i; j++)
        {
            cout<<j+1;
        }
        cout<<endl;
    }
}
void print6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i+j <<" ";
        }
        cout<<endl;
    }
}
void print7(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char c = 'A'; c <= 'A' + i; c++)
        {
            cout<<c;
        }
        cout<<endl;
    }
}
void print8(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            cout << " ";
        }
        char ch = 'A';
        for (int j = 0; j < 2*i + 1; j++)
        {
            cout<<ch;
            if (j < (2 * i + 1)/2)
            {
                ch++;
            }
            else ch--;
        }
        for (int j = 0; j < n-1-i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
    
}
void print9(int n)
{
    for (int i = 0; i < n; i++)
    {
        
        for (int j = 0; j < n-i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < 2*(i); j++)
        {
            cout<<" ";
        }
        for (int j = 0; j < n-i; j++)
        {
            cout << "*";
        }
        cout<<endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <=i; j++)
        {
            cout<<"*";
        }
        for (int j = 0; j < 2*(n - i - 1); j++)
        {
            cout << " ";
        }
        for (int j = 0; j <=i; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
void print10(int n)
{
    int spaces = 2*n - 2;
    for (int i  = 0; i < 2*n - 1; i++)
    {
        int stars;
        if (i < n) stars = i+1;
        else stars = 2*n - i - 1;


        for (int j = 0; j < stars; j++) cout<< "*";
        for (int j = 0; j < spaces; j++) cout << " ";
        for (int j = 0; j < stars; j++) cout<< "*";

        if (i < n-1) spaces -=2;
        else spaces +=2;
        cout <<endl;

    }
}
void print11(int n)
{
    int spaces = n-2;
    for (int i = 0; i < n; i++)
    {
        int stars = 1;
        if (i == 0 || i  == n-1)
        {
            stars = n;
            for (int j = 0; j < stars; j++) cout<< "*";
        }
        else 
        {
            for (int j = 0; j < stars; j++) cout<< "*";
            for (int j = 0; j < spaces; j++) cout<< " ";
            for (int j = 0; j < stars; j++) cout<< "*";

        }
        
        cout<<endl;
    }
}
void print12(int n)
{
    for (int i = 0; i < 2*n-1; i++)
    {
        for (int j = 0; j < 2*n - 1; j++)
        {
            if (i == j)
            {
                for (int k = 0; k < 2*n -1; k++)
                {
                    
                }
            }
        }
    }


}


int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        print11(n);
    }
    return 0;
}