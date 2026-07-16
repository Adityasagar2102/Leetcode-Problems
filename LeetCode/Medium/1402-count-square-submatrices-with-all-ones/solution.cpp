class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int totalSquares = 0;
        // for(int i=0; i<n; i++){
        //     dp[i][0] = matrix[i][0];
        //     totalSquares += dp[i][0];
        // }
        // for(int j=1; j<m; j++){
        //     dp[0][j] = matrix[0][j];
        //     totalSquares += dp[0][j];
        // }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]){
                    if(i==0 || j==0)dp[i][j] = 1;
                    else dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
                    totalSquares += dp[i][j];
                }
            }
        }
        return totalSquares;
    }
};