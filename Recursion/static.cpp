#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void func1(int n)
{
    static int x = 0;
    if(n>0)
    {
        x++;
        func1(n-1);
        cout<<x<<endl;
    }
}

int main()
{
    int n = 5;
    func1(n);
    return 0;
}