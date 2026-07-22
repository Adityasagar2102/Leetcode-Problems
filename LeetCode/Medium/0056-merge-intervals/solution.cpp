class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<vector<int>>result;

        sort(intervals.begin(), intervals.end());


        result.push_back(intervals[0]);
        int i=1;
        while(i<n){
            if(result.back()[1] >= intervals[i][0]){
                result.back()[1]  = max(result.back()[1],intervals[i][1]);
            }else{
                result.push_back(intervals[i]);
            }
            i++;
        }

        return result;
    }
};