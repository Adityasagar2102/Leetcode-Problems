class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int cnt = 0;
        bool capital = true;
        if(word[0]>='a' && word[0]<='z'){
            capital = false;
        }


        for(int i=1; i<n; i++){
            if(word[i] >='A' && word[i]<='Z'){
                cnt++;
                if(!capital) return false;
            }
        }

        if(cnt==n-1 || cnt==0) return true;
        return false;
    }
};