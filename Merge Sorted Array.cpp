class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector < int > aux(nums1.begin(), nums1.end());
        int p0 = 0, p1 = 0;
        while (p0 < m && p1 < n){
            if(aux[p0] < nums2[p1]){
                nums1[p0+p1] = aux[p0];
                p0++;
            }
            else {
                nums1[p0+p1] = nums2[p1];
                p1++;
            }
        }
        while (p0 < m){
            nums1[p0+p1] = aux[p0];
            p0++;
        }
        while (p1 < n){
            nums1[p0+p1] = nums2[p1];
            p1++;
        }
    }
};
