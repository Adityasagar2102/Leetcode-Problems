class Solution {
public:
    bool isSubsequence(string s, string t) {
        int tar = 0;
        if(!s.size()) return true;
        for(int i=0; i<t.size(); i++){
            if(s[tar] == t[i]){
                tar++;
                if(tar==s.size()) return true;
            }
        }

        return false;
    }
};