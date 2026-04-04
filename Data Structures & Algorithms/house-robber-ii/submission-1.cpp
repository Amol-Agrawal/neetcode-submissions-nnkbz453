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

        int prev = nums[0];
        int prev2 = 0;

        for (int i =1 ; i< n ; i++){



            int pick = nums[i] ;
            if(i >1) pick += prev2;
            int not_pick = 0+ prev;


            int curr = max (pick , not_pick);
            
            prev2 = prev;
            prev = curr;
            

        }

        return prev;
    }
};
