class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(amount == 0 ) return 0;
        if(coins.size()== 0) return -1;

        int ans =  helper(n-1 , amount , coins);

        return (ans >= 1e9) ? -1 :ans ;
    }

    int helper(int i, int amount , vector<int> & coins ){

        if( i ==0 ){
            if(amount% coins[i] == 0 ) return amount/coins[i];
            else return 1e9; 
        }

        int not_take = 0 + helper ( i-1 , amount , coins);
        int take = INT_MAX ;
        if(coins[i] <= amount ) {
            take = 1 + helper( i , amount- coins[i], coins);
        }

        return min (take ,not_take);

    }
};
