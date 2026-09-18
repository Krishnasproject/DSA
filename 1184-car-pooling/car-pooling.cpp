class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int diff[1001] = {0};

        for(int i = 0 ; i<trips.size();i++){
            int passengers = trips[i][0];
            int start = trips[i][1];
            int end = trips[i][2];

            diff[start] += passengers;
            diff[end] -= passengers;

        }
        int curr_passengers = 0;

        for(int i = 0;i<1000;i++){
            curr_passengers += diff[i];

            if(curr_passengers > capacity)
                return false;

        }
        return true;
    }
};