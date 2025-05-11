class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char,int> freq;
        for(auto it:s){
            freq[it]++;
        }
        vector<int> cnt;
        for(auto it:freq){
            cnt.push_back(it.second);
        }
        sort(cnt.begin(),cnt.end());
        long long dele=0;
        if(k>=cnt.size()) return 0;
        for(int i=0;i<cnt.size()-k;i++){
            dele+=cnt[i];
        }
        return dele;
    }
};