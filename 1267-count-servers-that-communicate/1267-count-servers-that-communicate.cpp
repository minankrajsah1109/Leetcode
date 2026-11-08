class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> indexRowCount(m,0);
        vector<int> indexColCount(n,0);

        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1){ // found a server
                    indexRowCount[row] += 1;
                    indexColCount[col] += 1;
                }
            }
        }
        
        int resultServer = 0;
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1 && (indexRowCount[row] > 1 || indexColCount[col] > 1)){
                    resultServer++;
                }
            }
        }
        return resultServer;
    }
};