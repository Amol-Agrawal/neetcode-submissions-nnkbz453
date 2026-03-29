class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false ; 
        // sort(s.begin(),s.end() );
        // sort(t.begin() , t.end());

        // for (int i = 0; i< s.size() ; i++){
        //     if( s[i] != t[i]) return false;
        // }
        // return true;

        unordered_map<char, int> cs;
        unordered_map<char, int> ct;

        for(int i = 0; i < s.size(); i++){
            cs[s[i]]++;
            ct[t[i]]++;
        }

        return cs == ct;
    }
};
