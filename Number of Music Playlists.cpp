const int mod=1e9+7;
using ll=long long;

class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        ll dp[goal+1][n+1];
        memset(dp,0,sizeof dp);
        dp[0][0]=1;
        for(int i=1;i<=goal;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]+=dp[i-1][j-1]*1ll*(n-j+1);
                dp[i][j]+=dp[i-1][j]*1ll*max(j-k,0);
                dp[i][j]%=mod;
            }
        }
        ll ans=dp[goal][n];
        return (int)ans;
    }
};
