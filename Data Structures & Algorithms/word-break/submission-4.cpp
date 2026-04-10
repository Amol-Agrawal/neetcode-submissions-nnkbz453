class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set <string> st ( wordDict.begin(), wordDict.end());

        vector<int> dp (s.size(), -1);
        return dfs( s, st, 0, dp);
    }

    bool dfs( string& s, unordered_set<string>& st, int i, vector<int>& dp){
        if(i== s.size()) return true;
        int maxLen;
        for (auto &w : st) maxLen = max(maxLen, (int)w.size());
        if(dp[i] != -1) return dp[i];

        for (int j = i; j < min((int)s.size(), i + maxLen); j++){
            if(st.find(s.substr(i, j-i+1 )) != st.end()  ){
                if( dfs( s, st, j+1,dp)){
                    return dp[i] = true;
                }
            }
        }
        return dp[i] = 0;
    }
};
