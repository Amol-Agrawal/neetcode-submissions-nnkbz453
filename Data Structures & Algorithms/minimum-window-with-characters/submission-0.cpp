class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map< char, int> st;
        for( char& x : t){
            st[x]++; 
        }

        int l =0; 
        int start; int minlength = INT_MAX; 
        int count= 0;
        
        for(int r = 0 ; r< s.size(); r++){

                if(st[s[r]] > 0 ) {
                    count ++;
                }
                st[s[r]]--;

                while(count == t.size()){
                    if(r-l+1 < minlength) {
                        minlength = r-l+1;
                        start = l;
                    }
                    st[s[l]]++;

                    if(st[s[l]] >0 ) count --;

                    l++;

                }
                    

        }

        if( minlength == INT_MAX) return "";
        return s.substr(start, minlength);

    }
};
