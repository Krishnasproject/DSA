class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        int low = 0;
        int high = 0;
        int k = 0;
        int res = 0;
        unordered_map<int,int>mp;
        for(high = 0;high <n;high++){
            mp[fruits[high]]++;
             k = high - low + 1;

             while(mp.size()>2){
                mp[fruits[low]]--;
                if(mp[fruits[low]] == 0)
                    mp.erase(fruits[low]);

                low++;
             }

             if(mp.size() == 2 || mp.size()<2){
                int len = high - low + 1;
                res = max(res,len);
             }
        }
        return res;
    }
};