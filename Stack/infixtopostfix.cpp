#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int prec(char c)
{
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    if(c == '^') return 3;
    return -1;
}

void infixtopostfix(string s)
{
    stack<char> st;
    string ans = "";
    for(int i = 0; i < s.size() ; i++)
    {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) ans += s[i];
        else if(s[i] == '(') st.push(s[i]);
        else if(s[i] == ')') 
        {
            while(!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty() && prec(st.top())>=prec(s[i]))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    cout << ans << endl;
}

int main()
{
    string s;
    cin >> s;
    infixtopostfix(s);

    return 0;
}