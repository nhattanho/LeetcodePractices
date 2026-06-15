class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int lengthMedian = (size1+size2)/2;//version1
        int previousMedian= 0, medianValue = 0;//version1
        int point1 = 0, point2 = 0; //version1
        //we just need to sort by comparing a = lengthMedian+1 times to get first a elements that           
        //are in order
        for(int i = 0; i <= lengthMedian; i++) {
            previousMedian = medianValue;
            if(point1 < size1 && point2 < size2){
                if(nums1[point1] < nums2[point2]){
                    medianValue = nums1[point1];
                    point1++;
                }else{
                    medianValue = nums2[point2];
                    point2++;
                }
            }else{
                if(point1 >= size1) medianValue = nums2[point2++];
                else if (point2 >= size2)
                    medianValue = nums1[point1++];
            }
        }
        return (size1+size2) % 2 == 0 ? (medianValue + previousMedian) / 2.0 : medianValue;  
    }
};
