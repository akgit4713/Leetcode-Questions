const int mxn=55,mod=1e9+7;
long long dp[mxn][mxn][mxn];
class Solution {
    
public:
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,0,sizeof dp);
        dp[0][startRow+1][startColumn+1]=1;
        long long  ans=0;
        for(int i=1;i<=maxMove;i++){
            for(int j=0;j<=m+1;j++){
                for(int k=0;k<=n+1;k++){
                    for(int x=-1;x<=1;x++){
                        for(int y=-1;y<=1;y++){
                            if(abs(x)+abs(y)==1){
                                int nx=j+x;
                                int ny=k+y;
                                if(nx>0&&nx<=m&&ny>0&&ny<=n){
                                    dp[i][j][k]+=dp[i-1][nx][ny];
                                    dp[i][j][k]%=mod;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        for(int i=0;i<=m+1;i++){
            for(int j=0;j<=n+1;j++){
                if(i==0||j==0||i==m+1||j==n+1){
                    if(i==0&&j==0)
                        continue;
                    if(i==m+1&&j==n+1)
                        continue;
                     if(i==m+1&&j==0)
                        continue;
                     if(i==0&&j==n+1)
                        continue;
                    for(int k=0;k<=maxMove;k++)
                        ans+=dp[k][i][j];
                    ans%=mod;
                }
            }
        }
        
        return (int)ans;
    
    }
};
