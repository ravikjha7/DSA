#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Lower Triangular Matrix with Column Major Formula
class lower{
    int n;
    int *arr;
    public :
        lower(int n=3)
        {
            this->n = n;
            arr = new int[n*(n+1)/2]{0};
        }
        void set(int i,int j,int x)
        {
            if(j>=i)
            {
                int index = (j*(j-1)/2) + (i-1);
                arr[index] = x;
            }
            else
            {
                cout<<"First Go and Read How Lower Trinagular Matrix Works!!!"<<endl;
            }
        }
        int get(int i,int j)
        {
            if(j>=i)
            {
                int index = (j*(j-1)/2) + (i-1);
                return arr[index];
            }
            else return 0;
        }
        void display()
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(j>=i)
                    {
                        int index = (j*(j-1)/2) + (i-1);
                        cout<<arr[index]<<" ";
                    }
                    else cout<<"0 ";
                }
                cout<<endl;
            }
        }
};

// Lower Triangular Matrix using Row Major Formula
// class lower{
//     int n;
//     int *arr;
//     public :
//         lower(int n=3)
//         {
//             this->n = n;
//             arr = new int[n*(n+1)/2]{0};
//         }
//         void set(int i,int j,int x)
//         {
//             if(j>=i)
//             {
//                 int index = (n*(i-1) - (i-1)*(i-2)/2) + (j-i);
//                 arr[index] = x;
//             }
//             else
//             {
//                 cout<<"First Go and Read How Lower Trinagular Matrix Works!!!"<<endl;
//             }
//         }
//         int get(int i,int j)
//         {
//             if(j>=i)
//             {
//                 int index = (n*(i-1) - (i-1)*(i-2)/2) + (j-i);
//                 return arr[index];
//             }
//             else return 0;
//         }
//         void display()
//         {
//             for(int i=1;i<n;i++)
//             {
//                 for(int j=1;j<n;j++)
//                 {
//                     if(j>=i)
//                     {
//                         int index = (n*(i-1) - (i-1)*(i-2)/2) + (j-i);
//                         cout<<arr[index]<<" ";
//                     }
//                     else cout<<"0 ";
//                 }
//                 cout<<endl;
//             }
//         }
// };

int main()
{
    int n;
    cin>>n;
    lower l(n);
    l.set(3,6,7);
    l.set(4,6,5);
    l.set(6,6,9);
    l.set(1,2,5);
    l.set(2,2,2);
    l.set(5,4,4);
    l.set(4,4,6);
    cout<<l.get(4,4)<<endl;
    cout<<l.get(3,6)<<endl;
    cout<<l.get(4,6)<<endl;
    cout<<l.get(6,6)<<endl;
    cout<<l.get(1,2)<<endl;
    cout<<l.get(2,2)<<endl;
    cout<<l.get(5,4)<<endl;
    l.display();
    return 0;
}