class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map< char, int> freq;
        int l = 0 ; int res= 0;
        int maxf = 0;

        for (int r = 0 ; r< s.size(); r++){

            freq[s[r]]++;
            maxf = max (freq[s[r]], maxf);

            while((r-l+1 - maxf) > k){
                freq[s[l]] -- ;
                l++;

            }

            res = max (res, r-l+1);



        }

        return res;
    }
};
