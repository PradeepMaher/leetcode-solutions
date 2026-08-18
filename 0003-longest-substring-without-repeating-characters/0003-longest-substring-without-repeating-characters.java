class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n=s.length();
        int[] hash=new int[256];
        Arrays.fill(hash,-1);

        int left=0;
        int maxLen=0;

        for(int right=0;right<n;right++){
            char ch=s.charAt(right);
            if(hash[ch]!=-1 && hash[ch]>= left){
                left=hash[ch]+1;
            } 
            hash[ch]=right;
            maxLen=Math.max(maxLen,right-left+1);
        }
        return maxLen;
    }
}