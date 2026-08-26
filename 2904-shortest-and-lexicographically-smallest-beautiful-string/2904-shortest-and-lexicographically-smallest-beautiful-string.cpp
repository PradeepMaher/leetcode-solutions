class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int l = 0;
        int count1 = 0;
        int minlen = INT_MAX;
        string ans = "";

        for (int r = 0; r < n; r++) {

            if (s[r] == '1')
                count1++;

            // More than k ones
            while (count1 > k) {
                if (s[l] == '1')
                    count1--;
                l++;
            }

            // Exactly k ones
            if (count1 == k) {

                // Remove leading zeroes
                while (s[l] == '0')
                    l++;

                string curr = s.substr(l, r - l + 1);

                if (curr.length() < minlen ||
                    (curr.length() == minlen && curr < ans)) {

                    minlen = curr.length();
                    ans = curr;
                }
            }
        }

        return ans;
    }
};