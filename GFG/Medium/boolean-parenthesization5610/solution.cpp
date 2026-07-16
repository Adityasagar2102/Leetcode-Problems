class Solution {
  public:
    int dptrue[101][101];
    int dpfalse[101][101];
    int solve(string &s, int i, int j, bool isTrue){
        if(i>j) return 0;
        if(i==j){
            if(isTrue) return s[i]=='T';
            else return s[i]=='F';
        }
        
        if(isTrue && dptrue[i][j]!=-1) return dptrue[i][j];
        if(!isTrue && dpfalse[i][j]!=-1) return dpfalse[i][j];
        
        int ans = 0;
        
        for(int k=i+1; k<=j-1; k+=2){
            int lt = solve(s,i,k-1,true);
            int lf = solve(s,i,k-1,false);
            int rt = solve(s,k+1,j,true);
            int rf = solve(s,k+1,j,false);
            // cout<<lt<<" "<<lf<<" "<<rt<<" "<<rf<<endl;
            
            if(s[k]=='&'){
                // cout<<"TEST "<<endl;
                if(isTrue){
                    ans+= lt*rt;
                }else{
                    ans += lt*rf + lf*rt + lf*rf;
                }
            }
            if(s[k]=='|'){
                if(isTrue){
                    ans += lt*rf + lf*rt + lt*rt;
                }else{
                    ans += lf*rf;
                }
            }
            if(s[k]=='^'){
                if(isTrue){
                    ans += lt*rf + lf*rt;
                }else{
                    ans += lt*rt + lf*rf;
                }
            }
            
            // cout<<"test"<< ans <<endl;
            
        }
        if(isTrue) return dptrue[i][j] = ans;
        else return dpfalse[i][j] = ans;
        
        // return ans;
    }
    int countWays(string &s) {
        // code here
        memset(dptrue,-1,sizeof(dptrue));
        memset(dpfalse,-1,sizeof(dpfalse));
        int n = s.size();
        return solve(s,0,n-1,true);
        
    }
};