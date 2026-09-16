//DP with space optimization
//Count Subsets with Sum
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        
        vector<int>prev(target + 1,0);

        //Base condition
        if(arr[0] == 0)
            prev[0] = 2;
        else 
        {
            prev[0] = 1;
            if(arr[0] <= target)
                prev[arr[0]] = 1;
        }

      //Further process
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
};
