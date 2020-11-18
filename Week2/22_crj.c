class Solution 
{
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        int count =  0;
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.insert(flowerbed.end(),0);
        for(int i = 1; i < flowerbed.size()-1; i++)
        {
            if(flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0)
            {
                flowerbed[i] = 1;
                count++;
            }
        }
        return n <= count;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
int getWinner(int* arr, int arrSize, int k){  //超出时间限制
    int count=0;
    int i;
    int t;
    while(count!=k)
    {
        if( arr[0] > arr[1] )
        {
            t=arr[1];
            for( i=2 ; i < arrSize ; i++ )
            {
                arr[i-1] = arr[i];
            }
            arr[arrSize-1] = t;
            count++;
        }
        else
        {
            t = arr[0];
            arr[0] = arr[1];
    
            count=1;
            for(i=2 ; i < arrSize ; i++)
            {
                arr[i-1] = arr[i];
            }
            arr[arrSize-1] = t;
        }
              
    
    }
    return *arr;
}


int getWinner(int* arr, int arrSize, int k) //ok
{
    int i, win_count = 0;

    for(i = 0; i < arrSize - 1 && win_count < k; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            arr[i + 1] = arr[i];
            win_count++;
        }
        else
            win_count = 1;
    }
   
    return arr[i];
}
////////////////////////////////////////////////////////////////////
