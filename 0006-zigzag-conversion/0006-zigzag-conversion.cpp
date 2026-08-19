class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) return s;

        vector<string> ans(numRows, "");
        int i = 0;
        int len = s.length();

        while (i < len) {
            
            for (int indx = 0; indx < numRows && i < len; indx++) {
                ans[indx] += s[i++];
            }
            for (int indx = numRows - 2; indx > 0 && i < len; indx--) {
                ans[indx] += s[i++];
            }
        }

        string res = "";
        for (string str : ans) {
            res += str;
        }

        return res;
    }
};
