class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int MOD = 1e9+7;
        unordered_map<int,int>mp;
        long long ans=0;
        vector<long long>poo(22);
        poo[0]=1;
        for(int i=1;i<=21;i++){
            poo[i] = poo[i-1]*2;
        }
        for(int i=0;i<deliciousness.size();i++){
            for(int j=0;j<=21;j++){
                int target = poo[j] - deliciousness[i];
                if(mp.find(target)!=mp.end()){
                    ans= (ans+mp[target]) % MOD;
                }
            }
            mp[deliciousness[i]]++;
        }
        return ans;
    }
};