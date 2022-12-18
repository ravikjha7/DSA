#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    stack<char> st;
    string s;
    cin>>s;
    int flag = 1;
    for(int i = 0; i < s.size() ; i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
        if(s[i] == ')') 
        {
            if(!st.empty() && st.top() == '(') st.pop();
            else 
            {
                flag = 0;
                break;
            }
        }
        if(s[i] == '}') 
        {
            if(!st.empty() && st.top() == '{') st.pop();
            else 
            {
                flag = 0;
                break;
            }
        }
        if(s[i] == ']') 
        {
            if(!st.empty() && st.top() == '[') st.pop();
            else 
            {
                flag = 0;
                break;
            }
        }
    }
    if(!st.empty()) flag = 0;
    if(flag) cout << "Matched!!!" << endl;
    else cout << "Not Matched!!!" << endl;
    return 0;
}