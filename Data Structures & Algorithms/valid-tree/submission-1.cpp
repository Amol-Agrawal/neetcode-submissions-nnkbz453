class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);
        for(auto i : edges){
            int u = i[0];
            int v = i[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        vector<int> visit(n,0);
        int parent = -1; 

        if(dfs(0, -1 , adj , visit)) return false;

        for(int i :visit){
            if(i== 0 ) return false;
        }

        return true;
    }

    bool dfs( int i , int par ,vector<vector<int>>& adj , vector<int>& visit){

        visit[i] = 1 ;

        for(int it : adj[i]){
            if(visit[it]== 0){
                if(dfs( it , i ,adj , visit)) return true;
            }else if( it != par){
                return true;
            }
        }
        return false;
    }
};
