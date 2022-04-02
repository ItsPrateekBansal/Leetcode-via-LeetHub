class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right) {
            if(s[left] == s[right]) {
                left += 1;
                right -= 1;
                continue;
            }
            break;
        }
        if(left >= right) return true;
        int li = left;
        int ri = right - 1;
        
        while(li < ri) {
            if(s[li]==s[ri]) {
                li += 1;
                ri -= 1;
                continue;
            }
            break;
        }
        if(li >= ri) return true;
        
        li = left + 1;
        ri = right;
        
        while(li < ri) {
            if(s[li]==s[ri]) {
                li += 1;
                ri -= 1;
                continue;
            }
            break;
        }
        if(li >= ri) return true;
        
        return false;
    }
};