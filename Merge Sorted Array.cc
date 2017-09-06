class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tail = m + n - 1;
        --m, --n;
        for (int i = tail; i >= 0; --i) {
            if (m < 0) {
                nums1[i] = nums2[n--]; 
            } else if (n < 0) { 
                nums1[i] = nums1[m--];
            } else if (nums1[m] > nums2[n]) {
                nums1[i] = nums1[m--];
            } else {
                nums1[i] = nums2[n--];
            }
        }
    }
};