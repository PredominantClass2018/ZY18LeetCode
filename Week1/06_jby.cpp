#include<stdio.h>
#include<iostream>
using namespace std;

bool threeConsecutiveOdds(int* arr, int arrSize){
    int  i;
	for (i = 0; i <= arrSize - 3; i++)
		if ((arr[i] % 2 != 0) && (arr[i+1] % 2 != 0) && (arr[i+2] % 2 != 0))
			return true;


	return false;


}

int sumOddLengthSubarrays(int* arr, int arrSize){
int i,j,k;
   int sum=0;
   for(i=1;i<=arrSize;i=i+2)   
      for(j=0;i+j<=arrSize;j++)  
         for(k=0;k<=i-1;k++)   
         sum+=arr[j+k];
   return sum;
}

int min(int a,int b)
{
	if(a<b) return a;
	return b;
}
int minimumTotal(int** triangle, int triangleSize,int* triangleColSize){
   int sum[triangleSize][triangleSize];
   int n;
   int i,j;
   for(int i=0;i<triangleSize;++i)
         sum[triangleSize-1][i]=triangle[triangleSize-1][i]; 
   for(int i=triangleSize-2;i>=0;--i)
       for(int j=0;j<=i;j++)
            sum[i][j]=min(sum[i+1][j],sum[i+1][j+1])+triangle[i][j]; 
	return sum[0][0];
}

