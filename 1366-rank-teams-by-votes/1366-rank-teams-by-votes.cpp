class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int teams = votes[0].size();
        vector<vector<int>>count(26,vector<int>(teams,0));
        for(const string& v:votes){
            for(int i=0;i<teams;i++){
                count[v[i]-'A'][i]++;
            }
        }

        string res = votes[0];

        sort(res.begin(),res.end(),[&](char a,char b){
            for(int i=0;i<teams;i++){
                if(count[a-'A'][i] != count[b-'A'][i]){
                    return count[a-'A'][i] > count[b-'A'][i];
                }
            }
            return a<b;
        });
        return res;
    }
};