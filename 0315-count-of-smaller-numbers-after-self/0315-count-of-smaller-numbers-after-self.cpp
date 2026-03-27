class Solution {
public:
    int n;
    vector<int>segtree;


    void update(int idx,int val,int i,int l,int r){
        if(l==r){
            segtree[i] += val;
            return;
        }

        int mid = l+(r-l)/2;
        if(idx<=mid)
            update(idx,val,2*i+1,l,mid);
        else
            update(idx,val,2*i+2,mid+1,r);

        segtree[i] = segtree[2*i+1]+segtree[2*i+2];
    }

    int query(int strt,int end,int i,int l,int r){
        if(l>end || r<strt)
            return 0;
        if(l>=strt && r<=end)
            return segtree[i];

        int mid = l+(r-l)/2;

        return query(strt,end,2*i+1,l,mid)+
                query(strt,end,2*i+2,mid+1,r);
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<int>sorted = nums;
        sort(sorted.begin(),sorted.end());
        sorted.erase(unique(sorted.begin(),sorted.end()),sorted.end());
        int n = sorted.size();

        segtree.assign(4*n,0);

        vector<int>ans(nums.size());

        for(int i=nums.size()-1;i>=0;i--){
            int idx = lower_bound(sorted.begin(),sorted.end(),nums[i]) - sorted.begin();

            if(idx>0){
                ans[i] = query(0,idx-1,0,0,n-1);
            }
            else{
                ans[i] = 0;
            }

            update(idx,1,0,0,n-1);
        }
        return ans;

        /*
        long long n=nums.size();
        vector<int>res;
        for(long long i=0;i<n-1;i++){
            long long cnt=0;
            for(long long j=i+1;j<n;j++){
                if(nums[j]<nums[i])
                    cnt++;
            }
            res.push_back(cnt);
        }
        res.push_back(0);
        return res;
        */
    }
};