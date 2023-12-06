#include <iostream>
using namespace std;

void computePrefix(string p, int m, int lps[]) 
{  
    int l = 0; 
  
    lps[0] = 0;
    int i = 1; 
    while (i < m) { 
        if (p[i] == p[l]) { 
            l++; 
            lps[i] = l; 
            i++; 
        } 
        else  
        { 
                if (l != 0) { 
                l = lps[l - 1]; 
  
            } 
            else 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 

void kmpPatternSearch(string p, string S) 
{ 
    int m = p.length(); 
    int n = S.length(); 
  
    // creating lps array 
    int lps[m]; 
  
    // finding prefix table 
    computePrefix(p, m, lps); 
  
    int i = 0; 
    int j = 0; 
    while (i < n) { 
        if (p[j] == S[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == m) { 
            cout<<"Pattern found at location: "<<i - j<<"\n"; 
            j = lps[j - 1]; 
        } 
  
        // mismatch case 
        else if (i < n && p[j] != S[i]) { 
            // Skip matching lps[0..lps[j-1]] characters
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
} 

int main() {
    string text = "ABAAABAAAAABBAAAABA"; 
    string pat = "AAAB"; 
    kmpPatternSearch(pat, text); 
    return 0;
}