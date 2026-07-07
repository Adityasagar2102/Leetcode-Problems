class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();

        int len = 0;
        int prev = 0;

        for(int i=0; i<n; i++){
            if(s[i]==' '){
                if(len!=0){
                    prev = len;
                }
                len=0;
                continue;
            }
            len++;
        }
        if(len!=0) return len;
        return prev;
    }
};