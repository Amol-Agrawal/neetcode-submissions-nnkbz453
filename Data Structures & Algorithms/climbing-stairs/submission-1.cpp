class Solution {
public:
    vector<int> dp;
    int climbStairs(int n) {
        dp.resize(n,-1);
        return dfs(n,0);
    }

    int dfs(int n , int i){
        if(i >n ) return 0;
        if( i == n) return 1;
        if( dp[i] != -1) return dp[i];
        return dp[i] = dfs(n,i+1) + dfs(n,i+2);
    }
};
