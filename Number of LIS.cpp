class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
         ios_base::sync_with_stdio(0), cin.tie(0);
       int n=nums.size();
        vector<int>v(n+1,1),cnt(n+1,0);
        int len=1;
        int ans=0;
        cnt[0]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])
                v[i]=max(v[i],v[j]+1);
                len=max(len,v[i]);
            }
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]&&v[j]==v[i]-1){
                    cnt[i]+=cnt[j];
                }
            }
            if(v[i]==1)
                cnt[i]++;
        }
        for(int i=0;i<n;i++){
            if(v[i]==len)
                ans+=cnt[i];
        }
        return ans;
    }
};
