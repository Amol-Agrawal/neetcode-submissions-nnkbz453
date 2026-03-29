class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        int offset =1;
        for (int i = 1; i<= n; i++){

            if(offset*2 == i){
                offset =i;
            }
            ans[i]= 1+ ans[i-offset];
        }
        // for(int i = 0; i<=n ; i++){
        //     int k = i;
        //     while(k!=0 ){
        //         ans[i] += k%2;
        //         k= k/2;
        //     }

        // }
         return ans;
    }
};
