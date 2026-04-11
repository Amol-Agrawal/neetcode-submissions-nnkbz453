class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    
        vector<vector<int>> ans;
        vector<int> curr;

        sort(nums.begin(), nums.end());

        f ( 0 , curr,0,nums , target, ans);


        return ans;
    }

    void f(int i , vector<int>& curr ,int total,  vector<int>& nums, int target, vector<vector<int>>& ans){
        if(target ==total ) {
            ans.push_back(curr);
            return;
        }

        for(int j = i ; j< nums.size(); j++){
            if(total > target) return;

            curr.push_back(nums[j]);
            f ( j , curr,total+ nums[j],nums , target, ans);
            curr.pop_back();
        }

        
        
    }


};
