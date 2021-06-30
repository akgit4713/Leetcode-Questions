
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);
        int m=cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<int>v;
        v.push_back(cuts[0]);
        for(int i=1;i<m;i++)
            v.push_back(cuts[i]-cuts[i-1]);
        v.push_back(n-cuts[m-1]);
        int p=v.size();
        vector<vector<int>>dp(p+1,vector<int>(p+1,1e9));
        for(int i=0;i<p;i++)
            dp[i][i]=0;
        int sum[p+1];
        sum[0]=0;
        for(int i=0;i<p;i++)
            sum[i+1]=sum[i]+v[i];
        for(int len=2;len<=p;len++){
            for(int i=0;i+len-1<p;i++){
               for(int k=i;k<=i+len-1;k++){
                   dp[i][i+len-1]=min(dp[i][i+len-1],dp[i][k]+dp[k+1][i+len-1]+sum[i+len]-sum[i]);
               } 
            }
        }
        return dp[0][p-1];
    }
};
