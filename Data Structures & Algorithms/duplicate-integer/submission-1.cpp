class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> dup ;

        for(int num: nums){
            if(dup.count(num)){
                return true;
            }
            dup.insert(num);
        }
        
        // for(int i = 0 ; i <n-1 ; i++ ){
        //     for( int j=i+1 ; j< n ; j++){
        //         if(nums[i]== nums[j]){
        //             return true ;
        //         }
        //     } 

        // }
        return false;
    }
};