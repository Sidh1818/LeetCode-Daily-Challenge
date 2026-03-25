class NumArray {
public:
    int n;
    vector<int>segtree;

    void buildSeg(int i,int l,int r,vector<int>& nums){
        if(l==r){
            segtree[i] = nums[l];
            return;
        }
        int mid = l+(r-l)/2;
        buildSeg(2*i+1,l,mid,nums);
        buildSeg(2*i+2,mid+1,r,nums);

        segtree[i] = segtree[2*i+1]+segtree[2*i+2];
    }

    int querysum(int strt,int end,int i,int l,int r){
        if(l>end || r<strt)
            return 0;
        if(l>=strt && r<=end){
            return segtree[i];
        }
        int mid = l+(r-l)/2;
        return querysum(strt,end,2*i+1,l,mid)+querysum(strt,end,2*i+2,mid+1,r);
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segtree.resize(4*n);
        buildSeg(0,0,n-1,nums);

    }
    
    int sumRange(int left, int right) {
        return querysum(left,right,0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);


 class NumArray {
public:
    int n;
    vector<int>tree;

    int merge(int a,int b){
        return a+b;
    }

    void build(vector<int>nums,int start,int end,int node){
        if(start==end){
            tree[node]=nums[start];
            return;
        }

        int mid=(start+end)/2;
        build(nums,start,mid,node*2);
        build(nums,mid+1,end,2*node+1);
        tree[node] = merge(tree[node*2],tree[2*node+1]);
    }

    int query(int start,int end,int node,int left,int right){
        if(start>right || end<left){
            return 0;
        }
        if(left<=start && right>=end)
            return tree[node];

        int mid=(start+end)/2;
        int left_sum = query(start,mid,2*node,left,min(mid,right));
        int right_sum = query(mid+1,end,2*node+1,max(left,mid),right);
        return right_sum+left_sum;
    }

    NumArray(vector<int>& nums) {
        n=nums.size();
        tree.resize(4*n+1,0);
        build(nums,0,n-1,1);
    }
    
    int sumRange(int left, int right) {
        return query(0,n-1,1,left,right);
    }
};

/*
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
 