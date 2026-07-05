class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        vector<string>rows(numRows+1);
        bool goingdown = true;
        int row = 0;
        if(numRows==1) return s;

        for(int i=0; i<n; i++){
            if(row==0) goingdown = true;
            if(row==numRows-1) goingdown = false;
            rows[row] += s[i];

            if(goingdown){
                row++;
            }else{
                row--;
            }
        }
        string ans = "";
        for(auto it: rows){
            ans += it;
        }
        return ans;
    }
};