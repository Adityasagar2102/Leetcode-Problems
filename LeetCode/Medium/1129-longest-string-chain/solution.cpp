class Solution {
public:


    bool comp(string&s, string&t){
        if(s.size() != t.size()+1) return false;
        for(int i=0; i<s.size(); i++){
            int si = 0;
            int ti = 0;
            bool match = true;
            while(si<s.size() && ti<t.size()){
                if(si==i){
                    si++;
                    continue;
                }
                if(s[si]!=t[ti]){
                    match = false;
                    break;
                }

                si++;
                ti++;
            }
            if(match){
                return true;
            }
        }
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](string &s1, string &s2){
            return s1.length() < s2.length();
        });
        vector<int>dp(n,1);

        int lis = 1;

        for(int i=0;i<n;i++){
            for(int prev =0; prev<i; prev++){
                if(comp(words[i],words[prev])){
                    dp[i] = max(dp[i],dp[prev]+1);
                    lis = max(lis,dp[i]);
                }
            }
        }

        return lis;

    }
};