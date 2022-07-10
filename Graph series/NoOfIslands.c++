class Solution{
    public:

    void dfs(int i,int j,int n,int m,vector<vector<int>>&vis,vector<vector<char>>&grid)
        {
            if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!='1') return;
            
            grid[i][j] = '2';
            
            if(!vis[i][j])
            {
                vis[i][j]=1;
                dfs(i-1,j,n,m,vis,grid);
                dfs(i+1,j,n,m,vis,grid);
                dfs(i,j-1,n,m,vis,grid);
                dfs(i,j+1,n,m,vis,grid);
                dfs(i-1,j-1,n,m,vis,grid);
                dfs(i-1,j+1,n,m,vis,grid);
                dfs(i+1,j-1,n,m,vis,grid);
                dfs(i+1,j+1,n,m,vis,grid);
            }
            
        }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        vector<vector<int>>vis(n , vector<int>(m , 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,n,m,vis,grid);
                    count++;
                }
            }
        }
        return count;
    }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n, m;
        cin >>n >> m;
        vector<vector<int>> grid(n, vector<char>(m, '#'));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
            }
        }
    }

    Solution obj;
    int ans = obj.numIslands(grid, n, m);
    cout << ans << '\n';
}