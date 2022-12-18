#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void fun1(int n)
{
    if(n>0){
        cout<<n<<endl;
        fun1(n-1);
        fun1(n-1);
    }
}
int main()
{
    int n = 3;
    fun1(n);

    return 0;
}