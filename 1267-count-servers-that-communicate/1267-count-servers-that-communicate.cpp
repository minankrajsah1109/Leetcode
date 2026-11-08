class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> colServerCount(n, 0);
        vector<int> RowAkelaServerCol(m,-1);

        int resultServer = 0;

        for(int row = 0; row < m; row++){
            int countServerRow = 0;
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1){
                    countServerRow += 1;
                    colServerCount[col]++;
                    RowAkelaServerCol[row] = col;
                }
            }

            if(countServerRow > 1){
                resultServer += countServerRow;
                RowAkelaServerCol[row] = -1;  // no akela server in this row
            }
        }

        // Check Akela Servers in each row
        for(int row = 0; row < m; row++){
            if(RowAkelaServerCol[row] != -1){
                int col = RowAkelaServerCol[row];
                if(colServerCount[col] > 1){
                    resultServer += 1;
                }
            }
        }
        return resultServer;
    }
};