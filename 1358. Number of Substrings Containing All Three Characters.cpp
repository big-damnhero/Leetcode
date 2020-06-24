//https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int i=0, j = 0;
        int cnt[3]={0};
        int ans=0;
        while(i<n)
        {
            cnt[s[i]-'a']++;
            if(cnt[0] and cnt[1] and cnt[2])
            {
                while(cnt[s[j]-'a']>1)
                {
                    cnt[s[j]-'a']--;
                    j++;
                }
                ans+=j+1;
            }
            i++;
            
            
        }
        
        
        return ans;
    }
};
