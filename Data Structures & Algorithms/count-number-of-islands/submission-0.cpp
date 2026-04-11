class Solution {
public:

    void bfs(int r, int c , vector<vector<char>>& grid, vector<vector<int>>& vis, vector<int>& dirx,vector<int>& diry ){

        vis[r][c] = 1 ;
        queue< pair<int,int>> q;
        q.push({r,c});

        while(!q.empty()){
            r = q.front().first;
            c= q.front().second;
            q.pop();

            for(int i =0 ; i< 4 ; i++){

                    int newr = r + dirx[i];
                    int newc = c + diry[i];

                    if(newr >=0 && newc >=0 && newr <grid.size() && newc < grid[0].size()
                        && grid[newr][newc]== '1' && vis[newr][newc] != 1){
                            q.push({newr,newc});
                            vis[newr][newc] = 1;
                            
                        
                }
            }



        }


    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> dirx = { 0 , 1 ,0 , -1};
        vector<int> diry = {1 , 0 , -1 , 0};
        vector<vector<int>> vis (n, vector<int> (m , 0));
        int count = 0;
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j< m ; j++){
                if( !vis[i][j] && grid[i][j] == '1'){
                    count++;
                    bfs(i , j , grid, vis, dirx , diry);
                }
            }
        }
        return count;
    }
};




