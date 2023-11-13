int solve(int idx, int prevIdx, vector<vector<int>>&points, vector<vector<int>>&dp){
    if(idx < 0){
        return 0;
    }

    // you have to pick an activity out of all activities and that activity should be something 
    // that you haven't picked consecutive previously.
    if(dp[idx][prevIdx] != -1) return dp[idx][prevIdx];
    int maxi = 0;
    for(int i = 0; i < 3; i++){
        if(i != prevIdx){
            // this is the task that we can pick for now
            int res = points[idx][i] + solve(idx-1, i, points, dp);
            maxi = max(maxi, res);
        }
    }
    return dp[idx][prevIdx] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n, vector<int>(3, -1));
    return solve(n-1, -1, points, dp);
}