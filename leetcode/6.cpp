#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution{
public:
    bool isValid(string s){
        stack <char> st;
        for(char &c: s){
            if(c =='(' || c =='{' || c =='['){
                st.push(c);
            }
            else{
                if(st.empty()){
                    return false;
                }
                else if((c ==')' && st.top()!='(') || (c =='}' && st.top()!='{') || (c ==']' && st.top()!='[')){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

int main(){
    Solution solution;

    string s1 = "()";
    string s2 = "(){}[]";
    string s3 = "(]";

    cout<<solution.isValid(s1);
}