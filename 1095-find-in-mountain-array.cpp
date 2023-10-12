/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l = 0, r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) 
                l = mid + 1;
    
            else r = mid - 1;
        }

        int peak = l;
        l = 0, r = peak;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int middle = mountainArr.get(mid);
            
            if (middle == target) return mid;
            else if (middle < target) l = mid + 1;
            else r = mid - 1;
        }

        l = peak + 1;
        r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int middle = mountainArr.get(mid);

            if (middle == target) return mid;
            else if (middle < target) r = mid - 1;
            else l = mid + 1;
        }

        return -1;
    }
};