#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Term{
    int coeff;
    int exp;
};

class Poly{
    int n;
    struct Term *t;
    public:
    Poly(int n)
    {
        this->n = n;
        t = new Term[n];
    }
    void read()
    {
        for(int i=0;i<n;i++)
        {
            cout<<"Enter Coefficient and Exponent of Term no "<<i+1<<" : ";
            cin>>t[i].coeff>>t[i].exp;
        }
    }
    void display()
    {
        for(int i=0;i<n-1;i++)
        {
            cout<<t[i].coeff<<"x^"<<t[i].exp<<" + ";
        }
        if(t[n-1].exp!=0)
        cout<<t[n-1].coeff<<"x^"<<t[n-1].exp<<endl;
        else cout<<t[n-1].coeff<<endl;
   }
   ll evaluate(int x)
   {
       ll ans = 0;
       for(int i=0;i<n;i++)
       {
           ans += t[i].coeff*pow(x,t[i].exp);
       }
       return ans;
   }
   Poly operator +(Poly &s)
   {
       Poly *sum = new Poly(n+s.n);
       int i=0,j=0,k=0;
       while(i<n&&j<s.n)
       {
           if(t[i].exp>s.t[j].exp) sum->t[k++] = t[i++];
           else if(t[i].exp<s.t[j].exp) sum->t[k++] = s.t[j++];
           else{
               sum->t[k] = t[i++];
               sum->t[k++].coeff += s.t[j++].coeff;
           }
       }
       for(;i<n;i++)
       {
           sum->t[k++] = t[i++];
       }
       for(;j<s.n;j++)
       {
           sum->t[k++] = s.t[j++];
       }
       sum->n = k;
       return *sum;
   }
};

int main()
{
    Poly first(5);
    first.read();
    first.display();
    cout<<first.evaluate(7)<<endl;
    Poly second(3);
    second.read();
    second.display();
    cout<<second.evaluate(7)<<endl;
    Poly sum = first + second;
    sum.display();
    cout<<sum.evaluate(7)<<endl;
    return 0;
}