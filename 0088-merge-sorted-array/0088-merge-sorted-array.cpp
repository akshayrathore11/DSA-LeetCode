class Solution {
public:
    void merge(vector<int>& mergedArray, int countNums1, vector<int>& nums2, int countNums2) {
         int indexNums1 = countNums1 - 1;                  
    int indexNums2 = countNums2 - 1;                  
    int mergeIndex = countNums1 + countNums2 - 1;     

   
    while (indexNums1 >= 0 && indexNums2 >= 0) {
        if (mergedArray[indexNums1] > nums2[indexNums2]) {
            mergedArray[mergeIndex] = mergedArray[indexNums1];
            indexNums1--;
        } else {
            mergedArray[mergeIndex] = nums2[indexNums2];
            indexNums2--;
        }
        mergeIndex--;
    }

   
    while (indexNums2 >= 0) {
        mergedArray[mergeIndex] = nums2[indexNums2];
        indexNums2--;
        mergeIndex--;
    }

    }
};