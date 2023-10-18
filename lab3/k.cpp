// #include <iostream>
// #include <vector>

// using namespace std;

// int minSubarraySum(vector<int>& arr, int k) {
//     int n = arr.size();
//     int minLen = n + 1;
//     int left = 0;
//     int currentSum = 0;

//     for (int right = 0; right < n; ++right) {
//         currentSum += arr[right];

//         while (currentSum >= k) {
//             minLen = min(minLen, right - left + 1);
//             currentSum -= arr[left];
//             left++;
//         }
//     }

//     return minLen;
// }

// int main() {
//     int n, k;
//     cin >> n >> k;

//     vector<int> arr(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> arr[i];
//     }

//     int result = minSubarraySum(arr, k);
//     cout << result << endl;

//     return 0;
// }



#include <iostream>
#include <vector>
using namespace std;

int minSub(vector<int> &a, int k){
    int l=0, minLen = a.size() + 1;
    int curSum = 0, size = a.size();

    for(int r=0; r<size; r++){
        curSum += a[r];

        while(curSum >= k){
            minLen = min(minLen, r-l+1);
            curSum -=a[l];
            l++;
        }
    }
    return minLen;
}

int main(){
    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int res = minSub(a, k);
    cout<<res;
    return 0;

}