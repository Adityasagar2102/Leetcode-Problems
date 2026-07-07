class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans = "";
        int kk = k;
        for(int i=s.size()-1; i>=0; i--){
            if(kk==0){
                kk=k;
                ans += '-';
            }

            if(isalnum(s[i])){
                ans += toupper(s[i]);
                kk--;
            }

        }
        // if(ans.empty()) return "";
        while(!ans.empty() && ans.back() == '-'){
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};