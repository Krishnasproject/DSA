class Solution {
public:
    struct cmp {
        bool operator()(const pair<int,int>&a,const pair<int,int>&b){
            int da = a.first*a.first + a.second*a.second;
            int db = b.first*b.first + b.second*b.second;

            return da<db;//max heap;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;

        for(auto it : points){
            pq.push({it[0],it[1]});

            if(pq.size()>k)
                pq.pop();
        }

        vector<vector<int>>ans;

        while(!pq.empty()){
            ans.push_back({pq.top().first,pq.top().second});
            pq.pop();
        }
        return ans;
    }
};