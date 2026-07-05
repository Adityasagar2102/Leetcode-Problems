class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<pair<int,int>>> dp;

    pair<int,int> solve(vector<string>& board, int row, int col) {
        if (row < 0 || col < 0 || board[row][col] == 'X')
            return {INT_MIN, 0};

        if (row == 0 && col == 0)
            return {0, 1};

        if (dp[row][col].first != -1)
            return dp[row][col];

        int bestScore = INT_MIN;
        long long ways = 0;

        vector<pair<int,int>> parents = {
            solve(board, row - 1, col),
            solve(board, row, col - 1),
            solve(board, row - 1, col - 1)
        };

        for (auto &p : parents) {
            int score = p.first;
            int cnt = p.second;

            if (score == INT_MIN) continue;

            if (score > bestScore) {
                bestScore = score;
                ways = cnt;
            }
            else if (score == bestScore) {
                ways = (ways + cnt) % MOD;
            }
        }

        if (bestScore == INT_MIN)
            return dp[row][col] = {INT_MIN, 0};

        int val = (board[row][col] == 'S') ? 0 : board[row][col] - '0';

        return dp[row][col] = {bestScore + val, (int)(ways % MOD)};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();

        dp.assign(n, vector<pair<int,int>>(n, {-1, -1}));

        auto ans = solve(board, n - 1, n - 1);

        if (ans.first == INT_MIN)
            return {0, 0};

        return {ans.first, ans.second};
    }
};