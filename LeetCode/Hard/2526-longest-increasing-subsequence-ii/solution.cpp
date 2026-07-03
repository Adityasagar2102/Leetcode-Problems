class Solution {
public:
    // vector<vector<long long>>dp;
    // long long solve(vector<long long>&nums,long long ind, long long last,long long k){
    //     if(ind == nums.size()) return 0;
    //     if(dp[ind][last+1] != -1) return dp[ind][last+1];
        
    //     long long take = 0;
    //     long long nottake = solve(nums,ind+1,last,k);
    //     if(last==-1 || (nums[ind] > nums[last] && nums[ind] <= nums[last]+k)){
    //         take = 1 + solve(nums, ind+1, ind,k);
    //     }

    //     return dp[ind][last+1] = max(take,nottake);
    // }
    static const long long MAXN = 1e5+5;
    static const long long INF = 1e9+5;
    pair<long long, long long> t[4*MAXN];

pair<long long, long long> combine(pair<long long, long long> a, pair<long long, long long> b) {
    if (a.first > b.first) 
        return a;
    if (b.first > a.first)
        return b;
    return make_pair(a.first, a.second + b.second);
}

void build(long long a[], long long v, long long tl, long long tr) {
    if (tl == tr) {
        t[v] = make_pair(a[tl], 1);
    } else {
        long long tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

pair<long long, long long> get_max(long long v, long long tl, long long tr, long long l, long long r) {
    if (l > r)
        return make_pair(0, 0);
    if (l == tl && r == tr)
        return t[v];
    long long tm = (tl + tr) / 2;
    return combine(get_max(v*2, tl, tm, l, min(r, tm)), 
                   get_max(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(long long v, long long tl, long long tr, long long pos, long long new_val) {
    if (tl == tr) {
        t[v] = make_pair(new_val, 1);
    } else {
        long long tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}
int lengthOfLIS(vector<int>& nums, int k) {
        long long n = nums.size();
        // dp.assign(n+1,vector<long long>(n+2,-1));
        // return solve(nums,0,-1,k);
        for(long long i=0; i<4*MAXN; i++){
            t[i]={0,0};
        }
        long long* a= new long long[MAXN+1];
         for(long long i=0; i<=MAXN; i++){
            a[i]=0;
         }
        vector<long long>dp(n,1);
        long long lis = 1;
        build(a,1,1,MAXN);
        for(long long i=0; i<n; i++){
            if (i>=0){
                auto b=get_max(1,1,MAXN,max(1LL,(long long)(nums[i]-k)),nums[i]-1);
                auto c = get_max(1,1,MAXN,nums[i],nums[i]);
                long long d = ((b.first+1)>c.first)?(b.first+1):(c.first);
                update(1,1,MAXN,nums[i],d);
                lis=max(lis,d);
            }
            // for(long long prev=0; prev<i; prev++){
            //     if(nums[i] >nums[prev] && nums[i]<=nums[prev]+k){
            //         dp[i] = max(dp[i],dp[prev]+1);
            //         lis = max(lis,dp[i]);
            //     }
            // }
        }

        return lis;
    }
};