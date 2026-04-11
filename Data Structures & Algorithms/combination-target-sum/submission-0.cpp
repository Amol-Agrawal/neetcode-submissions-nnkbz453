class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    
        vector<vector<int>> ans;
        vector<int> curr;
        f ( 0 , curr,nums , target, ans);


        return ans;
    }

    void f(int i , vector<int>& curr , vector<int>& nums, int target, vector<vector<int>>& ans){
        if(target ==0 ) {
            ans.push_back(curr);
            return;
        }

        if( i >= nums.size() || target <0 ){
            return ;
        }

        curr.push_back(nums[i]);
        f ( i , curr,nums , target- nums[i], ans);
        curr.pop_back();
        f ( i+1 , curr, nums , target, ans);

        
        
    }


};
