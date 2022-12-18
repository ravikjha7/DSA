#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll power(int a,int b)
{
    if(b==0)
    return 1;
    return a*power(a,b-1);
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<power(a,b)<<endl;

    return 0;
}