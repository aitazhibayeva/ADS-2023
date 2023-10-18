#include <iostream>
#include <cmath>
using namespace std;

bool check(int a[], int k, int n, int mid)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt = cnt + ceil(double(a[i]) / mid);
    }
    return cnt <= k;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    long long l = 0, r = 0, mid;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        r += a[i];
    }

    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (check(a, k, n, mid))
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    if (l == 0){
        l += 1;
    }
    cout << l;
}