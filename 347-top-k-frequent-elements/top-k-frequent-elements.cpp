class Solution {
public:
    
    struct cmp{
        bool operator()(pair<int,int>&a,pair<int,int>&b){
            if(a.first != b.first)
                return a.first>b.first;//min heap behaviour 

            return a.second>b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;

        for(int num : nums)
            mp[num]++;


        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;

        for(auto i : mp){
            pq.push({i.second,i.first});
            
            if(pq.size()>k)
                pq.pop();
        }

        vector<int>ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};