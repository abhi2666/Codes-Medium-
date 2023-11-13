class Solution
{
public:    
    int lowerBound(int a[], int n){
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(a[mid] == 1){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
    int transitionPoint(int arr[], int n) {
        return lowerBound(arr, n);
    }
};
