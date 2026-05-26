class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long m=mass;
        sort(asteroids.begin(),asteroids.end());
        for(int a:asteroids){
            if(a>m)
                return false;
            else
                m+=a;
        }
        return true;
    }
};