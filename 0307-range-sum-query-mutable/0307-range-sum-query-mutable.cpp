class NumArray {
public:
    int n;
    vector<int>segmentTree;

    void BuildSegTree(int i,int l,int r,vector<int>&arr){
        if(l==r){
            segmentTree[i] = arr[l];
            return ;
        }
        int mid = l+(r-l)/2;
        BuildSegTree(2*i+1,l,mid,arr);
        BuildSegTree(2*i+2,mid+1,r,arr);

        segmentTree[i] = segmentTree[2*i+1]+segmentTree[2*i+2];
    }

    void updateseg(int idx,int val,int i,int l,int r){
        if(l==r){
            segmentTree[i] = val;
            return;
        }

        int mid = l+(r-l)/2;
        if(idx<=mid){
            updateseg(idx,val,2*i+1,l,mid);
        }
        else{
            updateseg(idx,val,2*i+2,mid+1,r);
        }

        segmentTree[i]=segmentTree[2*i+1]+segmentTree[2*i+2];
    }

    int querySum(int strt,int end,int i,int l,int r){
        if(l>end || r<strt)
            return 0;
        if(l>=strt && r<=end){
            return segmentTree[i];
        }

        int mid = l+(r-l)/2;
        return querySum(strt,end,2*i+1,l,mid)+querySum(strt,end,2*i+2,mid+1,r);
    }


    NumArray(vector<int>& nums) {
        n = nums.size();
        segmentTree.resize(4*n);

        BuildSegTree(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        updateseg(index,val,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return querySum(left,right,0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */