#include<iostream>
#include<string>
using namespace std;

bool one_swap_match(string s1, string s2, int n)
{
    // If lengths don't match, impossible!
    if(s1.length() != s2.length()) return false;
    
    int diff_count = 0;
    int pos1 = -1, pos2 = -1;
    
    // Find all positions where characters differ
    for(int i = 0; i < n; i++)
    {
        if(s1[i] != s2[i])
        {
            diff_count++;
            
            if(diff_count == 1) 
                pos1 = i;
            else if(diff_count == 2) 
                pos2 = i;
            else 
                return false;  // More than 2 differences? Impossible!
        }
    }
    
    // Case 1: Already equal (0 differences) ✅
    if(diff_count == 0) return true;
    
    // Case 2: Exactly 2 differences - check if one swap fixes them ✅
    if(diff_count == 2)
    {
        return (s1[pos1] == s2[pos2] && s1[pos2] == s2[pos1]);
    }
    
    // Case 3: Only 1 difference - can't fix with a swap ❌
    return false;
}

int main() {
    string s1 = "bank";
    string s2 = "knab";
    cout << "bank vs knab: " << one_swap_match(s1, s2, s2.length()) << endl;  // 0 (false)
    
    string s3 = "abcd";
    string s4 = "abdc";
    cout << "abcd vs abdc: " << one_swap_match(s3, s4, s3.length()) << endl;  // 1 (true)
    
    string s5 = "hello";
    string s6 = "hello";
    cout << "hello vs hello: " << one_swap_match(s5, s6, s5.length()) << endl;  // 1 (true) - already equal!
    
    return 0;
}