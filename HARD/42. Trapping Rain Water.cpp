#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;

        vector<int> left(n);
        vector<int> right(n);
        int water = 0;

        left = height;
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], height[i]);
        }

        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i]);
        }

        for (int i = 1; i < n - 1; i++) {
            int var = min(left[i - 1], right[i + 1]);
            if (var > height[i]) {
                water += var - height[i];
            }
        }

        return water;
    }
};

int main() {
    Solution solver;
    
    // Example test case: [0,1,0,2,1,0,1,3,2,1,2,1]
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    
    int result = solver.trap(height);
    
    cout << "Total trapped rainwater: " << result << endl;
    
    return 0;
}
/*
Time Complexity (TC): \(\mathcal{O}(N)\)Space Complexity (SC): \(\mathcal{O}(N)\)
*/