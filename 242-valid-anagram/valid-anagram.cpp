class Solution {
public:
    bool isAnagram(string s, string t) {
       if(s.length()!=t.length())
            return false;

        unordered_map<char,int>sp;
        unordered_map<char,int>tp;

        for(int i =0;i<s.length();i++){
            sp[s[i]]++;
        }
        for(int i=0;i<s.length();i++){
            tp[t[i]]++;
        }

        return sp == tp;
    }
};