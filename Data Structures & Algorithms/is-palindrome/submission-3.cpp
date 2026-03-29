class Solution {
public:
    bool isPalindrome(string s) {
       int n = s.size();
        
        for (char &x : s){
            x = tolower(x);
        }
        int i = 0 , j= n-1;
       while(i<j) {
            if(!isalnum(s[i])) { i++; continue; }
            if(!isalnum(s[j])) { j--; continue; }
            if(s[i]==s[j]) {
                i++;j--;
            }
            else return false;
       }
       return true;
    }
};
