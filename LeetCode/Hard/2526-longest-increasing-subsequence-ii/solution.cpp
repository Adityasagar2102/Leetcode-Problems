class Solution {
public:
    static const int MAXN = 100000;
    int seg[4 * MAXN];

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (tl == l && tr == r) return seg[v];

        int tm = (tl + tr) / 2;
        return max(
            query(v*2, tl, tm, l, min(r, tm)),
            query(v*2+1, tm+1, tr, max(l, tm+1), r)
        );
    }

    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            seg[v] = max(seg[v], val);
            return;
        }

        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, val);
        else
            update(v*2+1, tm+1, tr, pos, val);

        seg[v] = max(seg[v*2], seg[v*2+1]);
    }

    int lengthOfLIS(vector<int>& nums, int k) {
        memset(seg, 0, sizeof(seg));

        int ans = 1;

        for (int x : nums) {
            int left = max(1, x - k);
            int right = x - 1;

            int best = query(1, 1, MAXN, left, right);
            int cur = best + 1;

            update(1, 1, MAXN, x, cur);
            ans = max(ans, cur);
        }

        return ans;
    }
};