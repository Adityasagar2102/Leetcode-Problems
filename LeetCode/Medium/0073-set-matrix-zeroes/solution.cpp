class Solution {
public:
// [row][col]
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> hashRow(n,0);
        vector<int> hashCol(m,0);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    hashRow[i]++;
                    hashCol[j]++;
                }
            }
        }

        for(int i=0; i<n; i++){
            if(hashRow[i]>0){
                for(int j=0; j<m; j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int i=0; i<m; i++){
            if(hashCol[i]>0){
                for(int j=0; j<n; j++){
                    matrix[j][i]=0;
                }
            }
        }
        return ;
    }
};