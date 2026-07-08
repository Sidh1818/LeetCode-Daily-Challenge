class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left=0,right=0;
        int len = INT_MIN,n=fruits.size();
        unordered_map<int,int>freq;

        while(right<n){
            freq[fruits[right]]++;

            while(freq.size()>2){
                freq[fruits[left]]--;
                if(freq[fruits[left]]==0)
                    freq.erase(fruits[left]);
                left++;
            }
            len = max(len,right-left+1);
            right++;
        }
        return len;
    }
};