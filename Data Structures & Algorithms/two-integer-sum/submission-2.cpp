class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         
        //  vector<pair<int, int>> arr;
        //  for(int i = 0; i < nums.size(); i++){
        //     arr.push_back({nums[i], i});
        //  }
        //  sort(arr.begin(), arr.end());


        //  int i= 0, j= nums.size()- 1;
        //  while(i<j){
        //     int cur = arr[i].first + arr[j].first ;
        //     if (cur == target){
            
        //         return {min(arr[i].second, arr[j].second),
        //                 max(arr[i].second, arr[j].second)};
        //     }
        //     else if( cur < target){
        //         i++;
        //     }
        //     else{
        //         j--;
        //     }
        //  }
        //  return {} ;

        unordered_map <int , int> hash;
        int n = nums.size();

        for(int i = 0 ; i< n ; i++){
            int diff = target - nums[i];
            if(hash.find(diff) != hash.end()){
                return {hash[diff], i};
            }
            hash.insert({nums[i], i});
        }
        return {};

    }
};
