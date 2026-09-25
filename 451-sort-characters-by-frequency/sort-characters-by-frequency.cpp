class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();

        unordered_map<char,int>mp;
        for(char ch : s){
            mp[ch]++;
        }

        priority_queue<pair<int,char>>pq;//max_heap;

        for(auto it:mp){
            pq.push({it.second,it.first});
        }
    string ans = "";
        while(!pq.empty()){
            pair<int,char> c = pq.top();
            pq.pop();

            for(int i =0;i<c.first;i++){
                ans +=c.second;
            }
        }
    return ans;
    }
};