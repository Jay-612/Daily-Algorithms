//DP with space optimization
//Partitions with Given Difference

class Solution {
  public:

    //previous problem

    int perfectSum(vector<int>& arr,int target) {
            // code here
            int n = arr.size();

            vector<int>prev(target + 1,0);

            if(arr[0] == 0)
                prev[0] = 2;
            else 
            {
                prev[0] = 1;
                if(arr[0] <= target)
                    prev[arr[0]] = 1;
            }

            for(int i = 1;i < n;i++)
            {
                vector<int>temp(target + 1,0);
                for(int j = 0;j <= target;j++)
                {
                    int nopick = prev[j];
                    int pick = 0;
                    if(arr[i] <= j)
                        pick = prev[j - arr[i]];

                    temp[j] = pick + nopick;
                }
                prev = temp;
            }

            return prev[target];
        }
  
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n = arr.size();
        int sum = 0;
        for(int i = 0;i < n;i++)sum += arr[i];

        //s1 - s2 = diff
        //s2 = (sum - diff) / 2

        int target = (sum - diff) / 2;

        //Edge cases 
        if((sum - diff) < 0 || (sum - diff) % 2)
            return 0;
            
        return perfectSum(arr,target);
    }
};
