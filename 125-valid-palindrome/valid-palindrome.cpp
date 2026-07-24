class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0 ,j = s.length()-1;
        int n = s.length();

        for(int i =0;i<n;i++){
            s[i] = tolower(s[i]);
        }
        while(i<j){


            if(!isalnum(s[i]))
                i++;
            else if(!isalnum(s[j]))
                j--;
            else
            {
               { 
                if(s[i]!=s[j])
                    return false;
                    }
                
            i++;
            j--;

            }

        }
        return true;
    }
};