class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        vector<int> a(n,n);
        vector<int> b(n,n);
        vector<int> c(n,n);

        if(s[n-1] == 'a') a[n-1] = n-1;
        if(s[n-1] == 'b') b[n-1] = n-1;
        if(s[n-1] == 'c') c[n-1] = n-1;

        for(int i = n-2; i>=0; i--){
            if(s[i]=='a'){
                a[i] = i;
                b[i] = b[i+1];
                c[i] = c[i+1];
            }else if(s[i]=='b'){
                b[i] = i;
                a[i] = a[i+1];
                c[i] = c[i+1];

            }else if(s[i]=='c'){
                a[i] = a[i+1];
                b[i] = b[i+1];
                c[i] = i;
            }
        }

        int cnt = 0;
        for(int i=0; i<n; i++){
            int temp = max({a[i],b[i],c[i]});
            if(temp!=n){
                cnt += n-temp;
            }
        }

        return cnt;
    }
};