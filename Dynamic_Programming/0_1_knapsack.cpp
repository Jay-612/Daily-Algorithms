//0/1 knapsack using memoisation

class Solution {
  public:
    int solve(int index,int w,vector<int> &val, vector<int> &wt,vector<vector<int>> &dp)
    {
        //Base condition
        if(index == 0)
        {
            if(wt[0] <= w) return val[0];
            else return 0;
        }

        //Memoise
        if(dp[index][w] != -1)
            return dp[index][w];

        //Not take condition
        int notake = solve(index - 1,w,val,wt,dp);

        //Take condition
        int take = INT_MIN;
        if(wt[index] <= w)
            take = val[index] + solve(index - 1,w - wt[index],val,wt,dp);
            
        return dp[index][w] = max(notake,take);
    }
  
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();

        //Dp array
        vector<vector<int>>dp(n,vector<int>(W + 1,-1));
        
        return solve(n - 1,W,val,wt,dp);
    }
};







//Using Tablulation
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>>dp(n,vector<int>(W + 1,0));

      //Base condition
        for(int i = wt[0];i <= W;i++)
            dp[0][i] = val[0];
            
        for(int i = 1;i < n;i++)
        {
            for(int j = 0;j <= W;j++)
            {
                int notake = dp[i - 1][j];
                int take = INT_MIN;
                if(wt[i] <= j)
                    take = val[i] + dp[i - 1][j - wt[i]];
                    
                dp[i][j] = max(take,notake);
            }
        }
        
        return dp[n - 1][W];
    }
};


//Space Optimization
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();

      //Only using one array
        vector<int>prev(W + 1);

      //Base condition
        for(int i = wt[0];i <= W;i++)
            prev[i] = val[0];
            
        for(int i = 1;i < n;i++)
        {
            for(int j = W;j >= 0 ;j--)
            {
                int notake = prev[j];
                int take = INT_MIN;
                if(wt[i] <= j)
                    take = val[i] + prev[j - wt[i]];
                    
                prev[j] = max(take,notake);
            }
        }
        
        return prev[W];
    }
};
