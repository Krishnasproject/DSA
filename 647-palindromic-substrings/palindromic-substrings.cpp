class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        
        int cnt = 0;

        for(int i = 0 ;i<n;i++){
            cnt++;
            int left = i-1;
            int right = i+1;
            while(left>=0 && right <n){
                if(s[left] == s[right])
                    {    cnt++;
                        left--;
                        right++;
                    }
                else
                    break;
            }

            left = i;
            right = i+1;

            while(left>=0 && right <n){
                if(s[left] == s[right])
                    {
                        cnt++;
                        left--;
                        right++;
                    }
                else
                    break;
            }
        }
        
        return cnt;
    }
};