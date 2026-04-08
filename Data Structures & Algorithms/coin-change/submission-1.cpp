class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(amount == 0 ) return 0;
        if(coins.size()== 0) return -1;

        vector<vector<int>> dp(n, vector<int>(amount+1, -1)) ;

        
        int ans = helper( n-1, amount , coins, dp);

        return (ans >= 1e9) ? -1 :ans ;
    }

    int helper(int i, int amount , vector<int> & coins, vector<vector<int>>& dp ){
        
        if( dp[i][amount] != -1){
             return dp[i][amount];
        }
        if( i ==0 ){
            if(amount% coins[i] == 0 ) return dp[i][amount]= amount/coins[i];
            else return dp[i][amount] = 1e9; 
        }

        int not_take = 0 + helper ( i-1 , amount , coins, dp);
        int take = INT_MAX ;
        if(coins[i] <= amount ) {
            take = 1 + helper( i , amount- coins[i], coins, dp);
        }

        return dp[i][amount] = min (take ,not_take);

    }
};
