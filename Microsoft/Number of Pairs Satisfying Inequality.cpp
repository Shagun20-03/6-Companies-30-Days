class Solution {
    public:
    long long int cnt;
    
    void checkCount(vector<int>&nums, int start, int mid, int end, int diff) {
        int l=start, r=mid+1;
        while(l<=mid && r<=end) {
            if(nums[l]<=(nums[r]+diff)) {
                cnt+=(end-r+1);
                l++;
            }
            else {
                r++;
            }
        }
        sort(nums.begin()+start, nums.begin()+end+1);
        return;
    }
    void mergeSort(vector<int>&nums, int start, int end, int diff) {
        if(start==end)
            return;
        int mid=(start+end)/2;
        mergeSort(nums, start, mid, diff);
        mergeSort(nums, mid+1, end, diff);
        checkCount(nums, start, mid, end, diff);
        return;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n=nums1.size();
        
        vector<int> c(n);
        for(int i=0;i<n;i++) {
            c[i]=nums1[i]-nums2[i];
        }
        mergeSort(c, 0, n-1, diff);
        return cnt;
    }
};
