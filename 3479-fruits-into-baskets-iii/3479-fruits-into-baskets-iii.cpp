class Solution {
public:
    void buildST(int i,int l,int r,vector<int>& baskets,vector<int>&segtree){
        if(l==r){
            segtree[i] = baskets[l];
            return;
        }
        int mid = l+(r-l)/2;
        buildST(2*i+1,l,mid,baskets,segtree);
        buildST(2*i+2,mid+1,r,baskets,segtree);

        segtree[i] = max(segtree[2*i+1],segtree[2*i+2]);
    }

    bool query(int i,int l,int r,vector<int>&segtree,int fruit){
        if(segtree[i]<fruit)
            return false;
        if(l==r){
            segtree[i] = -1;
            return true;
        }

        int mid = l+(r-l)/2;
        bool placed = false;

        if(segtree[2*i+1]>=fruit)
            placed = query(2*i+1,l,mid,segtree,fruit);
        else
            placed = query(2*i+2,mid+1,r,segtree,fruit);

        segtree[i] = max(segtree[2*i+1],segtree[2*i+2]);

        return placed;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=baskets.size();
        vector<int>segtree(4*n,-1);
        
        buildST(0,0,n-1,baskets,segtree);
        int unplaced=0;

        for(int f:fruits){
            if(query(0,0,n-1,segtree,f)==false)
                unplaced++;
        }
        return unplaced;
    }
};