class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(); //row
        int m = matrix[0].size(); //col

        vector<int>spiral;
        int left = 0,right = m-1;
        int top = 0, bottom = n-1;
        

        while(left<=right && top<=bottom){
            for(int i=left; i<=right;  i++){
                spiral.push_back(matrix[top][i]);
                // cout<<"test 1 "<<matrix[top][i]<<endl;
            }
            top++;
            for(int i=top; i<=bottom;  i++){
                spiral.push_back(matrix[i][right]);
                // cout<<"test 2 "<<matrix[i][right]<<endl;
            }
            right--;
            if(top<=bottom)
            {
                for(int i=right; i>=left;  i--){
                    spiral.push_back(matrix[bottom][i]);
                    // cout<<"test 3 "<<matrix[bottom][i]<<endl;
                }
            }
            bottom--;
            if(left<=right)
            {
                for(int i=bottom; i>=top;  i--){
                    spiral.push_back(matrix[i][left]);
                    // cout<<"test 4 "<<matrix[i][left]<<endl;
                }
            }
            left++;
        }

        return spiral;
        
    }
};