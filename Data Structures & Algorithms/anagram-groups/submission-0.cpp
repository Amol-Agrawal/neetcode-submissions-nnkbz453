class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string , vector<string>> grp;
       for (const auto&s : strs){

            string sorteds = s;
            sort(sorteds.begin(), sorteds.end());
            grp[sorteds].push_back(s);
       }
    
    vector<vector<string>> result;
    for(auto& pair :grp){
        result.push_back(pair.second);
    }
    return result;

    }
};
