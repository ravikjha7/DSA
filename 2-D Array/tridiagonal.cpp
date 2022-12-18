#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class tridiagonal{
    int n;
    int *arr;
    public :
    tridiagonal(int n=5)
    {
        this->n = n;
        arr = new int[3*n-2]{0};
    }
    void set(int i,int j,int x)
    {
        if(abs(i-j)<=1)
        {
            int index;
            if(i-j==1) index = i-1;
            else if(i==j) index = n-1 + (i-1);
            else index = 2*n -1 + (i-1);
            arr[index] = x;
        }
        else cout<<"Kaha Kaha se Aa Jaate Hai Idhar Log!!"<<endl;
    }

    int get(int i,int j)
    {
        if(abs(i-j)<=1)
        {
            int index;
            if(i-j==1) index = i-1;
            else if(i==j) index = n-1 + (i-1);
            else index = 2*n -1 + (i-1);
            return arr[index];
        }
        else return 0;
    }

    void display()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(abs(i-j)<=1)
                {
                    int index;
                    if(i-j==1) index = i-1;
                    else if(i==j) index = n-1 + (i-1);
                    else index = 2*n -1 + (i-1);
                    cout<<arr[index]<<" ";
                }
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
    tridiagonal t(n);
    t.set(4,5,6);
    t.set(4,3,2);
    t.set(4,6,9);
    t.set(4,2,8);
    t.set(3,4,3);
    t.set(3,3,4);
    t.set(5,5,7);
    cout<<t.get(4,5)<<" ";
    cout<<t.get(4,3)<<" ";
    cout<<t.get(4,6)<<" ";
    cout<<t.get(4,2)<<" ";
    cout<<t.get(3,4)<<" ";
    cout<<t.get(3,3)<<" ";
    cout<<t.get(5,5)<<endl;

    t.display();

    return 0;
}