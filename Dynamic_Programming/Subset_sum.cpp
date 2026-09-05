//Subset sum equal to target
//Dynamic programming with space optimization
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();

      //Declaring vector for prev and curr elements
        vector<bool>prev(sum + 1,false);
        vector<bool>curr(sum + 1,false);

      //Base condition
        prev[0] = curr[0] = true;
        prev[arr[0]] = true;
        
        for(int index = 1;index < n;index++)
        {
            for(int target = 1;target <= sum;target++)
            {
                bool notake = prev[target];
                bool take = false;
        
                if(arr[index] <= target)
                    take = prev[target - arr[index]];
            
                curr[target] = (take || notake);
            }
            prev = curr;
        }        
        return prev[sum];
    }
};
