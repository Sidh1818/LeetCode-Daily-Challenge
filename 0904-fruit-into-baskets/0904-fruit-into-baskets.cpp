class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int i=0,j=0,res=0;
        unordered_map<int,int>freq;
        while(j<n){
            freq[fruits[j]]++;
            if(freq.size()<=2){
                res=max(res,j-i+1);
            }
            else{
                freq[fruits[i]]--;
                if(freq[fruits[i]]==0)
                    freq.erase(fruits[i]);
                i++;
            }
            j++;
        }
        return res;
    }
};