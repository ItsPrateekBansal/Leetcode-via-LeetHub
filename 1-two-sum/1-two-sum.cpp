class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> track;
        vector<int> ans(2,0);
        for(int i = 0 ; i < numbers.size() ; i++) {
            int a = numbers[i] ; 
            int b = target - a ;
            if (track.count(b) > 0) {
                ans[0] = track[b];
                ans[1] = i;
                break;
            } else {
                track[a] = i;
            }
        }
        return ans;
    }
};