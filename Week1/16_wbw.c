//int sumOddLengthSubarrays(int* arr, int arrSize) 第一题 
//{
//    int i, j, sum = 0;
//    int length = 1;
//
//    while(length <= arrSize)
//    {
//        for(i = 0; i < arrSize - length + 1; i++)
//        {
//            for(j = i; j < i + length; j++)
//            {
//                sum += arr[j];
//            }
//        }
//        length += 2;
//    }
//
//    return sum;
//}
//bool threeConsecutiveOdds(int* arr, int arrSize){ 第二题 
//    int cnt = 0;
//    for (int i = 0; i < arrSize; i++) {
//        if (arr[i] & 1) {
//            cnt++;
//        } else {
//            cnt = 0;
//        }
//
//        if (cnt == 3) return true;
//    }
//
//    return false;
//}
//int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){第三题 
//    for(int i=triangleSize-2;i>=0;--i){
//        for(int j=0;j<=i;++j){
//            triangle[i][j]=fmin(triangle[i+1][j],triangle[i+1][j+1])+triangle[i][j];
//        }
//    }
//    return triangle[0][0];
//}


