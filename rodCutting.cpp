/*
you have the array ->
2 5 7 8 10
and your task is to divide a rod in pieces from 1 to N(size) where 
each value of piece represent value from array (1-based indexing)..
you have to maximise the result by optimisingly cutting the rod..

Approach --> using DP
1. start from f(idx, N) where N = 5 in our case 
// we can cut the rod only if idx+1  <= N(remaining length of the rod)
*/

int solve(int idx, int remainingLength, vector<int>&price, vector<vector<int>>&dp){
    // base case --> when idx will reach 0
    // then at that point you will have only 0+1 = 1 size in which
    // you can cut your remaining length into
    if(idx == 0){
        return remainingLength * price[idx];
    }

    if(dp[idx][remainingLength] != -1) return dp[idx][remainingLength];
    // can either cut the rod or can leave it 
    int notCut = 0 + solve(idx-1, remainingLength, price, dp);
    int cut = INT_MIN;
    if(idx+1 <= remainingLength){
        // we will keep the index in the same place because we 
        // may have to cut the same length of piece again in the
        // future.
        cut = price[idx] + solve(idx, remainingLength-(idx+1), price, dp);
    }

    return dp[idx][remainingLength] = max(cut, notCut);
}

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>>dp(n, vector<int>(n+1, -1));
	return solve(n-1, n, price, dp);
}
