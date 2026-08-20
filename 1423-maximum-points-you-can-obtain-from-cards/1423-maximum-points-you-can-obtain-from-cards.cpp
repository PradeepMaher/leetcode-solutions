class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l = k-1, r = n-1;
        int maxPoint = 0,lsum=0,rsum=0;

        for(int i = 0; i<k; i++){
            lsum += cardPoints[i];
            maxPoint += cardPoints[i];
        }

        for(int i = k-1; i>=0; i--){
            lsum = lsum -cardPoints[i];
            rsum = rsum + cardPoints[r];
            r--;
            maxPoint = max(maxPoint, lsum + rsum);
        }

        return maxPoint;
    }
};