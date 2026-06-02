class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landDuration.size();
        int m = waterStartTime.size();
        int minFinish=INT_MAX;
        for(int i=0;i<n;i++){
            int landFinish = landStartTime[i] + landDuration[i];
            for(int j=0;j<m;j++){
                int waterstrt = max(landFinish,waterStartTime[j]);
                int currFinish = waterstrt+waterDuration[j];
                minFinish = min(minFinish,currFinish);
            }
        }
        for(int i=0;i<m;i++){
            int waterFinish = waterStartTime[i] + waterDuration[i];
            for(int j=0;j<n;j++){
                int landstrt = max(waterFinish,landStartTime[j]);
                int currFinish = landstrt+landDuration[j];
                minFinish = min(minFinish,currFinish);
            }
        }
        return minFinish;
        /*
        vector<pair<int,int>>temp;
        for(int i=0;i<landStartTime.size();i++){
            temp.push_back({landStartTime[i],landDuration[i]});
        }

        for(int i=0;i<waterStartTime.size();i++){
            temp.push_back({waterStartTime[i],waterDuration[i]});
        }

        sort(temp.begin(),temp.end());

        int ans=0;
        if(temp[0].first>0)
            ans+=temp[0].first;
        for(int i=0;i<temp.size()-1;i++){
            ans+=temp[i].second;
            if(temp[i+1].first<temp[i].first)
                ans+=temp[i+1].first - temp[i].second;
        }
        return ans;
        */
    }
};