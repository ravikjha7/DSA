#include<iostream>
#include"vector.h"
using namespace std;
typedef long long ll;

int main()
{
    vector<char> v;
    v.push_back('a');
    v.push_back('b');
    v.push_back('c');
    v.push_back('d');

    cout<<"Entire Vector : "<<endl;
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;
    
    cout<<v.front()<<" "<<v.back()<<endl;
    v.pop_back();
    cout<<v.front()<<" "<<v.back()<<endl;

    cout<<"Size : "<<v.size()<<" Capacity : "<<v.capacity()<<endl;

    cout<<v.At(2)<<endl;
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    cout<<"Khali Vector Ka Size : "<<v.size()<<endl;

    return 0;
}