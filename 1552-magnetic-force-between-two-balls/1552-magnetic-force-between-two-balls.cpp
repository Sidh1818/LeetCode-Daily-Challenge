class Solution {
public:
    bool canPlace(vector<int>& position, int m,int dist){
        int n=position.size();
        int last = position[0];
        int cnt=1;
        for(int i=1;i<position.size();i++){
            if(position[i]-last>=dist){
                last = position[i];
                cnt++;

                if(cnt>=m)
                    return true;
            }
        }
        return false;
    }


    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int low=1,high=position[n-1]-position[0];
        int ans=0;

        while(low<=high){
            int mid = low+(high-low)/2;
            if(canPlace(position,m,mid)){
                ans=mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};