class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();

        int l = 0, r = 1;
        int maxp = 0;

        while(r< prices.size()){
            if(prices[r]> prices[l]){
                int pro = prices[r]- prices[l];
                maxp = max( pro, maxp);
            } else {
                l =r;
            }

            r++;
        }

        return maxp;
    }
};
