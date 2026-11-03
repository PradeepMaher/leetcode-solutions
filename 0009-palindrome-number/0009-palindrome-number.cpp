class Solution {
    bool solve(int i, int j, string s) {

        if(i >= j) return true;

        if(s[i] != s[j]) return false;

        return solve(i + 1, j - 1, s);
    }
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int i = 0;
        int n = s.size();

        return solve(i,n-1,s);
    }
};