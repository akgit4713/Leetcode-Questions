int dp[11][2][2],s,nn;
string num;


class Solution {
public:
    int count(int id,bool ti,int tt,vector<string>&d,string rr){
        if(id==s){
            int c=0;
            for(int i=0;i<rr.size();i++)
                c*=10,c+=rr[i]-'0';
            return c<=nn;
        }
        if(dp[id][ti][tt]!=-1)
            return dp[id][ti][tt];
        int ret=0;
        int lim=ti?num[id]-'0':9;
        for(auto x:d){
            int i=x[0]-'0';
            if(i>lim)
                continue;
            int nt=ti&(i==lim);
            int ntt=nt|(i>0);
            ret+=count(id+1,nt,ntt,d,rr+char(i+'0'));
        }
        return dp[id][ti][tt]=ret;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        nn=n;
        memset(dp,-1,sizeof dp);
        num=to_string(n);
        s=num.length();
        bool z=false;
        for(int i=0;i<digits.size();i++)
            z|=digits[i][0]=='0';
        if(z)
        return count(0,0,0,digits,"");
        else{
            int ans=0;
            for(int i=0;i<s;i++)
                ans+=count(i,i==0,0,digits,"");
            return ans;
        }
    }


};
