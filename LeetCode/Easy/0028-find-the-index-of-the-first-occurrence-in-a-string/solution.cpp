class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int>lps(needle.size(),0);
        int pre = 0;
        for(int i=1; i<needle.size(); i++){
            while(pre>0 &&needle[i]!=needle[pre]){
                pre = lps[pre-1];
            }
            if(needle[i] == needle[pre]){
                pre++;
                lps[i]=pre;
            }
        }

        int n=0;
        for(int i=0; i<haystack.size(); i++){
            while(n>0 && haystack[i] != needle[n]){
                n = lps[n-1];
            }
            if(haystack[i]==needle[n]){
                n++;
            }
            if(n==needle.size())
                return i-n+1;
        }
        return -1;
    }
};