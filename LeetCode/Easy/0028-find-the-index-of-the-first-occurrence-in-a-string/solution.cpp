class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        int ind = -1;

        for(int i=0; i<=n-m; i++){
            bool match = true;
            // int ind = -1
            for(int j=0; j<m; j++){
                
                if(haystack[j+i]!= needle[j]){
                    match = false;
                    break;
                }
            }
            if(match) return i;
        }

        return -1;

    }
};