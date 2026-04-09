class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st( wordDict.begin(), wordDict.end());

        int n =s.size();
        vector<int> dp (n,-1);
        dfs( 0, s , st ,dp);

        return dp[0] ; 
    }

    bool dfs( int i , string s , unordered_set<string>& st,vector<int> &dp){
        if(i== s.size()){
            return 1;
        }
        if(dp[i] != -1) return dp [i];

        string temp ="";

        for( int j =i ; j< s.size(); j++){
            temp += s[j];

            if( st.count( temp ) && dfs(j+1, s,st , dp)){
                return dp[i] = 1;
            }
        }

        return dp[i] = 0;

    }


};
