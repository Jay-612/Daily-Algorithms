//Minimum path sum of triangle from top to bottom
//Using Dynamic-programming and space optimization

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

//Define the vector to store the value of next row
        vector<int>front(n,0);
//Define the vector to store the value of next row
        vector<int>curr(n,0);

        for(int i = n - 1;i >= 0;i--)
            front[i] = triangle[n - 1][i];

        for(int i = n - 2;i >= 0;i--)
        {
            for(int j = i;j >= 0;j--)
            {
                int p1 = triangle[i][j] + front[j + 1];
                int p2 = triangle[i][j] + front[j];

                curr[j] = min(p1,p2);
            }
            front = curr;
        }

        return front[0];
    }
};
