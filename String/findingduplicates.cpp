#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void checkduplicates(string s)
{
    int x = 1 , h = 0;
    for(int i=0;i<s.size();i++)
    {
        x = 1;
        x = x<<s[i]-97;
        if((h&x)) cout<<s[i]<<" ";
        else h = (h | x);
    }
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    checkduplicates(s);
    return 0;
}