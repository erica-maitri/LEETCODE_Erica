#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    void reverse(vector<int>& arr, int low, int high) {
        while (low < high) {
            swap(arr[high], arr[low]);
            low++;
            high--;
        }
    }

public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Handle edge case for empty array
        if (n == 0) return; 

        // Reduce k to stay within bounds [0, n-1]
        k = k % n; 

        // If k becomes 0, no rotation is needed
        if (k == 0) return; 

        // Step 1: Reverse the last k elements
        reverse(nums, n - k, n - 1);

        // Step 2: Reverse the first n - k elements
        reverse(nums, 0, n - k - 1);

        // Step 3: Reverse the entire array
        reverse(nums, 0, n - 1);
    }
};
