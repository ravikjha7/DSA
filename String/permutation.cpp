#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void permutation(char s[],int k)
{
    static int arr[10];
    static char ans[10];
    if(s[k]=='\0')
    {
        ans[k] = '\0';
        cout<<ans<<endl;
        return;
    }
    for(int i = 0;s[i]!='\0';i++)
    {
        if(arr[i]==0)
        {
            ans[k] = s[i];
            arr[i]=1;
            permutation(s,k+1);
            arr[i]=0;
        }
    }
}

int main()
{
    char s[] = {'A','B','C','\0'};
    permutation(s,0);
    return 0;
}