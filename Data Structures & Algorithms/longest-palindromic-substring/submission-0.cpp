class Solution {
public:
    string longestPalindrome(string s) {
        int n= s.size();
        string res = "";
        int reslen = 0;

        for(int i = 0 ; i< n ; i++){

            int l = i; int r=i;
            while(l>=0 && r< n  && s[l]== s[r] ){
                l--; r++;            }

            if( reslen < (r-l-1) && l<=r){
                res = s.substr(l+1,r-l-1 );
                reslen = r-l-1;

            }

            l = i ; r= i+1;
            while(l>=0 && r< n  && s[l]== s[r] ){
                l--; r++;            }
            
            if( reslen < (r-l-1) && l<=r){
                res = s.substr(l+1 ,r-l-1 );
                reslen = r-l-1;

            }

        }

        return res;
    
        
    }

   
};
