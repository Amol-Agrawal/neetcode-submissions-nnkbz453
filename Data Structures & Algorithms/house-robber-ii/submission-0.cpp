class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()== 1 )return nums[0];

        vector<int> temp1( nums.begin() +1 , nums.end());
        vector<int> temp2 (nums.begin()  , nums.end()-1 );

        return max( help(temp1), help(temp2));
    }

    int help(vector<int> nums){
        int n = nums.size();
        if(n == 0 ) return 0;
        if(n == 1) return nums[0];

        vector<int> dp ( n,-1);
        dp[0]= nums[0];

        for (int i =1 ; i< n ; i++){

            int pick = nums[i] ;
            if(i >1) pick += dp[i-2];
            int not_pick = dp[i-1];

            dp[i] = max (pick , not_pick);

        }

        return dp[n-1];
    }
};
