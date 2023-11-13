class Solution{
public:
	
	int findMaximum(int a[], int n) {
	    /// question similar to finding the peak element 
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(a[mid] > a[mid-1] && a[mid] > a[mid + 1]) return a[mid];
            else if(a[mid] > a[mid-1]) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
	}
};