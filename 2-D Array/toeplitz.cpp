#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class toeplitz{
    int n;
    int *arr;
    public:
    toeplitz(int n=5)
    {
        this->n = n;
        arr = new int[n]{0};
    }
    void set(int i,int j,int x)
    {
        int index;
        if(j>=i) index = j-i;
        else index = n+i-j-1;
        arr[index] = x;
    }
    int get(int i,int j)
    {
        int index;
        if(j>=i) index = j-i;
        else index = n+i-j-1;
        return arr[index];
    }
    void display()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int index;
                if(j>=i) index = j-i;
                else index = n+i-j-1;
                cout<<arr[index]<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    toeplitz t(n);
    t.set(1,1,2);
    t.set(1,2,3);
    t.set(1,3,4);
    t.set(1,4,5);
    t.set(1,5,6);
    t.set(2,1,7);
    t.set(3,1,8);
    t.set(4,1,9);
    t.set(5,1,10);
    cout<<t.get(1,1)<<" ";
    cout<<t.get(1,2)<<" ";
    cout<<t.get(1,3)<<" ";
    cout<<t.get(1,4)<<" ";
    cout<<t.get(1,5)<<" ";
    cout<<t.get(2,1)<<" ";
    cout<<t.get(3,1)<<" ";
    cout<<t.get(4,1)<<" ";
    cout<<t.get(5,1)<<endl;

    t.display();

    return 0;
}