/**
 * 1401. 圆和矩形是否有重叠
 */

class Solution {
    public boolean checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        
        if(x_center >= x1 && x_center <= x2 && y_center >= y1 && y_center <= y2){
            return true;
        }

        int distance = 0, x_d = 0, y_d = 0;

        if(y_center < y1 || y_center > y2){
            y_d = Math.min(Math.abs(y1 - y_center), Math.abs(y2 - y_center));
        }

        distance = Math.min((x1 - x_center) * (x1 - x_center) + y_d * y_d, 
                            (x2 - x_center) * (x2 - x_center) + y_d * y_d);

        if(distance <= radius * radius)
            return true;
        if(x_center < x1 || x_center > x2){
            x_d = Math.min(Math.abs(x1 - x_center), Math.abs(x2 - x_center));
        }
        distance = Math.min((y1 - y_center) * (y1 - y_center) + x_d * x_d, 
                            (y2 - y_center) * (y2 - y_center) + x_d * x_d);

        if(distance <= radius * radius)
            return true;
            
        return false;

    }
}

/**
 * 704. 二分查找
 */

class Solution {
    public int search(int[] nums, int target) {
        
        int l = 0;
        int r = nums.length - 1;

        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] > target){
                r = mid - 1;
            }else if(nums[mid] < target){
                l = mid + 1;
            }else{
                return mid;
            }
        }

        return -1;

    }

}

/**
 * 189. 旋转数组
 */
class Solution {
    public void rotate(int[] nums, int k) {

        int[] a = new int[nums.length];

        for (int i = 0; i < nums.length; i++) {
            a[(i + k) % nums.length] = nums[i];
        }
        
        for (int i = 0; i < nums.length; i++) {
            nums[i] = a[i];
        }
    }

}