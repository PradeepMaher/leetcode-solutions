class Solution {
public:
    int reverseDegree(string s) {
        int pro =0, n= s.size();

        for(int i=0; i<n; i++){
            int ch = 'z' - s[i] + 1;;
            pro += (1+i) * ch;
        }

        return pro;
    }
};