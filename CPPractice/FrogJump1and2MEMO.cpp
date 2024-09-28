#include <iostream>
#include <vector>
using namespace std;

int solve(int ind, vector<int>& height, vector<int>& dp)
{
    if (ind == 0) return 0;

    if(dp[ind]!=-1) return dp[ind];

    int jump2 = INT_MAX;
    int jump1 = solve(ind-1,height,dp) + abs(height[ind]-height[ind-1]);

    if(ind > 1) int jump2 = solve(ind-2,height,dp) + abs(height[ind]-height[ind-2]);

    return dp[ind] = min(jump1,jump2);
}
int main()
{
    vector<int> heights {10,20,30,10};
    int n = heights.size();

    vector<int> dp(n,-1);
    cout << solve(n-1,heights,dp);

}