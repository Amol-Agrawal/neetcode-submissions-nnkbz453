class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
            vector<vector<int>> adj(n);

            for(auto it : edges){
                int u = it[0];
                int v = it[1];

                adj[u].push_back(v);
                adj[v].push_back(u);
            }

            vector<int> visit( n,0) ;
            int count =0;
            for(int i = 0 ; i< n ; i++){
                
                if(visit[i] != 1){
                    count++;
                    dfs( i , adj , visit);
                }
            } 

        return count;

    }

    void dfs(int i , vector<vector<int>>& adj , vector<int>& visit ){

        visit[i] = 1;

        for(int it : adj[i]){
            if(visit[it] ==0){
            dfs( it , adj ,visit);
            }
        }
    }
};
