class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> arr(nums.begin(), nums.end());

        int longest=0;

        for(int num : arr){
            int curr = num;
            int count = 0;
            if(arr.find(curr-1) == arr.end()){
                count =1 ;
                while(arr.find(curr+1) != arr.end() ){
                    count++;
                    curr++;
                }

                longest = max(longest, count);
            }

        }

        return longest;

    }
};
