#include <iostream>
#include <stack>
using namespace std;

string back_s1(string s)
{
    stack<char> s1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '#')
        {
            s1.pop();
        }
        else
        {
            s1.push(s[i]);
        }
    }
    string res1 = "";
    while (!s1.empty())
    {
        res1 += s1.top();
        s1.pop();

    }
    return res1;
}

string back_s2(string k)
{
    stack<char> s2;
    for (int i = 0; i < k.size(); i++)
    {
        if (k[i] == '#')
        {
            s2.pop();
        }
        else
        {
            s2.push(k[i]);
        }
    }
    string res2 = "";
    while (!s2.empty())
    {
        res2 += s2.top();
        s2.pop();
    }
    return res2;
}

int main()
{
    string s, k;
    cin >> s >> k;
    if (back_s1(s) == back_s2(k))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}