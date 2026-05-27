class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>small(26,-1);
        vector<int>last(26,-1);
        //unordered_map<int,int>small;
        //unordered_map<int,int>large;
        int i=0;
        
        for(int i=0;i<word.size();i++){
            if(word[i]>='a' && word[i]<='z'){
                small[word[i]-'a'] = i;
            }
            else{
                if(last[word[i]-'A']==-1)
                    last[word[i]-'A'] = i;
            }
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(small[i]!=-1 && last[i]!=-1){
                if(small[i]<last[i])
                    ans++;
            }
        }
        return ans;
    }
};