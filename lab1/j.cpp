#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<int> dq;
    char c;
    int n, sum = 0;
    while (cin >> c)
    {
        if (c == '!')
        {
            break;
        }
        if (c == '+')
        {
            cin >> n;
            dq.push_front(n);
        }
        if (c == '-')
        {
            cin >> n;
            dq.push_back(n);
        }
        if (c == '*')
        {
            if (dq.size() >= 2)
            {
                cout << dq.front() + dq.back() << endl;
                dq.pop_back();
                dq.pop_front();
            }
            else if (dq.size() == 1)
            {
                cout << dq.front() * 2 << endl;
                dq.pop_front();
            }
            else
            {
                cout << "error" << endl;
            }
        }
    }
    return 0;
}
