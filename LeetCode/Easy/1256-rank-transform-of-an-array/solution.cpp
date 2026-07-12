class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int> uom;
        
        int uni = 1;
        for(int i=0; i<temp.size(); i++){
            if(i!=0 && temp[i]> temp[i-1]) uni++;
            uom[temp[i]] = uni;
        }

        for(auto &it: arr){
            it = uom[it];
        }
        return arr;
    }
};