class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int n = nums.size();
        int maxp = INT_MIN;
        int pre = 1 ; int suf = 1;

        for (int i = 0 ; i< n ; i++){

            if(pre == 0 ){pre =1; }
            pre = pre*nums[i];
            if(suf == 0 ) suf =1  ;
            suf = suf*nums[n-i-1];

            maxp = max( maxp, max(pre, suf));
        }

        return maxp;
    }

    
};
