class Solution {
public:
    int binarySearch2(int left,int right, int target,MountainArray mountainArr){
        while(left <= right){
            int mid = (left + right) / 2;
            int midValue = mountainArr.get(mid);
            if (midValue == target) return mid;
            if (midValue > target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
    int binarySearch1(int left,int right, int target,MountainArray mountainArr){
        while (left <= right) {
            int mid = (left + right) / 2;
            int midValue = mountainArr.get(mid);

            if (midValue == target) return mid;
            if (midValue > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length();
        int left = 0, right = len - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int peakEle = left;
        int ans1 = binarySearch1(0,peakEle,target,mountainArr);
        if(ans1 != -1)return ans1;
        int ans2 = binarySearch2(peakEle,len-1,target,mountainArr);
        return ans2;
    }
};