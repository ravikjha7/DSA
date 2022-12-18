#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int getIthbit(int n,int i)
{
    // Just set ith bit of a number as 1
    // then using and of our number and the new number will give us required answer
    int x = (1<<i);
    if((n&x)>0) return 1;
    else return 0;
}

void setIthbit(int &n,int i)
{
    // To set the ith bit of a number we will make one new number which will have 0 at all other places except for ith position
    int x = (1<<i);
    // If we will OR any number with such number it will set the ith bit of that number
    n = (n|x);
}

void clearIthbit(int &n,int i)
{
    // For clearing the ith bit we need a number with 0 at ith position and 1 at rest of the position
    // To make such number , we will make a nmber with 1 at ith position and 0 at rest of the positon i.e 1<<i and take negation of it
    int x = (~(1<<i));
    n = (n & x);
}

void updateIthbit(int &n,int i,int b)
{

    // We will first clear the ith bit
    clearIthbit(n,i);
    // Now we will make a number having the required bit to be set at the ith position
    int x = (b<<i);
    // It will set b as ith bit
    // Now we will set ith bit of n as b
    n = (n|x);

    // My Method
    // if(b==1) setIthbit(n,i);
    // else clearIthbit(n,i);
}

void toggleIthbit(int &n,int i)
{
    // First , to check whether the required bit is 0 or 1 we are using getIthbit functinality
    int x = (1<<i);
    // If it is 1 , we are clearing the ith bit
    if((n&x)) n = (n&(~x));
    // else we are setting the ith bit
    else n = (n|x);
}

void clearlastIbits(int &n,int i)
{
    // For this we need a number with all 1 and last 1 bit as 0
    // Ex : 11111000 
    // 1111111111111 it is actually -1 or you can say (~0)
    int x = (-1<<i);
    // Left shifting -1 with i will give us a number with all bits 1 and last i bits as 0
    n = (n&x);
}

void setlastIbits(int &n,int i)
{
    // For setting last I bits we need a number as 000000111 with everywhere 0 except at last I bits
    int x = (1<<i) - 1;
    n = (n|x);
}

void clearbitsinRange(int &n,int i,int j)
{
    // To clear bits in range we need a number like this 111000011
    // where the range is cleared and rest is set
    int x = (-1<<(j+1));
    // To make this type of a number , we will first clear last I bits
    // i.e 111000000
    x = (x|((1<<i)-1));
    // Then set last j bits i.e 111000011
    n = (n&x);
}

int main()
{
    int n,i,v,j;
    // cin>>n>>i;
    // cin>>n>>i>>v;
    // cout<<getIthbit(n,i)<<endl;
    // setIthbit(n,i);
    // clearIthbit(n,i);
    // updateIthbit(n,i,v);
    // toggleIthbit(n,i);
    // clearlastIbits(n,i);
    // setlastIbits(n,i);
    cin>>n>>i>>j;
    clearbitsinRange(n,i,j);

    cout<<n<<endl;
    return 0;
}