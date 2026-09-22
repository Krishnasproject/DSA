class Solution {
public:
    string longestPalindrome(string s) {
        int n  = s.size();

        string ans = s.substr(0,1);
        string cur_ans = "";
        for(int i =0;i<n;i++){
            int left = i-1;
            int right = i+1;

            while(left>=0 && right < n){
                if(s[left] == s[right]){
                    cur_ans = s.substr(left,right-left+1);
                    left--;
                    right++;
                    if (cur_ans.length() > ans.length())
                        ans = cur_ans;
                }
                else
                    break;
            }
            left = i;
            right = i+1;

            while(left>=0 && right<n && s[left] == s[right]){
                cur_ans = s.substr(left,right-left+1);
                left--;
                right++;
                if (cur_ans.length() > ans.length())
                    ans = cur_ans;
            }
        }
        return ans;
    }
};