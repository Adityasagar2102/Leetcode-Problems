class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        string made = "";
        for(int i=0; i<n; i++){
            if(s[i]>='a' && s[i]<='z'){
                made += s[i];
            }else if(s[i]>='A' && s[i]<='Z'){
                made += tolower(s[i]);
            }else if(s[i]>='0' && s[i]<='9'){
                made += s[i];
            }
        }
        cout << made;
        int m = made.size();
        if(m==0) return true;
        int i = 0;
        while(i<=m/2){
            if(made[i]!=made[m-i-1]){
                cout << i;
                return false;
            }
            i++;
        }
        return true;

    }
};