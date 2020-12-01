/****************
binary-search
****************/

/*********  version 1  memory consumption 7M    *********/  
/*int search(int* nums, int numsSize, int target){
    for(int i=0;i<numsSize;++i)
        if(nums[i]==target)
            return i;
    
    return -1;
}
*/

/*********  version 2  memory consumption 6.9M    *********/  
/*int search(int* nums, int numsSize, int target){
    int left=0;
    int right=numsSize-1;
    int mid=(left+right)/2;
    
    for(int i=0;;++i){
        if(nums[mid]==target)   return mid;
        if(nums[mid]<target){
            left=mid+1;
        }
        if(nums[mid]>target){
            right=mid-1;
        }
        mid=(left+right)/2;
        if(right<left)  return -1;
    }
} */

/*********  version 3  memory consumption 7.2M    *********/  
/*int search(int* nums, int numsSize, int target){
    int mid,left=0,right=numsSize-1;
    while(left<=right){
        mid=left+(right-left)/2;
        if(nums[mid]==target)   return mid;
        if(target<nums[mid])    right=mid-1;
        else left=mid+1;
    }
    return -1;
}*/


/****************
circle-and-rectangle-overlapping
****************/
/*矩形区域内点离圆心最近的点距离小于圆的半径*/

/*bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2){
    int dx = x1 > x_center ? x1 - x_center : x2 < x_center ? x_center - x2 : 0;
    int dy = y1 > y_center ? y1 - y_center : y2 < y_center ? y_center - y2 : 0;
    return dx * dx + dy * dy <= radius * radius;
}*/



/****************
rotate-array
****************/

/*********  version 1 暴力算法 时间复杂度O(n*k)    *********/  
/*void rotate(int* nums, int numsSize, int k){
    int t;
    for (int i = 0; i < k; ++i) {
        t = nums[numsSize - 1];
        for (int j = numsSize - 2; j >= 0; j--)
            nums[j + 1] = nums[j];
        nums[0] = t;
    }
}*/

/*********  version 2 额外的数组 时间复杂度O(n)    *********/  
//用一个额外的数组来将每个元素放到正确的位置上，原本数组里下标为 i的把它放到 (i+k)\%数组长度(i+k)%数组长度 的位置。然后把新的数组拷贝到原数组中
/*void rotate(int* nums, int numsSize, int k){
    int* array;
    array=(int *)malloc(numsSize*sizeof(int));
    for(int i =0;i<numsSize;++i)
        array[(i+k)%numsSize]=nums[i];
    for(int i =0;i<numsSize;++i)
        nums[i]=array[i];
}*/

/*********  version 3 环状替换 时间复杂度O(n)    *********/  
//假设，数组里我们有 n 个元素并且 k 是要求移动n/k的次数。
//更进一步，假设 n%k=0 。第一轮中，所有移动数字的下标 i 满足 i%k==0 。这是因为每跳 k 步，只会到达相距为 k 个位置下标的数。
//每一轮，移动 n/k个元素。下一轮中，移动满足 i%k==1 的位置的数。这样的轮次会一直持续到再次遇到 i%k==0 的地方为止，此时 i=k 。
//此时在正确位置上的数字共有 k× n/k =n 个。因此所有数字都在正确位置上。
/*void rotate(int* nums, int numsSize, int k){
    k=k%numsSize;
    int count=0;
    for(int start=0;count<numsSize;start++){
        int current=start;
        int prev=nums[start];
        do{
            int next=(current+k)%numsSize;
            int temp=nums[next];
            nums[next]=prev;
            prev=temp;
            current=next;
            count++;
        }while(start!=current);
    }
}*/


/*********  version 4 使用反转 时间复杂度O(n)    *********/ 
//基于事实：当旋转数组 k 次，k%n 个尾部元素会被移动到头部，剩下的元素会被向后移动。
//建议C++ JAVA
