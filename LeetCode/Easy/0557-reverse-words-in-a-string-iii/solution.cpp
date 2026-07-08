class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int start = 0;
        for(int i=0; i<n; i++){
            if(s[i] == ' '){
                reverse(s.begin()+start, s.begin()+i);
                start = i+1;
            }
        }
        reverse(s.begin()+start,s.end());
        return s;
    }
};