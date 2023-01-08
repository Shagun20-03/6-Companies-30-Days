class Solution {
public:
    int trailingZeroes(int n) {
        int count=0;
        //keep dividing n by higher power of 5 until its value is >= 1
        for(int i=5; n/i>=1; i=i*5){
            count+=n/i;
        }
        return count;
    }
};
