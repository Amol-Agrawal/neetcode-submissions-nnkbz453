class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n, -1);
        return solve (nums, n-1, dp);
    }

    int solve (vector<int>& nums, int i, vector<int>& dp){
        int n = nums.size();
        if(i<0){
            return 0;
        }
        if(dp[i]!= -1){return dp[i];}

        int rob = nums[i] + solve(nums , i-2, dp);
        int skip = solve(nums, i-1, dp);

        return dp[i]= max(rob, skip);
    }
};
