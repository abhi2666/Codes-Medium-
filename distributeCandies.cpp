#include<bits/stdc++.h>
using namespace std;

int candy(vector<int> &A) {
    vector<int>ans(A.size(), 1); // each will have atleast one candy
    sort(A.begin(), A.end());
    for(int i = 1; i < A.size(); i++){
        if(A[i] > A[i-1]){
            ans[i] = ans[i-1]+1;
        }
    }

    int sum = 0;
    for(auto it : ans) sum += it;
    return sum;
}

int main(){
    vector<int>a {1, 5, 2, 1};
    cout<<candy(a)<<endl;
    return 0;
}