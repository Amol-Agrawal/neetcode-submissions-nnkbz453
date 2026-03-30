class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int p =1, zeroc =0;
        for (int i =0 ; i< nums.size(); i++){
            if(nums[i] != 0){
            p *= nums[i];}
            else{
                zeroc++;
            }

        }
        if (zeroc > 1) {
            return vector<int>(nums.size(), 0);
        }


        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (zeroc > 0) {
                res[i] = (nums[i] == 0) ? p : 0;
            } else {
                res[i] = p / nums[i];
            }
        }
        return res;

    }
};
