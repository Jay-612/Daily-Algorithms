//Coin change using memoisation

//Time complexity - O(n * sum)
//Space complexity - O(n * sum) + O(n)

class Solution {
	public:
	int solve(int index, int sum, vector<int> &coins, vector<vector<int>> &dp)
	{
    //Base condition
		if (index == 0)
			{
			if (sum % coins[0] == 0)return sum/coins[0];
      else //For negative values and not possible conditions
				return 1e9;
		}
		
		if (dp[index][sum] != -1)
			return dp[index][sum];
		
		int notake = solve(index - 1, sum, coins, dp);
		int take = 1e9;
		if (coins[index] <= sum)
			take = 1 + solve(index, sum - coins[index], coins, dp);//index will not be reduced as we have infinite supply of coins
		
		return dp[index][sum] = min(take, notake);
	}
	
	int minCoins(vector<int> &coins, int sum) {
		// code here
		int n = coins.size();
		vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
		
		int res = solve(n - 1, sum, coins, dp);
		
		return res < 1e9 ? res : -1;//For invalid condition it will return -1
	}
};






//Using Tablulation and space optimosation
class Solution {
	public:

	int minCoins(vector<int> &coins, int sum) {
		// code here
		int n = coins.size();
		
		vector<int>prev(sum + 1,1e9);
		vector<int>curr(sum + 1,1e9);
		
		for(int i = 0;i <= sum;i++)
		{
		    if(i % coins[0] == 0)
		        prev[i] = i/coins[0];
		}
		
		for(int i = 1;i < n;i++)
		{
		    for(int j = 0;j <= sum;j++)
		    {
		        int notake = prev[j];
		        int take = 1e9;
		        if (coins[i] <= j)
			        take = 1 + curr[j - coins[i]];
			        
			    curr[j] = min(take,notake);
		    }
		    prev = curr;
		}
		
		int res = prev[sum];
		
		return res < 1e9 ? res : -1;
	}
};
