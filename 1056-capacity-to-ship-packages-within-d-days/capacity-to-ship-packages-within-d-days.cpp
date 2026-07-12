class Solution {
public:

    bool func(vector<int>& weights,int n ,int limit,int days){
        int day = 1;
        int package = 0;

        for(int i = 0;i<n;i++){
            if(package+weights[i]<=limit){
                package+=weights[i];
                }
            else{
                day++;
                package = weights[i];

                if(day>days)
                    return false;
            }

        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        if(n<days)
            return -1;
        int low = 0,high=0;

        for(int i =0;i<n;i++){
            low = max(low,weights[i]);
            high += weights[i];
        }
        int res = -1;
        while(low<=high){
            int guess = low +(high - low)/2;

            if(func(weights,n,guess,days)){
                res = guess;
                high = guess - 1;

            }
            else{
                low = guess + 1;
            }
        }
        return res;
    }
};