class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        int totalTime = 0;
        
        for(int i = 0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }

        priority_queue<int>pq;
        for(auto it : mp){
            pq.push(it.second);
        }
        while(!pq.empty()){
        int cycleTasks=0;
        vector<int>temp;
            while(cycleTasks<n+1 && !pq.empty()){
                int task = pq.top();
                pq.pop();
                task--;
                if(task>0)
                    temp.push_back(task);
                cycleTasks++;
            }
            for(int freq : temp)
                pq.push(freq);

            if (!pq.empty()) {
                totalTime += n + 1;
            } else {
                totalTime += cycleTasks;
            }     
        }
        return totalTime;
    }
};