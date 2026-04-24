class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>freq;
        for(int i=0;i<words.size();i++){
            freq[words[i]]++;
        }

        vector<string>ans;
        for(auto it:freq)
            ans.push_back(it.first);
        sort(ans.begin(),ans.end(),[&](const string &a,const string &b){
            if(freq[a]==freq[b])
                return a<b;
            return freq[a]>freq[b];
        });

        ans.resize(k);
        return ans;
    }
};