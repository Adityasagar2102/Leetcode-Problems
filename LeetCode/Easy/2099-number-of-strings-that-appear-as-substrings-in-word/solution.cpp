class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;

        for (string &temp : patterns) {
            bool found = false;

            for (int j = 0; j < word.size(); j++) {
                int a = 0;
                int b = j;

                while (a < temp.size() && b < word.size() &&
                       temp[a] == word[b]) {
                    a++;
                    b++;
                }

                if (a == temp.size()) {
                    found = true;
                    break;
                }
            }

            if (found) cnt++;
        }

        return cnt;
    }
};