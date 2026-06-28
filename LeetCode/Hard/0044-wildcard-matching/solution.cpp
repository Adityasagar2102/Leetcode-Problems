class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int starIdx = -1, matchIdx = 0;
        int n = s.size(), m = p.size();
        
        while (i < n) {
            // 1. Exact character match or universal single-char match '?'
            if (j < m && (p[j] == '?' || p[j] == s[i])) {
                i++;
                j++;
            }
            // 2. We hit a '*', record the checkpoint and try matching 0 characters first
            else if (j < m && p[j] == '*') {
                starIdx = j;
                matchIdx = i;
                j++; // Advance pattern past the '*'
            }
            // 3. Current characters mismatch, but we can backtrack to the last '*' checkpoint
            else if (starIdx != -1) {
                j = starIdx + 1; // Reset pattern pointer to right after the '*'
                matchIdx++;      // Force the '*' to consume one more character from s
                i = matchIdx;    // Restart string matching from this updated position
            }
            // 4. Mismatch and absolutely no '*' to salvage the match
            else {
                return false;
            }
        }
        
        // Clean up any remaining trailing stars in the pattern (e.g., s = "a", p = "a***")
        while (j < m && p[j] == '*') {
            j++;
        }
        
        return j == m;
    }
};