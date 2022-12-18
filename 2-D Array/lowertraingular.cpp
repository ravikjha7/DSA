#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Lower Triangular Matrix with Row Major Formula
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
//             if(i>=j)
//             {
//                 int index = (i*(i-1)/2) + (j-1);
//                 arr[index] = x;
//             }
//             else
//             {
//                 cout<<"First Go and Read How Lower Trinagular Matrix Works!!!"<<endl;
//             }
//         }
//         int get(int i,int j)
//         {
//             if(i>=j)
//             {
//                 int index = (i*(i-1)/2) + (j-1);
//                 return arr[index];
//             }
//             else return 0;
//         }
//         void display()
//         {
//             for(int i=1;i<=n;i++)
//             {
//                 for(int j=1;j<=n;j++)
//                 {
//                     if(i>=j)
//                     {
//                         int index = (i*(i-1)/2) + (j-1);
//                         cout<<arr[index]<<" ";
//                     }
//                     else cout<<"0 ";
//                 }
//                 cout<<endl;
//             }
//         }
// };

// Lower Triangular Matrix using Column Major Formula
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
            if(i>=j)
            {
                int index = (n*(j-1) - (j-1)*(j-2)/2) + (i-j);
                arr[index] = x;
            }
            else
            {
                cout<<"First Go and Read How Lower Trinagular Matrix Works!!!"<<endl;
            }
        }
        int get(int i,int j)
        {
            if(i>=j)
            {
                int index = (n*(j-1) - (j-1)*(j-2)/2) + (i-j);
                return arr[index];
            }
            else return 0;
        }
        void display()
        {
            for(int i=1;i<n;i++)
            {
                for(int j=1;j<n;j++)
                {
                    if(i>=j)
                    {
                        int index = (n*(j-1) - (j-1)*(j-2)/2) + (i-j);
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
    lower l(n);
    l.set(6,3,7);
    l.set(6,4,5);
    l.set(6,6,9);
    l.set(2,1,5);
    l.set(2,2,2);
    l.set(4,5,4);
    l.set(4,4,6);
    cout<<l.get(4,4)<<endl;
    cout<<l.get(6,3)<<endl;
    cout<<l.get(6,4)<<endl;
    cout<<l.get(6,6)<<endl;
    cout<<l.get(2,1)<<endl;
    cout<<l.get(2,2)<<endl;
    cout<<l.get(4,5)<<endl;
    l.display();
    return 0;
}