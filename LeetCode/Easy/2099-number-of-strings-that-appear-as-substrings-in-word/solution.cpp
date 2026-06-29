class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = patterns.size();
        int cnt = 0;
        
        for(int i=0; i<n; i++){
            string temp = patterns[i];
            bool match = false;
            for(int j=0; j<word.size(); j++){
                int a =0;
                int b=j;
                while(a<temp.size() && b<word.size() && temp[a] == word[b]){
                    a++;
                    b++;
                }
                if(a==temp.size()){
                    match = true;
                    break;
                }
            }
            if(match) cnt++;
        }
        return cnt;
    }
};