class Solution {
    public static int min(int a, int b) {
        if(a < b) return a;
        return b;
    }
    public int minFlips(String s) {
        StringBuilder ss = new StringBuilder(s+s);
        // System.out.println(ss);
        StringBuilder s1 = new StringBuilder("");
        StringBuilder s2 = new StringBuilder("");
        for(int i = 0 ; i < ss.length() ; i++) {
            if(i % 2 == 0) {
                s1.append('0');
                s2.append('1');
            } else {
                s1.append('1');
                s2.append('0');
            }
        }
        // System.out.println(s2);
        //SlidingWindow 
        int si = 0, ei = s.length()-1, left = 0, right = 0;
        // System.out.println(ei);
        for(int i = 0 ; i <= ei ; i++) {
            if(ss.charAt(i) != s1.charAt(i)) left++;
            if(ss.charAt(i) != s2.charAt(i)) right++;
        }
        ei++;
        int ans = Integer.MAX_VALUE;
        ans = min(left, right);
        while(ei < ss.length()) {
            if(ss.charAt(ei - s.length()) != s1.charAt(ei - s.length())) left--;
            if(ss.charAt(ei - s.length()) != s2.charAt(ei - s.length())) right--;
            
            if(ss.charAt(ei) != s1.charAt(ei)) left++;
            if(ss.charAt(ei) != s2.charAt(ei)) right++;
            ans = min(ans, left);
            ans = min(ans, right);
            
            ei++;
            
        }
        return ans;
    }
}