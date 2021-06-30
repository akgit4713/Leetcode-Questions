int dp[605][105][105];

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int h=strs.size();
        for(int i=0;i<h;i++){
            int zeroes=0,ones=0;
            for(int j=0;j<strs[i].length();j++){
                if(strs[i][j]=='0')
                    zeroes++;
                else
                    ones++;
            }
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]);
                    if(zeroes<=j&&ones<=k)
                    dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j-zeroes][k-ones]+1);
                }
            }
        }
        int ans=dp[h][m][n];
        for(int i=0;i<=h;i++){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++)
                    dp[i][j][k]=0;
            }
        }
        return ans;
    }
};
