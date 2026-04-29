class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int beauty = 0;
        int n = nums.size();
        vector<int>large(n);
        vector<int>small(n);

        int l = nums[0];
        large[0]=l;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>l){
                l = nums[i];
            }
            large[i]=l;
        }

        int s = nums[n-1];
        small[n-1] = s;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<s)
                s = nums[i];
            small[i] = s;
        }

        for(int i=1;i<n-1;i++){
            if(large[i-1]<nums[i] && small[i+1]>nums[i])
                beauty+=2;
            else if(nums[i-1]<nums[i] && nums[i]<nums[i+1])
                beauty+=1;
        }
        return beauty;
        /*

        for(int i=1;i<=nums.size()-2;i++){

            /*
            //int j=0;
            int x=i;
            int k=i;
            bool flag1,flag2;
            for(int s=0;s<x;s++){
                flag1 = true;
                if(nums[s]>nums[s+1]){
                    flag1 = false;
                    break;
                }
            }
            if(flag1==true){
                for(int s=k;s<nums.size();s++){
                    flag2=true;
                    if(nums[s]>nums[s+1]){
                        flag2 = false;
                        break;
                    }
                }
            }
            if(flag1==true && flag2==true){
                beauty+=2;
                //continue;
            }
            
            else{
                if()
                    beauty+=1;
            }
        }
        return beauty;
        */
    }
};