//Partition equal subset sum
//Dynamic programming with space optimization
class Solution {
public:
    //Function for subset with given target
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        
        vector<bool>prev(sum + 1,false);
        vector<bool>curr(sum + 1,false);
        
        prev[0] = curr[0] = true;
        
        if(arr[0] <= sum)
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

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;

        for(int i = 0;i < n;i++)
            sum += nums[i];

        //If the sum is false then the partition will absolutely have unequal sums.
        if(sum % 2)return false;
        
        sum/=2;

        //If the subset is having sum = sum/2 then the remaining sum will definitely be sum/2
        return isSubsetSum(nums,sum);
    }
};
