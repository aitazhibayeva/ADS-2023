#include <iostream>
#include <vector>
using namespace std;

void LPS(string s, int n, vector<int> &lps){
    int len = 0;
    int i = 1;
    while(i < n){
        if(s[i] == s[len]){
            lps[i] = len + 1;
            len++;
            i++;
        }
        else if(len != 0){
            len = lps[len-1];
        }
        else{
            lps[i] = 0;
            i++;
        }
    }
}

int KMP(string s){
    int n = s.size();
    vector<int> lps(n, 0);
    LPS(s, n, lps);

    return lps[n-1];
}

int main(){
    string s; cin>>s;//kokshetau 
    int n; cin>>n;
    string c;
    int lenght=0, cnt=0;
    vector<string> ans;
    s[0] = tolower(s[0]);
    int max = -1;
    for(int i=0; i<n; i++){
        cin>>c; //astana
        c[0] = tolower(c[0]);
        int ptSz = c.length(); //6
        string check = c+s; //yacuibaalmaty /000000000001
        int maxLPS = KMP(check); //yurgaalmaty /0000000001
        c[0]=toupper(c[0]); //moskowalmaty /00000001000
        if(maxLPS> max && maxLPS != 0){
            ans.clear();
            ans.push_back(c);
            max = maxLPS;
            cnt = 1;
        }
        else if(maxLPS == max){
            ans.push_back(c);
            cnt++;
        }
    }
    cout<<cnt<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
}