class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        int low = 0;
        int max_freq = 0;
        int ans = 0;

        unordered_map<char,int>mp;

        for(int high =0;high<n;high++){
            mp[answerKey[high]]++;

            max_freq = max(max_freq,mp[answerKey[high]]);

            while((high-low+1)-max_freq >k){
                mp[answerKey[low]]--;
                low++;
            }
            ans = max(ans,high-low+1);
        }
        return ans;
    }
};