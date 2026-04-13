class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<int> del_r = {-1,0,1,0};
        vector<int> del_c = {0, 1, 0,-1};
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> pac( n, vector<int>(m,0)) ;
        vector<vector<int>> alt( n, vector<int>(m,0)) ;
        vector<vector<int>> ans;
        for( int c = 0 ; c< heights[0].size(); c++ ){
            dfs(0 ,c , pac, heights[0][c], heights, del_r , del_c );
            dfs(n-1 , c , alt,heights[n-1][c], heights,del_r , del_c );
        }

        for( int r = 0 ; r< heights.size(); r++ ){
            dfs(r ,0 , pac, heights[r][0], heights, del_r , del_c );
            dfs(r , m-1 , alt,heights[r][m-1], heights,del_r , del_c );
        }

        for( int r = 0 ; r< heights.size(); r++ ){
            for( int c = 0 ; c< heights[0].size(); c++ ){
                if(pac[r][c] ==1 &&  alt[r][c] ==1 ){
                    ans.push_back({r,c});
                }
            }
        }

        return ans;


    }

    void dfs( int row , int col ,vector<vector<int>>& visit , int prevh , vector<vector<int>>& heights, vector<int>& del_r,vector<int>& del_c ){


        if(row < 0 || col <0 || row >= heights.size()|| col >= heights[0].size() ||
            visit[row][col] ==1 || heights[row][col] < prevh ){
                return;
            }

        visit[row][col] = 1;

        for( int i = 0 ; i< 4 ; i++){
            int newr = row + del_r[i];
            int newc = col + del_c[i];
            dfs(newr , newc , visit, heights[row][col] , heights,del_r , del_c );
        }

    }
};
