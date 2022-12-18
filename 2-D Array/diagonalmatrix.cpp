#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class diagonal{

    int *arr;
    int n;
    public :
    diagonal(int n=3)
    {
        this->n = n;
        arr = new int[n]{0};
        
    }
    void set(int i,int j,int x)
    {
        if(i==j) arr[i-1] = x;
        else if(x!=0) cout<<"Diagonal Matrix Ka Matlab Nahi Pata Hai Kya??"<<endl;
    }
    int get(int i,int j)
    {
        if(i==j) return arr[i-1];
        return 0;
    }
    void display()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) cout<<arr[i-1]<<" ";
                else cout<<"0 ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int n;
    cin>>n;
    diagonal d(n);
    int i,j,x;
    cin>>i>>j>>x;
    d.set(i,j,x);
    cout<<d.get(i,j)<<endl;
    d.display();
    return 0;
}