class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = -1;
        int n= nums.size();
        int l = 0, r = n-1;

        while(l <= r ){

            int m = (l+r)/2;
            if(nums[m] == target )  return m;
            if( nums[m] >= nums[l] ){
                if( nums[l]<= target && target <= nums[m]){
                    r = m-1;
                }else l= m+1;

            }else {
                if(nums[m+1]<= target && target <= nums[r]){
                    l = m+1;
                }else r = m-1;
            }

        }


        return res;

    }
};
