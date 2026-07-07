class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        int n = strs.size();
        int mn = INT_MAX;
        for(int i=1; i<n; i++){
            int j = 0;
            while(j<ans.size() && j<strs[i].size()){
                if(ans[j]!=strs[i][j]) break;
                j++;
            }
            mn = min(j,mn);
        }

        return ans.substr(0,mn);
    }
};